#ifndef FAMILIAR_TERMINAL_INTERFACE_H
#define FAMILIAR_TERMINAL_INTERFACE_H

#include <string>
#include <vector>

#include "ProjectManager.h"

// TerminalInterface.cpp
// createProject(), 
// createTask(), 
// getSelectedProject()

namespace Familiar {
const int MAX_NUMBER_OF_OPTIONS = 5;
class TerminalInterface {
  public:
    void run();

  private:
    bool isRunning = true;
    ProjectManager pm;
    Project *selectedProject = nullptr;

    const std::vector<std::unique_ptr<Project>> &getProjectList();
    
    //
    bool createProject();
    bool createTask();
    Project *getSelectedProject();
    //

    void showTitle() const;
    void showMenu() const;
    void printReport() const;
    void printSelectedProjectTask();
    void printProject(const Project &p);
    void printTasks(const std::vector<Task> &t);

    int readNumber();
    void readWord(std::string &output);
    int readMenuChoice();

    bool handleChoice(int choice);
    void killSwitch();

    bool saveData();
    bool loadData();
    void loadProjectList(std::ifstream &datafile);
    std::string saveProjectList(std::ofstream &datafile);

};

} // namespace Familiar

#endif // FAMILIAR_TERMINAL_INTERFACE_H