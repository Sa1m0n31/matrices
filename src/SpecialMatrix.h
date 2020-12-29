#ifndef UNTITLED7_SPECIALMATRIX_H
#define UNTITLED7_SPECIALMATRIX_H

#include "Matrix.h"

using namespace std;

class SpecialMatrix {
public:
    static Matrix getVandermondeMatrix();
    static Matrix getToeplitzMatrix();
    static Matrix getPermutationMatrix();
};

#endif //UNTITLED7_SPECIALMATRIX_H
