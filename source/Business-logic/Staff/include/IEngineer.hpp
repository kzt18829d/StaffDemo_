#ifndef STAFFDEMO_REFACTOR_IENGINEER_HPP
#define STAFFDEMO_REFACTOR_IENGINEER_HPP
#include "IEmployee.hpp"
#include "StaffInterfaces.hpp"
#include <memory>
#include <vector>

namespace staff {

    class Project;

    class IEngineer : public IEmployee, public WorkBaseTime, public ProjectBudget, public std::enable_shared_from_this<IEngineer>{
    protected:
        float partOfBudget;
        unsigned proAdditions;

        int calcBonus() override;
        int calcBase(int salary_, int worktime_) override;
        int calcBudgetPart(float part, int budget) override;
        int calcProAdditions() override;

    public:
        IEngineer(std::string id_, std::string name_, std::string position_, float partOfBudget_, unsigned proAdditions_);
        virtual ~IEngineer() override = default;

        void calc() override;

        float getPartOfBudget() const;
        unsigned getProAdditions() const;

        void setPartOfBudget(float newPartOfBudget);
        void setProAdditions(int newProAdditions);
        void addProAdditions(int ProAdditions);
        void removeProAdditions(unsigned remProAdditions);

        virtual std::vector<std::string> getProjectNames() const = 0;

        virtual bool removeProject(std::shared_ptr<Project> remProject) = 0;
        virtual bool addProject(std::shared_ptr<Project> newProject) = 0;
        virtual bool removeAllProject() = 0;

        std::string makeLineForFile(char delim, char subDelim = ',') override = 0;

    };

class downIEngineer : public IEngineer{
    protected:
        unsigned salary;
        std::weak_ptr<Project> project;

    public:
        downIEngineer(std::string id_, std::string name_, std::string position_, float partOfBudget_, unsigned int proAdditions, unsigned int salary_, std::shared_ptr<Project> project_);
        virtual ~downIEngineer() override = default;

        void calc() override;

        unsigned getSalary() const;
        std::shared_ptr<Project> getProject();
        std::shared_ptr<Project> getProject() const;

        void setSalary(int newSalary);

        std::vector<std::string> getProjectNames() const override;

        bool addProject(std::shared_ptr<Project> newProject) override;
        bool removeProject(std::shared_ptr<Project> remProject) override;
        bool removeAllProject() override;

        std::string makeLineForFile(char delim, char subDelim = ',') override;
    };

    class ManagerIEngineer : public IEngineer, public Heading {
    protected:
        unsigned heading;
        std::vector<std::weak_ptr<Project>> projects;

    public:
        ManagerIEngineer(std::string id_, std::string name_, std::string position_, float partOfBudget_, unsigned int proAdditions_, unsigned int heading_, std::vector<std::shared_ptr<Project>> projects_);
        virtual ~ManagerIEngineer() override = default;

        unsigned getHeading() const;
        std::vector<std::shared_ptr<Project>> getProject() const;
        std::vector<std::string> getProjectNames() const override;


        void setHeading(unsigned newHeading);
        bool addProject(std::shared_ptr<Project> newProject) override = 0;
        bool removeProject(std::shared_ptr<Project> remProject)  override = 0;
        bool removeAllProject() override = 0;

        int calcHeads() override;

        void calc() override;

        std::string makeLineForFile(char delim, char subDelim = ',') override;

    };

} // staff

#endif //STAFFDEMO_REFACTOR_IENGINEER_HPP
