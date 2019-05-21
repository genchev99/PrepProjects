#include <iostream>
#include "FiniteMultiset.h"
#include "FiniteSet.h"
#include "Evens.h"

bool containsNumber(std::vector<Set *> sets, int number) {
  for (const auto &set : sets) {
    if (!set->member(number))
      return false;
  }

  return true;
}

int main() {
  Evens evens;
  FiniteMultiset finiteMultiset(10);
  FiniteSet finiteSet(10);

  evens.addNumber(2);
  evens.addNumber(3);
  evens.addNumber(6);

  finiteMultiset.addNumber(6);
  finiteMultiset.addNumber(12);
  finiteMultiset.addNumber(13);

  finiteSet.addNumber(1);
  finiteSet.addNumber(1);
  finiteSet.addNumber(6);

  evens.print();
  finiteSet.print();
  finiteMultiset.print();

  /* Populating sets */
  std::vector<Set *> sets;
  sets.push_back(&evens);
  sets.push_back(&finiteSet);
  sets.push_back(&finiteMultiset);

  std::cout << containsNumber(sets, 6) << std::endl;
  return 0;
}