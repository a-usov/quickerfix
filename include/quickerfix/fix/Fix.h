#pragma once

#include "Field.h"
#include <unordered_map>

class Fix {
  std::unordered_map<int, Field> m_fields;

public:
  friend std::ostream &operator<<(std::ostream &ostream, const Fix &fix);
};
