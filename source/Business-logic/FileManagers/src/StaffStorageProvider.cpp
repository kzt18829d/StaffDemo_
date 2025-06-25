#include "../include/StaffStorageProvider.hpp"
#include <fstream>
#include "../include/Spliter.hpp"
#include "IPersonal.hpp"
#include "IEngineer.hpp"

namespace fileManager {
    void StaffStorageProvider::addEmployee(staff::TempEmplyee&& tempEmployee) {
        employeeQueue.push(std::move(tempEmployee));
    }

    void StaffStorageProvider::addProject(staff::TempProject&& tempProject) {
        projectQueue.push(std::move(tempProject));
    }

    bool StaffStorageProvider::loadFromFile(const std::filesystem::path &path) {
        std::ifstream file(path);
        if (!file.is_open()) return false;
        utils::Spliter Spl;
        std::string line;
        std::getline(file, line);

        while (std::getline(file, line)) {
            std::vector<std::string> fields = Spl.splitFileLine(line);
            if (fields.size() != 5) continue;
            // field[4] разделяется при создании указателя IEmployee/IEngineer
            auto tempEmployee = staff::TempEmplyee(std::move(fields[0]), std::move(fields[1]), std::move(fields[2]), std::move(fields[3]), fields[4]);
            if (fields[4].find(',')) {
                auto projects = Spl.splitFileLine(fields[4], ',');
                for (auto& name: projects) {
                    auto tempProject = staff::TempProject(std::move(name));
                    addProject(std::move(tempProject));
                }
            } else {
                auto tempProject = staff::TempProject(std::move(fields[4]));
                addProject(std::move(tempProject));
            }
        }
        file.close();
        return true;
    }

    const std::queue<staff::TempEmplyee>& StaffStorageProvider::getEmployeeQueue() const {
        return employeeQueue;
    }

    const std::queue<staff::TempProject>& StaffStorageProvider::getProjectQueue() const {
        return projectQueue;
    }

    bool StaffStorageProvider::saveToFile(const std::filesystem::path &path,
                                          const std::vector<std::shared_ptr<staff::IEmployee>> &staffs) {
        std::ofstream file(path, std::ios_base::out | std::ios_base::trunc);
        if (!file.is_open()) return false;
        char delim = ';';
        char subDelim = ',';

        file << "id;name;position;salary;project\n";
        for (const auto& IEmployee: staffs) {
            if (!IEmployee) continue;
            file << IEmployee->makeLineForFile(delim, subDelim) << '\n';
        }
        return true;
    }
} // fileManager