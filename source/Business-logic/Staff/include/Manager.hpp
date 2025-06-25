//
// Created by hid3h on 23.06.2025.
//

#ifndef STAFFDEMO_REFACTOR_MANAGER_HPP
#define STAFFDEMO_REFACTOR_MANAGER_HPP
#include "IEngineer.hpp"

namespace staff {

    class ProjectManager : public ManagerIEngineer {
    public:
        ProjectManager(std::string id_, std::string name_, std::string position_, float partOfBudget_, unsigned int proAdditions_, unsigned int heading_, std::vector<std::shared_ptr<Project>> projects_);
        ~ProjectManager() override;

        bool addProject(std::shared_ptr<Project> newProject) override;
        bool removeProject(std::shared_ptr<Project> remProject) override;
        bool removeAllProject() override;

    };

    class SeniorManager : public ManagerIEngineer {
    public:
        SeniorManager(std::string id_, std::string name_, std::string position_, float partOfBudget_, unsigned int proAdditions_, unsigned int heading_, std::vector<std::shared_ptr<Project>> projects_);
        ~SeniorManager() override;

        bool addProject(std::shared_ptr<Project> newProject) override;
        bool removeProject(std::shared_ptr<Project> remProject) override;
        bool removeAllProject() override;
    };
} // staff

#endif //STAFFDEMO_REFACTOR_MANAGER_HPP
