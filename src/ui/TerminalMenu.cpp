void TerminalInterface::run() {
    showTitle();

    loadData();
    while (isRunning) {
        try {
            int choice = readMenuChoice();
            handleChoice(choice);
        } catch (const std::runtime_error &e) {
            std::cerr << '\n' << e.what() << '\n';
            killSwitch();
        }
    }
}

void TerminalInterface::killSwitch() {
    isRunning = false;
}