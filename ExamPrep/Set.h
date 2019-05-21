//
// Created by genchev99 on 21.05.19.
//

#ifndef EXAMPREP_SET_H
#define EXAMPREP_SET_H

#include <iostream>
#include <vector>

class Set {
protected:
    std::vector<int> elements;
public:
  Set();
  virtual bool member(int x) = 0;
  void print();
};

#endif //EXAMPREP_SET_H
