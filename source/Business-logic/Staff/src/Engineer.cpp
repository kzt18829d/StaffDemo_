//
// Created by hid3h on 23.06.2025.
//

#include "Engineer.hpp"
#include "Project.hpp"

#include <utility>

namespace staff {
    Programmer::Programmer(std::string id_, std::string name_, std::string position_, float partOfBudget_,
                           unsigned int proAdditions, unsigned int salary_, std::shared_ptr<Project> project_) :
                           downIEngineer(std::move(id_), std::move(name_), std::move(position_), partOfBudget_, proAdditions, salary_, std::move(project_)) {

    }

    Programmer::~Programmer() = default;

    Tester::Tester(std::string id_, std::string name_, std::string position_, float partOfBudget_, unsigned int proAdditions,
                   unsigned int salary_, std::shared_ptr<Project> project_) :
                   downIEngineer(std::move(id_), std::move(name_), std::move(position_), partOfBudget_, proAdditions, salary_, std::move(project_)) {

    }

    Tester::~Tester() = default;

    TeamLeader::TeamLeader(std::string id_, std::string name_, std::string position_, float partOfBudget_,
                           unsigned int proAdditions, unsigned int salary_, unsigned int heading_,
                           std::shared_ptr<Project> project_) :
                           Programmer(std::move(id_), std::move(name_), std::move(position_), partOfBudget_, proAdditions, salary_, std::move(project_)), heading{heading_}{

    }

    TeamLeader::~TeamLeader() = default;

    unsigned TeamLeader::getHeading() const {
        return this->heading;
    }

    bool TeamLeader::setHeading(unsigned int newHeading) {
        try {
            this->heading = newHeading;
        } catch (...) { return false; }
        return true;
    }

    bool TeamLeader::addHeading(unsigned int addHeading_) {
        try {
            this->heading += addHeading_;
        } catch (...) { return false; }
        return true;
    }

    bool TeamLeader::removeHeading(unsigned int remHeading) {
        if (remHeading > this->heading) remHeading = heading;
        try {
            this->heading -= remHeading;
        } catch (...) { return false; }
        return true;
    }

    int TeamLeader::calcHeads() {
        return heading;
    }

    void TeamLeader::calc() {
        payment = calcBase(this->salary, this->workTime) + IEngineer::calcProAdditions() + calcBudgetPart(this->partOfBudget, project.lock()->getTotalBudget()) + calcHeads();

    }

} // staff