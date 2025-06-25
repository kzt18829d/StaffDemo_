
#ifndef STAFFDEMO_REFACTOR_REPOSITORYINSTRUMENTS_HPP
#define STAFFDEMO_REFACTOR_REPOSITORYINSTRUMENTS_HPP
#include <memory>
#include <queue>
#include "StaffRepository.hpp"
#include "ProjectRepository.hpp"
#include "TempEmplyee.hpp"
#include "TempProject.hpp"



namespace repository {

    class RepositoryInstruments {
    public:
        RepositoryInstruments();

        std::unique_ptr<repository::StaffRepository> staffRepository;
        std::unique_ptr<repository::ProjectRepository> projectRepository;

        bool loadStaffFromQueue(std::queue<staff::TempEmplyee>& tempQueue);
        bool loadProjectsFromQueue(std::queue<staff::Project>);

        std::vector<std::shared_ptr<staff::IEmployee>> downloadStaffs() const;

    };

} // repository

#endif //STAFFDEMO_REFACTOR_REPOSITORYINSTRUMENTS_HPP
