//
// Created by genchev99 on 21.05.19.
//

#include "Set.h"

Set::Set() = default;

void Set::print() {
  for (unsigned long i = 0; i < this->elements.size(); ++i) {
    std::cout << elements.at(i) << (i != elements.size() -1? ", ": "");
  }

  std::cout << std::endl;
}
