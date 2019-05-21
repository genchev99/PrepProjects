//
// Created by genchev99 on 21.05.19.
//

#ifndef EXAMPREP_EVENS_H
#define EXAMPREP_EVENS_H


#include "Set.h"

class Evens: public Set {
public:
    Evens();
    bool member(int x);
    bool addNumber(int x);
};


#endif //EXAMPREP_EVENS_H
