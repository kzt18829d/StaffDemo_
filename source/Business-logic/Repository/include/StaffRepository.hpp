#ifndef STAFFDEMO_REFACTOR_STAFFREPOSITORY_HPP
#define STAFFDEMO_REFACTOR_STAFFREPOSITORY_HPP
//#include "IEmployee.hpp"
#include "../../Staff/include/IEmployee.hpp"
#include <memory>
#include <map>

namespace repository {

    class StaffRepository {
    private:
        std::map<std::string, std::shared_ptr<staff::IEmployee>> staff_map;

    public:
        bool addStaff(std::shared_ptr<staff::IEmployee> staff);
        bool removeStaff(std::shared_ptr<staff::IEmployee> staff);
        bool clearRepository();

        std::map<std::string, std::weak_ptr<staff::IEmployee>> getAllStaff() const;
        std::map<std::string, std::weak_ptr<staff::IEmployee>> getStaffByName(const std::string& onSearch) const;
        std::map<std::string, std::weak_ptr<staff::IEmployee>> getStaffByPosition(const std::string& posToSearch) const;

        std::map<std::string, std::weak_ptr<staff::IEmployee>> getStaffByPaymentBig(unsigned payment) const;
        std::map<std::string, std::weak_ptr<staff::IEmployee>> getStaffByPaymentSmall(unsigned payment) const;

    };

} // repository

#endif //STAFFDEMO_REFACTOR_STAFFREPOSITORY_HPP
