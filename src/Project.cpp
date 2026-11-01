#include "Project.h"

#include <algorithm>
#include <utility>

namespace Familiar {

Project::Project(int id, std::string name, std::string desc,
                 ProjectStatus status)
    : brain(id, std::move(name), NodeType::Project), desc(std::move(desc)),
      status(status) {}

int Project::getId() const {
    return brain.id;
}
void Project::setId(int id) {
    brain.id = id;
}
const std::string &Project::getName() const {
    return brain.name;
}
void Project::setName(const std::string &name) {
    brain.name = name;
}
const std::string &Project::getDescription() const {
    return desc;
}
void Project::setDescription(const std::string &desc) {
    this->desc = desc;
}
ProjectStatus Project::getStatus() const {
    return status;
}

void Project::setStatus(ProjectStatus status) {
    this->status = status;
}

// Task management
void Project::addTask(const Task &task) {
    tasks.push_back(task);
}
bool Project::removeTask(int taskId) {
    auto it =
        std::find_if(tasks.begin(), tasks.end(), [taskId](const Task &task) {
            return task.getId() == taskId;
        });

    if (it == tasks.end()) {
        return false;
    }

    tasks.erase(it);
    return true;
}

Project &Project::operator=(const Project &other) {
    if (this != &other) {

        brain = other.brain;
        desc = other.desc;
        status = other.status;
    }

    return *this;
}

const Task *Project::getTask(int taskId) const {
    auto it =
        std::find_if(tasks.begin(), tasks.end(), [taskId](const Task &task) {
            return task.getId() == taskId;
        });

    if (it == tasks.end()) {
        return nullptr;
    }
    return &(*it);
}

const std::vector<Task> &Project::getTasks() const {
    return tasks;
}
}; // namespace Familiar