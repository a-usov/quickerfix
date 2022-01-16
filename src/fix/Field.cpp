#include "quickerfix/fix/Field.h"
#include <fmt/core.h>

Field::Field(int num, std::string name) : m_num(num), m_name(std::move(name)) {}

std::ostream &operator<<(std::ostream &ostream, const Field &field) {
  ostream << fmt::format("Tag {}<{}>", field.m_name, field.m_num);
  return ostream;
}
