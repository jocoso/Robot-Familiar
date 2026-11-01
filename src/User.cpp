#include "domain/User.h"

namespace Familiar {
User::User(int userId, const std::string &name) : userId(userId), name(name) {}

int User::getUserId() const {
    return userId;
}

const std::string &User::getName() const {
    return name;
}

void User::setName(const std::string &name) {
    this->name = name;
}

const std::vector<std::string> &User::getPreferences() const {
    return preferences;
}

void User::addPreference(const std::string &preference) {
    preferences.push_back(preference);
}

} // namespace Familiar