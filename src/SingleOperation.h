#ifndef UNTITLED7_SINGLEOPERATION_H
#define UNTITLED7_SINGLEOPERATION_H

#include "Matrix.h"

using namespace std;

class SingleOperation {
private:
    Matrix matrix;

public:
    Matrix getMatrix();
    void setMatrix(const Matrix &matrix);
    Matrix transpose();
    Matrix inverse();
    Matrix crossRowAndColumn(int k, int l);
    double determinant();
    double trace();
    double adjugate(int i, int j);
    Matrix getSubmatrix(int rowsStart, int rowsEnd, int colsStart, int colsEnd);

    static bool isSquare(Matrix m);
};

#endif //UNTITLED7_SINGLEOPERATION_H
