#include <vector>
#include <algorithm>

#include "ProjectManager.h"
#include "Project.h"

namespace Familiar {
bool ProjectManager::createProject(std::unique_ptr<Project> project) {

    if (!project)
        return false;

    project->setId(nextProjectId++);

    projects.push_back(std::move(project));
    return true;
}

bool ProjectManager::loadProject(std::unique_ptr<Project> project) {
    if (!project) {
        return false;
    }

    if (findProject(project->getId()) != nullptr) {
        return false;
    }

    if (project->getId() >= nextProjectId) {
        nextProjectId = project->getId() + 1;
    }

    projects.push_back(std::move(project));

    return true;
}

void ProjectManager::clearProjects() {
    projects.clear();

    nextProjectId = 1;
}

const std::vector<std::unique_ptr<Project>> &
ProjectManager::getProjects() const {
    return projects;
}

Project *ProjectManager::findProject(int id) {
    for (const auto &project : projects) {
        if (project->getId() == id) {
            return project.get();
        }
    }

    return nullptr;
}

const Project *ProjectManager::findProject(int id) const {
    for (const auto &project : projects) {
        if (project->getId() == id) {
            return project.get();
        }
    }

    return nullptr;
}

bool ProjectManager::updateProject(int id, const Project &updatedProject) {
    Project *project = findProject(id);

    if (project == nullptr) {
        return false;
    }

    *project = updatedProject;
    return true;
}

bool ProjectManager::addTaskToProject(int pId, const Task &t) {
    Project *project = findProject(pId);

    if (project == nullptr) {
        return false;
    }

    project->addTask(t);
    return true;
}

bool ProjectManager::deleteProject(int id) {
    auto it = std::find_if(projects.begin(), projects.end(),
                           [id](const std::unique_ptr<Project> &project) {
                               return project->getId() == id;
                           });

    if (it == projects.end()) {
        return false;
    }

    projects.erase(it);
    return true;
}
} // namespace Familiar