//
// Created by hid3h on 23.06.2025.
//

#include "Manager.hpp"

#include <utility>

namespace staff {
    ProjectManager::ProjectManager(std::string id_, std::string name_, std::string position_, float partOfBudget_,
                                   unsigned int proAdditions_, unsigned int heading_,
                                   std::vector<std::shared_ptr<Project>> projects_) :
                                   ManagerIEngineer(std::move(id_), std::move(name_),
                                                                                                       std::move(position_),
                                                                                                       partOfBudget_,
                                                                                                       proAdditions_,
                                                                                                       heading_,
                                                                                                       std::move(projects_)) {

    }

    bool ProjectManager::addProject(std::shared_ptr<Project> newProject) {
        if (!newProject) return false;
        if (!projects.empty() && !projects[0].expired() && projects[0].lock().get() == newProject.get()) return false;
        projects.clear();
        projects.push_back(newProject);
        return true;
    }

    bool ProjectManager::removeProject(std::shared_ptr<Project> remProject) {
        if (!remProject || projects.empty()) return false;
        if (auto project = projects[0].lock(); project && project.get() == remProject.get()) {
            projects.clear();
            return true;
        }
        return false;
    }

    bool ProjectManager::removeAllProject() {
        projects.clear();
        return true;
    }

    ProjectManager::~ProjectManager() = default;


    SeniorManager::SeniorManager(std::string id_, std::string name_, std::string position_, float partOfBudget_,
                                 unsigned int proAdditions_, unsigned int heading_,
                                 std::vector<std::shared_ptr<Project>> projects_) : ManagerIEngineer(std::move(id_), std::move(name_),
                                                                                                     std::move(position_),
                                                                                                     partOfBudget_,
                                                                                                     proAdditions_,
                                                                                                     heading_,
                                                                                                     std::move(projects_)) {

    }

    SeniorManager::~SeniorManager() = default;

    bool SeniorManager::addProject(std::shared_ptr<Project> newProject) {
        if (!newProject) return false;
        if (auto findIt = std::find_if(projects.begin(), projects.end(), [&](const std::weak_ptr<Project>& current){
            return current.lock().get() == newProject.get(); }); findIt == projects.end()) {
            projects.push_back(newProject);
            return true;
        }
        return false;
    }

    bool SeniorManager::removeProject(std::shared_ptr<Project> remProject) {
        if (auto findIt = std::find_if(projects.begin(), projects.end(), [&](const std::weak_ptr<Project>& current){
            return !current.expired() && current.lock().get() == remProject.get(); }); findIt != projects.end()) {
            projects.erase(findIt);
            return true;
        }
        return false;
    }

    bool SeniorManager::removeAllProject() {
        projects.clear();
        return true;
    }

} // staff