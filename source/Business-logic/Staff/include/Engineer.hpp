//
// Created by hid3h on 23.06.2025.
//

#ifndef STAFFDEMO_REFACTOR_ENGINEER_HPP
#define STAFFDEMO_REFACTOR_ENGINEER_HPP
#include "IEngineer.hpp"

namespace staff {

    class Programmer : public downIEngineer {
    public:
        Programmer(std::string id_, std::string name_, std::string position_, float partOfBudget_, unsigned int proAdditions, unsigned int salary_, std::shared_ptr<Project> project_);
        ~Programmer() override;
    };

    class Tester : public downIEngineer {
    public:
        Tester(std::string id_, std::string name_, std::string position_, float partOfBudget_, unsigned int proAdditions, unsigned int salary_, std::shared_ptr<Project> project_);
        ~Tester() override;
    };

    class TeamLeader : public Programmer , public Heading {
    private:
        unsigned heading;

    public:
        TeamLeader(std::string id_, std::string name_, std::string position_, float partOfBudget_, unsigned proAdditions, unsigned int salary_, unsigned int heading, std::shared_ptr<Project> project_);
        ~TeamLeader() override;

        unsigned getHeading() const;

        bool setHeading(unsigned newHeading);
        bool addHeading(unsigned addHeading_);
        bool removeHeading(unsigned remHeading);

        int calcHeads() override;
        void calc() override;

    };

} // staff

#endif //STAFFDEMO_REFACTOR_ENGINEER_HPP
