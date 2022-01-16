#pragma once

#include "fix/Fix.h"
#include <optional>

namespace qf {

/** Load FIX configuration file **/
std::optional<Fix> load_document(const std::string &path);

} // namespace qf
