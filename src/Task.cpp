#include "Task.h"
#include <utility>

namespace Familiar {
Task::Task(int id, std::string pName, std::string pDesc, TaskStatus status)
    : id(id), title(std::move(pName)), description(std::move(pDesc)),
      status(status) {}

int Task::getId() const {
    return id;
}
const std::string &Task::getTitle() const {
    return title;
}
void Task::setTitle(const std::string &title) {
    this->title = title;
}
const std::string &Task::getDescription() const {
    return description;
}

void Task::setDescription(const std::string &desc) {
    this->description = desc;
}

TaskStatus Task::getStatus() const {
    return status;
}

void Task::setStatus(TaskStatus status) {
    this->status = status;
}
}; // namespace Familiar