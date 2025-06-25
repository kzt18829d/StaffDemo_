#ifndef STAFFDEMO_REFACTOR_STAFFSTORAGEPROVIDER_HPP
#define STAFFDEMO_REFACTOR_STAFFSTORAGEPROVIDER_HPP
#include <filesystem>
#include <memory>
#include <queue>
#include <TempEmplyee.hpp>
#include <TempProject.hpp>
#include <IEmployee.hpp>

namespace fileManager {

    class StaffStorageProvider {
    private:
        std::filesystem::path loadPath;
        std::queue<staff::TempEmplyee> employeeQueue;
        std::queue<staff::TempProject> projectQueue;

        void addEmployee(staff::TempEmplyee&& tempEmployee);
        void addProject(staff::TempProject&& tempProject);

    public:
        bool loadFromFile(const std::filesystem::path& path);
        bool saveToFile(const std::filesystem::path& path, const std::vector<std::shared_ptr<staff::IEmployee>>& staffs);

        const std::queue<staff::TempEmplyee>& getEmployeeQueue() const;
        const std::queue<staff::TempProject>& getProjectQueue() const;

    };

} // fileManager

#endif //STAFFDEMO_REFACTOR_STAFFSTORAGEPROVIDER_HPP
