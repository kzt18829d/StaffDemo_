#include "../include/StaffRepository.hpp"
#include "IEngineer.hpp"
#include <algorithm>

namespace repository {

    bool StaffRepository::addStaff(std::shared_ptr<staff::IEmployee> staff) {
        if (!staff) return false;
        if (staff_map.contains(staff->getID())) return false;
        staff_map[staff->getID()] = std::move(staff);
        return true;
    }

    bool StaffRepository::removeStaff(std::shared_ptr<staff::IEmployee> staff) {
        if (!staff) return false;
        if (auto findIt = std::find_if(staff_map.begin(), staff_map.end(), [&](std::pair<const std::string, std::shared_ptr<staff::IEmployee>>& current){
            return current.second.get() == staff.get() && current.first == staff->getID();
        }); findIt != staff_map.end()) {
            if (auto engineer = std::dynamic_pointer_cast<staff::IEngineer>(staff)) engineer->removeAllProject();
            staff_map.erase(findIt);
            return true;
        }
        return false;
    }

    bool StaffRepository::clearRepository() {
        std::for_each(staff_map.begin(), staff_map.end(), [&](const std::pair<const std::string, std::shared_ptr<staff::IEmployee>>& line) {
            if (auto engineer = std::dynamic_pointer_cast<staff::IEngineer>(line.second)) engineer->removeAllProject();
        });
        staff_map.clear();
        return true;
    }

    std::map<std::string, std::weak_ptr<staff::IEmployee>> StaffRepository::getAllStaff() const {
        std::map<std::string, std::weak_ptr<staff::IEmployee>> temp;
        for (const auto& line: staff_map) temp[line.first] = line.second;
        return temp;
    }

    std::map<std::string, std::weak_ptr<staff::IEmployee>> StaffRepository::getStaffByName(const std::string &onSearch) const {
        std::map<std::string, std::weak_ptr<staff::IEmployee>> temp;
        std::for_each(staff_map.begin(), staff_map.end(), [&](const std::pair<const std::string, std::shared_ptr<staff::IEmployee>>& line){
            if (auto find = line.second->getName().find(onSearch); find != std::string::npos) temp[line.first] = line.second;
        });
        return temp;
    }

    std::map<std::string, std::weak_ptr<staff::IEmployee>>
    StaffRepository::getStaffByPosition(const std::string &posToSearch) const {
        std::map<std::string, std::weak_ptr<staff::IEmployee>> temp;
        std::for_each(staff_map.begin(), staff_map.end(), [&](const std::pair<const std::string, std::shared_ptr<staff::IEmployee>>& line){
            if (line.second->getPosition() == posToSearch) temp[line.first] = line.second;
        });
        return temp;
    }

    std::map<std::string, std::weak_ptr<staff::IEmployee>> StaffRepository::getStaffByPaymentBig(unsigned int payment) const {
        std::map<std::string, std::weak_ptr<staff::IEmployee>> temp;
        std::for_each(staff_map.begin(), staff_map.end(), [&](const std::pair<const std::string, std::shared_ptr<staff::IEmployee>>& line){
            if (line.second->getPayment() > payment) temp[line.first] = line.second;
        });
        return temp;
    }

    std::map<std::string, std::weak_ptr<staff::IEmployee>>
    StaffRepository::getStaffByPaymentSmall(unsigned int payment) const {
        std::map<std::string, std::weak_ptr<staff::IEmployee>> temp;
        std::for_each(staff_map.begin(), staff_map.end(), [&](const std::pair<const std::string, std::shared_ptr<staff::IEmployee>>& line){
            if (line.second->getPayment() < payment) temp[line.first] = line.second;
        });
        return temp;
    }

} // repository