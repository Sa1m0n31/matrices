#ifndef UNTITLED7_MULTIPLEOPERATION_H
#define UNTITLED7_MULTIPLEOPERATION_H

#include "Matrix.h"

using namespace std;

class MultipleOperation {
private:
    Matrix A, B;
public:
    MultipleOperation();
    MultipleOperation(Matrix A, Matrix B);

    const Matrix getA();

    void setA(Matrix &a);

    const Matrix getB();

    void setB(Matrix &b);

    Matrix addMatrices();
    Matrix subtractMatrices();
    Matrix multiplyMatrices();
};

#endif //UNTITLED7_MULTIPLEOPERATION_H
