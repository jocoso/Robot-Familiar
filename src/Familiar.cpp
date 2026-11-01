
#include <string>

#include "Familiar.h"
#include "ui/TerminalInterface.h"

namespace Familiar {

int Application::run() {
    TerminalInterface ti;

    ti.run();
    return 0;
}

} // namespace Familiar