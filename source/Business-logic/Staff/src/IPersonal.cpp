#include "IPersonal.hpp"

namespace staff {
    IPersonal::IPersonal(std::string id_, std::string name_, std::string position_, int salary_) : IEmployee(std::move(id_), std::move(name_), std::move(position_)), salary{salary_} {

    }

    int IPersonal::calcBase(int salary_, int worktime_) {
        return salary_ * worktime_;
    }

    int IPersonal::calcBonus() {
        return 0;
    }

    void IPersonal::calc() {
        payment = calcBase(this->salary, this->workTime) + calcBonus();
    }

    int IPersonal::getSalary() const {
        return salary;
    }

    bool IPersonal::setSalary(int newSalary) {
        try {
            salary = newSalary;
        } catch (...) { return false; }
        return  true;
    }

    std::string IPersonal::makeLineForFile(char delim, char subDelim) {
        return std::string(getID() + delim + getName() + delim + getPosition() + delim + std::to_string(getSalary()) + delim + "");
    }
} // staff