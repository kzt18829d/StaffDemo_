//
// Created by hid3h on 25.06.2025.
//

#include "RepositoryInstruments.hpp"
#include "Personal.hpp"
#include "Engineer.hpp"
#include "Manager.hpp"
#include "Spliter.hpp"

namespace repository {
    RepositoryInstruments::RepositoryInstruments() {
        staffRepository = std::make_unique<repository::StaffRepository>();
        projectRepository = std::make_unique<repository::ProjectRepository>();
    }

    bool RepositoryInstruments::loadStaffFromQueue(std::queue<staff::TempEmplyee>& tempQueue) {
        if (tempQueue.empty()) return false;

        utils::Spliter spliter;
        do {
            staff::TempEmplyee temp = tempQueue.front();
            int salary = 0;

            try {
                salary = std::stoi(temp.salary);
            } catch (...) { salary = 0; }
            tempQueue.pop();

            if (temp.position == "cleaner") {
                std::shared_ptr<staff::Cleaner> cleaner = std::make_shared<staff::Cleaner>(std::move(temp.id),
                    std::move(temp.name), std::move(temp.position), salary);
                staffRepository->addStaff(cleaner);
            }
            else if (temp.position == "driver") {
                auto driver = std::make_shared<staff::Driver>(std::move(temp.id),
                    std::move(temp.name), std::move(temp.position), salary, 0);
                staffRepository->addStaff(driver);
            }
            else {

                if (temp.position == "smanager") {
                    auto projects_s = spliter.splitFileLine(temp.project, ',');
                    std::vector<std::shared_ptr<staff::Project>> projects_p;
                    if (!projects_s.empty()) {
                        for (auto& name: projects_s) {
                            auto project = std::make_shared<staff::Project>(std::move(name));
                            projects_p.push_back(project);
                        }
                    }

                    std::shared_ptr<staff::SeniorManager> manager = std::make_shared<staff::SeniorManager>(std::move(temp.id),
                           std::move(temp.name), std::move(temp.position), 0, 0, 0, std::vector<std::shared_ptr<staff::Project>> {});
                    auto ptr = std::dynamic_pointer_cast<staff::IEngineer>(manager);

                    for (auto& proj: projects_p) {
                        proj->addMember(ptr);
                        projectRepository->addProject(proj);
                    }
                    staffRepository->addStaff(ptr);
                    continue;
                }

                auto project = std::make_shared<staff::Project>(temp.project);
                std::shared_ptr<staff::IEngineer> ptr;

                if (temp.position == "programmer") {
                    auto programmer = std::make_shared<staff::Programmer>(std::move(temp.id),
                          std::move(temp.name), std::move(temp.position), 0, 0, salary, nullptr);
                    ptr = std::dynamic_pointer_cast<staff::IEngineer>(programmer);
                }
                else if (temp.position == "tester") {
                    auto tester = std::make_shared<staff::Tester>(std::move(temp.id),
                          std::move(temp.name), std::move(temp.position), 0, 0, salary, nullptr);
                    ptr = std::dynamic_pointer_cast<staff::IEngineer>(tester);
                }
                else if (temp.position == "teamleader") {
                    auto team = std::make_shared<staff::TeamLeader>(std::move(temp.id),
                          std::move(temp.name), std::move(temp.position), 0, 0, salary, 0, nullptr);
                    ptr = std::dynamic_pointer_cast<staff::IEngineer>(team);
                }
                else if (temp.position == "pmanager") {
                    auto manager = std::make_shared<staff::ProjectManager>(std::move(temp.id),
                          std::move(temp.name), std::move(temp.position), 0, 0, 0, std::vector<std::shared_ptr<staff::Project>>{});
                    ptr = std::dynamic_pointer_cast<staff::IEngineer>(manager);
                }

                project->addMember(ptr);
                projectRepository->addProject(project);
                staffRepository->addStaff(ptr);

            }
        } while (!tempQueue.empty());
        return true;
    }

    bool RepositoryInstruments::loadProjectsFromQueue(std::queue<staff::Project>) {
        return false; // труп, нет времени
    }

    std::vector<std::shared_ptr<staff::IEmployee>> RepositoryInstruments::downloadStaffs() const {
        std::vector<std::shared_ptr<staff::IEmployee>> staffs;
        auto map = staffRepository->getAllStaff();
        for (auto& line: map) {
            staffs.push_back(line.second.lock());
        }
        return staffs;
    }
} // repository