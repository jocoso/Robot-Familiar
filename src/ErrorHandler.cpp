#ifndef FAMILIAR_ERROR_HANDLER_H
#define FAMILIAR_ERROR_HANDLER_H

#include "ErrorHandler.h"
#include <iostream>

namespace Familiar {
void reportError(const std::string &msg) {
    std::cerr << "ERROR: " << msg << '\n';
}
} // namespace Familiar

#endif // FAMILIAR_ERROR_HANDLER_H