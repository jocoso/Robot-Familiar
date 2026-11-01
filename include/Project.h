#ifndef FAMILIAR_PROJECT_H
#define FAMILIAR_PROJECT_H

#pragma once

#include <string>
#include <vector>
#include "Task.h"
#include "domain/Node.h"

namespace Familiar {
enum ProjectStatus { Active = 1, Completed = 2, Archived = 3 };
class Project {
  public:
    explicit Project(int id, std::string name, std::string desc,
                     ProjectStatus status = ProjectStatus::Active);

    // Getters
    int getId() const;
    const std::string &getName() const;
    ProjectStatus getStatus() const;
    const std::string &getDescription() const;
    void setId(int id);

    // Setter
    void setName(const std::string &name);
    void setDescription(const std::string &desc);
    void setStatus(ProjectStatus status);

    // Task management
    void addTask(const Task &task);
    bool removeTask(int taskId);
    const Task *getTask(int taskId) const;

    const std::vector<Task> &getTasks() const;

    Project &operator=(const Project &other);

  private:
    Node brain;
    std::string desc;
    std::vector<Task> tasks;
    ProjectStatus status = ProjectStatus::Active;
};
} // namespace Familiar

#endif // FAMILIAR_PROJECT_H