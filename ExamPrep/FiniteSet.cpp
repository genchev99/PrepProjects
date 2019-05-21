//
// Created by genchev99 on 21.05.19.
//

#include "FiniteSet.h"

bool FiniteSet::addNumber(int x) {
  if (this->elements.size() == this->maxSize)
    return false;

  for (const auto &element : this->elements) {
    if (element == x)
      return false;
  }

  this->elements.push_back(x);
  return true;
}

FiniteSet::FiniteSet(): FiniteMultiset(10) {}
FiniteSet::FiniteSet(int size): FiniteMultiset(size) {}
