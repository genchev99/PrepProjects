//
// Created by genchev99 on 21.05.19.
//

#ifndef EXAMPREP_FINITEMULTISET_H
#define EXAMPREP_FINITEMULTISET_H


#include "Set.h"

class FiniteMultiset: public Set {
protected:
//    std::vector<int> elements;
    int maxSize;
public:
    FiniteMultiset();
    FiniteMultiset(int size);
    bool member(int x);
    bool addNumber(int x);
};


#endif //EXAMPREP_FINITEMULTISET_H
