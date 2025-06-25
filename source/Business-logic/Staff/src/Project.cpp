#include "Project.hpp"
#include "IEngineer.hpp"

namespace staff {

    Project::Project(std::string name_, unsigned int budget) : name(std::move(name_)), totalBudget{budget} {

    }

    std::string Project::getProjectName() const {
        return name;
    }

    unsigned Project::getTotalBudget() const {
        return totalBudget;
    }

    std::vector<std::weak_ptr<IEngineer>> Project::getAllMemebers() const {
        return members;
    }

    bool Project::addMember(std::shared_ptr<IEngineer> member) {
        if (!member) return false;
        if (auto findIt = std::find_if(members.begin(), members.end(), [&](const std::weak_ptr<IEngineer>& current) {
            return !current.expired() && current.lock().get() == member.get();
        }); findIt == members.end()) {
            auto sharedFromThis = shared_from_this();
            member->addProject(sharedFromThis);
            members.push_back(member);
            return true;
        }
        return false;
    }

    bool Project::removeMember(std::shared_ptr<IEngineer> member) {
        if (!member) return false;
        if (auto findIt = std::find_if(members.begin(), members.end(), [&](const std::weak_ptr<IEngineer>& current){
                return current.lock().get() == member.get();
        }); findIt != members.end()) {
            auto sharedFromThis = shared_from_this();
            member->removeProject(sharedFromThis);
            members.erase(findIt);
            return true;
        }
        return false;
    }

    bool Project::operator==(const Project &other) const {
        return this->name == other.name;
    }

    bool Project::operator!=(const Project &other) const {
        return !(this->name == other.name);
    }

    bool Project::operator<(const Project &other) const {
        return this->name < other.name;
    }

    bool Project::operator>(const Project &other) const {
        return this->name > other.name;
    }
} // staff