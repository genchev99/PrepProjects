//
// Created by genchev99 on 21.05.19.
//

#ifndef EXAMPREP_FINITESET_H
#define EXAMPREP_FINITESET_H


#include "FiniteMultiset.h"

class FiniteSet: public FiniteMultiset {
public:
    FiniteSet();
    FiniteSet(int size);
    bool addNumber(int x);
};


#endif //EXAMPREP_FINITESET_H
