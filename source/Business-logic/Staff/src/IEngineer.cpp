//
// Created by hid3h on 23.06.2025.
//

#include "IEngineer.hpp"
#include "Project.hpp"

namespace staff {
    IEngineer::IEngineer(std::string id_, std::string name_, std::string position_, float partOfBudget_, unsigned int proAdditions_) :
            IEmployee(std::move(id_), std::move(name_), std::move(position_)), partOfBudget{partOfBudget_}, proAdditions{proAdditions_}{

    }

    int IEngineer::calcBase(int salary_, int worktime_) {
        return salary_ * worktime_;
    }

    int IEngineer::calcBudgetPart(float part, int budget) {
        if (part > 100) part = 100;
        return static_cast<int>(part * static_cast<float>(budget) / 100);
    }

    int IEngineer::calcProAdditions() {
        return static_cast<int>(getProAdditions());
    }

    void IEngineer::calc() {
        IEmployee::calc();
    }

    float IEngineer::getPartOfBudget() const {
        return this->partOfBudget;
    }


    void IEngineer::setPartOfBudget(float newPartOfBudget) {
        this->partOfBudget = newPartOfBudget;
    }


    unsigned int IEngineer::getProAdditions() const {
        return this->proAdditions;
    }

    void IEngineer::setProAdditions(int newProAdditions) {
        this->proAdditions = newProAdditions;
    }

    void IEngineer::addProAdditions(int ProAdditions) {
        this->proAdditions += ProAdditions;
    }

    void IEngineer::removeProAdditions(unsigned remProAdditions) {
        if (remProAdditions > this->proAdditions) remProAdditions = proAdditions;
        this->proAdditions -= remProAdditions;
    }

    int IEngineer::calcBonus() {
        return 0;
    }


    downIEngineer::downIEngineer(std::string id_, std::string name_, std::string position_, float partOfBudget_,
                                 unsigned int proAdditions,unsigned int salary_, std::shared_ptr<Project> project_) :
            IEngineer(std::move(id_), std::move(name_), std::move(position_), partOfBudget_, proAdditions), salary{salary_}, project(project_) {

    }

    void downIEngineer::calc() {
        payment = calcBase(this->salary, this->workTime) + IEngineer::calcProAdditions() + calcBudgetPart(this->partOfBudget, getProject()->getTotalBudget());
    }

    unsigned int downIEngineer::getSalary() const {
        return this->salary;
    }

    std::shared_ptr<Project> downIEngineer::getProject() {
        return this->project.lock();
    }

    std::shared_ptr<Project> downIEngineer::getProject() const {
        return this->project.lock();
    }

    void downIEngineer::setSalary(int newSalary) {
        this->salary = newSalary;
    }

    bool downIEngineer::addProject(std::shared_ptr<Project> newProject) {
        try { this->project = newProject; }
        catch (...) { return false;}
        return true;
    }

    bool downIEngineer::removeProject(std::shared_ptr<Project> remProject) {
        if (!remProject) return false;
        if (!(remProject.get() == project.lock().get())) return false;
        project.reset();
        return true;
    }

    bool downIEngineer::removeAllProject() {
        if (project.expired()) return true;
        auto thisMember = shared_from_this();
        if (!(project.lock()->removeMember(thisMember))) return false;
        project.reset();
        if (!project.expired()) return false;
        return true;
    }

    std::vector<std::string> downIEngineer::getProjectNames() const {
        if (!project.expired()) return {};
        return {project.lock()->getProjectName()};
    }

    std::string downIEngineer::makeLineForFile(char delim, char subDelim) {
        auto pname = getProject();
        return std::string(getID() + delim + getName() + delim + getPosition() + delim + std::to_string(getSalary()) +
            delim + (pname ? pname->getProjectName() : ""));
    }

    ManagerIEngineer::ManagerIEngineer(std::string id_, std::string name_, std::string position_, float partOfBudget_,
                                       unsigned int proAdditions_, unsigned int heading_, std::vector<std::shared_ptr<Project>> projects_) :
            IEngineer(std::move(id_), std::move(name_), std::move(position_), partOfBudget_, proAdditions_), heading{heading_} {

        for (const auto& ptr: projects_) {
            if (!ptr) continue;
            this->projects.push_back(ptr);
        }
    }

    unsigned int ManagerIEngineer::getHeading() const {
        return this->heading;
    }

    std::vector<std::shared_ptr<Project>> ManagerIEngineer::getProject() const {
        std::vector<std::shared_ptr<Project>> temp;
        for (const auto& weak: projects) {
            if (weak.expired()) continue;
            temp.push_back(weak.lock());
        }
        return temp;
    }

    void ManagerIEngineer::setHeading(unsigned newHeading) {
        this->heading = newHeading;
    }

    std::vector<std::string> ManagerIEngineer::getProjectNames() const {
        std::vector<std::string> temp;
        for (const auto& weak: projects) {
            temp.push_back(weak.lock()->getProjectName());
        }
        return temp;
    }

    std::string ManagerIEngineer::makeLineForFile(char delim, char subDelim) {
        std::string projectNamesString;
        auto projectNames = this->getProjectNames();
       if (!projectNames.empty()) {
           projectNamesString = projectNames[0];
           for (auto index = std::next(projectNames.begin()); index != projectNames.end(); ++index) projectNamesString += subDelim + *index;
       }
        return std::string(getID() + delim + getName() + delim + getPosition() + delim + "" + delim + projectNamesString);
    }

    int ManagerIEngineer::calcHeads() {
        return heading;
    }

    void ManagerIEngineer::calc() {
        payment = IEngineer::calcProAdditions() + calcHeads();
        int BudgPart{0};
        for (const auto& project: projects) BudgPart += calcBudgetPart(this->partOfBudget, project.lock()->getTotalBudget());
        payment += BudgPart;
    }

} // staff