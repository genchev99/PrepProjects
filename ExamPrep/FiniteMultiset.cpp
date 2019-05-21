//
// Created by genchev99 on 21.05.19.
//

#include "FiniteMultiset.h"

FiniteMultiset::FiniteMultiset() {
  this->maxSize = 10;
}

FiniteMultiset::FiniteMultiset(int size) {
  this->maxSize = size;
}

bool FiniteMultiset::addNumber(int x) {
  if (this->maxSize == this->elements.size()) return false;

  this->elements.push_back(x);
  return false;
}

bool FiniteMultiset::member(int x) {
  for (const auto &element : this->elements) {
    if (element == x)
      return true;
  }

  return false;
}
