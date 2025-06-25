//
// Created by hid3h on 23.06.2025.
//

#include "Personal.hpp"

namespace staff {
    Cleaner::Cleaner(std::string id_, std::string name_, std::string position_, int salary_) :
        IPersonal(std::move(id_), std::move(name_), std::move(position_), salary_) {

    }

    Driver::Driver(std::string id_, std::string name_, std::string position_, int salary_, int nBonus) :
            IPersonal(std::move(id_), std::move(name_), std::move(position_), salary_), nightBonus{nBonus} {

    }

    int Driver::calcBonus() {
        return getBonus();
    }

    int Driver::getBonus() const {
        return nightBonus;
    }

    bool Driver::setBonus(int newBonus) {
        try {
            nightBonus = newBonus;
        } catch (...) { return false; }
        return true;
    }
} // staff