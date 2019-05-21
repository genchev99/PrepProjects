//
// Created by genchev99 on 21.05.19.
//

#include "Evens.h"

Evens::Evens() {
  for (auto it = this->elements.begin(); it < this->elements.end(); it++) {
    if (*it % 2 != 0) {
      this->elements.erase(it);
    }
  }
}

bool Evens::member(int x) {
  for (const auto &element : this->elements) {
    if (element == x) {
      return true;
    }
  }

  return false;
}

bool Evens::addNumber(int x) {
  if (x % 2 != 0) {
    return false;
  }

  this->elements.push_back(x);
  return true;
}
