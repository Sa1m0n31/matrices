#ifndef UNTITLED7_SINGLEOPERATION_H
#define UNTITLED7_SINGLEOPERATION_H

#include "Matrix.h"

using namespace std;

class SingleOperation {
private:
    Matrix matrix;
    vector<double> row1;
    vector<double> row2;
    vector<vector<double> > matrixErr;
    const Matrix *errorMatrix;

public:
    Matrix getMatrix();
    void setMatrix(const Matrix &matrix);
    Matrix transpose();
    Matrix inverse(Matrix m);
    static Matrix getMatrixForLaplaceTransform(Matrix m, int rowToDelete, int columnToDelete);
    double determinant();
    double trace(Matrix m);
    Matrix getSubmatrix(Matrix m, int rowsStart, int rowsEnd, int colsStart, int colsEnd);

    static bool isSquare(Matrix m);
};

#endif //UNTITLED7_SINGLEOPERATION_H
