#include "quickerfix/fix/Fix.h"
#include <fmt/ostream.h>
#include <fmt/ranges.h>

std::ostream &operator<<(std::ostream &ostream, const Fix &fix) {
  ostream << fmt::format("Fields", fix.m_fields);
  return ostream;
}
