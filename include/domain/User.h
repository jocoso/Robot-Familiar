#pragma once

#include <string>
#include <vector>

namespace Familiar {
class User {
  public:
    User(int userId, const std::string &name);
    int getUserId() const;
    const std::string &getName() const;
    void setName(const std::string &name);
    const std::vector<std::string> &getPreferences() const;
    void addPreference(const std::string &preference);

  private:
    int userId;
    std::string name;
    std::vector<std::string> preferences;
};
} // namespace Familiar