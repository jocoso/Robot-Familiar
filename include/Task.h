#ifndef FAMILIAR_TASK_H
#define FAMILIAR_TASK_H

#pragma once

#include <string>

namespace Familiar {
enum class TaskStatus {
    Pending = 1,
    Active = 2,
    Completed = 3,
    Blocked = 4,
    Cancelled = 5
};
class Project;

class Task {
  public:
    Task(int id, std::string pName, std::string pDesc,
         TaskStatus status = TaskStatus::Active);

    int getId() const;
    int getProjectId() const;

    const std::string &getTitle() const;
    void setTitle(const std::string &title);

    const std::string &getDescription() const;
    void setDescription(const std::string &desc);

    TaskStatus getStatus() const;
    void setStatus(TaskStatus status);

  public:
    int id = 0;
    int parentId = 0;

    std::string title;
    std::string description;

    TaskStatus status = TaskStatus::Pending;
};
} // namespace Familiar
#endif