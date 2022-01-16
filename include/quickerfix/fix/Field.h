#pragma once

#include <ostream>
#include <string>

class Field {
  int m_num;
  std::string m_name;

public:
  Field(int num, std::string name);

  friend std::ostream &operator<<(std::ostream &ostream, const Field &field);
};
