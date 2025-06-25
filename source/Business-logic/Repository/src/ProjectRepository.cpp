//
// Created by hid3h on 23.06.2025.
//

#include "ProjectRepository.hpp"
#include <algorithm>
#include <utility>

namespace repository {

    bool ProjectRepository::addProject(std::shared_ptr<staff::Project> &project) {
        if (!project) return false;
        if (project_map.contains(project->getProjectName())) return false;
        project_map[project->getProjectName()] = std::move(project);
        return true;
    }

    bool ProjectRepository::removeProject(const std::shared_ptr<staff::Project> &project) {
        if (!project) return false;
        auto findIt = std::find_if(project_map.begin(), project_map.end(), [&](const std::pair<std::string, std::shared_ptr<staff::Project>> line){
            return project.get() == line.second.get();
        });
        if (findIt == project_map.end()) return false;
        auto members = project->getAllMemebers();
        std::for_each(members.begin(), members.end(), [&](const std::weak_ptr<staff::IEngineer>& member){
            if (auto memberShared = member.lock()) project->removeMember(memberShared);
        });
        project_map.erase(findIt);
        return true;
    }

    std::map<std::string, std::weak_ptr<staff::Project>> ProjectRepository::getAllProject() const {
        std::map<std::string, std::weak_ptr<staff::Project>> temp;
        for (const auto& line: project_map) temp.insert(line);
        return temp;
    }

    std::vector<std::weak_ptr<staff::IEngineer>> ProjectRepository::getProjectStaff(const std::shared_ptr<staff::Project> &project) const {
        if (!project) return {};
        return project->getAllMemebers();
    }

    bool ProjectRepository::addStaff(std::shared_ptr<staff::IEngineer> staff, std::shared_ptr<staff::Project>& project) {
        if (!project) return false;
        return project->addMember(std::move(staff));
    }

    bool
    ProjectRepository::removeStaff(std::shared_ptr<staff::IEngineer> staff, std::shared_ptr<staff::Project>& project) {
        if (!project) return false;
        return project->removeMember(std::move(staff));
    }

    bool ProjectRepository::relocateStaff(std::shared_ptr<staff::IEngineer> staff, std::shared_ptr<staff::Project>& fromProject, std::shared_ptr<staff::Project>& toProject) {
        if (!staff || !fromProject || !toProject) return false;
        if (!fromProject->removeMember(staff)) return false;
        return toProject->addMember(std::move(staff));
    }

} // repository