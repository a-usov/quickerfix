#include "quickerfix/FixConfigParser.h"
#include <pugixml.hpp>
#include <spdlog/spdlog.h>

namespace qf {

std::optional<Fix> load_document(const std::string &path) {
  pugi::xml_document doc;
  const auto result = doc.load_file(path.c_str());

  if (result.status != pugi::xml_parse_status::status_ok) {
    spdlog::critical("Could not parse FIX configuration file, error: {}", result.description());
    return std::nullopt;
  }

  return Fix{};
}

} // namespace qf
