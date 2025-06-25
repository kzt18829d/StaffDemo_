//
// Created by hid3h on 23.06.2025.
//

#include "../include/IEmployee.hpp"

namespace staff {
    IEmployee::IEmployee(std::string id_, std::string name_, std::string position_) : id{std::move(id_)},
        employeeName{std::move(name_)}, employeePosition{std::move(position_)}, payment{0},  workTime{0} {

    }

    IEmployee::~IEmployee() = default;

    void IEmployee::setWorkTime(int workTime_) {
        this->workTime = workTime_;
    }

    std::string IEmployee::getID() const {
        return this->id;
    }

    std::string IEmployee::getName() const {
        return this->employeeName;
    }

    std::string IEmployee::getPosition() const {
        return this->employeePosition;
    }

    int IEmployee::getWorkTime() const {
        return this->workTime;
    }

    int IEmployee::getPayment() const {
        return this->payment;
    }

    bool IEmployee::operator==(const IEmployee &other) const {
        return this->id == other.id;
    }

    bool IEmployee::operator!=(const IEmployee &other) const {
        return !(this->id == other.id);
    }
} // staff