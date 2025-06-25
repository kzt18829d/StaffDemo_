#ifndef STAFFDEMO_REFACTOR_PROJECTREPOSITORY_HPP
#define STAFFDEMO_REFACTOR_PROJECTREPOSITORY_HPP
#include <map>
#include <memory>
#include <string>
#include "../../Staff/include/Project.hpp"

namespace repository {

    class ProjectRepository {
    private:
        std::map<std::string, std::shared_ptr<staff::Project>> project_map;

    public:
        bool addProject(std::shared_ptr<staff::Project>& project);
        bool removeProject(const std::shared_ptr<staff::Project>& project);

        std::map<std::string, std::weak_ptr<staff::Project>> getAllProject() const;
        std::vector<std::weak_ptr<staff::IEngineer>> getProjectStaff(const std::shared_ptr<staff::Project>& project) const;

        bool addStaff(std::shared_ptr<staff::IEngineer> staff, std::shared_ptr<staff::Project>& project);
        bool removeStaff(std::shared_ptr<staff::IEngineer> staff, std::shared_ptr<staff::Project>& project);
        bool relocateStaff(std::shared_ptr<staff::IEngineer> staff, std::shared_ptr<staff::Project>& fromProject, std::shared_ptr<staff::Project>& toProject);

    };

} // repository

#endif //STAFFDEMO_REFACTOR_PROJECTREPOSITORY_HPP
