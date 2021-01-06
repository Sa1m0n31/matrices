//
// Created by sajmo on 29.12.2020.
//

#ifndef UNTITLED7_GAUSSIANELIMINATION_H
#define UNTITLED7_GAUSSIANELIMINATION_H

#include<vector>

#include "./Matrix.h"

using namespace std;

class GaussianElimination {
private:
    Matrix matrix;
    vector<double> row1;
    vector<double> row2;
    vector<vector<double> > matrixErr;
    const Matrix *errorMatrix;
public:
    GaussianElimination();
    GaussianElimination(Matrix matrix);
    Matrix getMatrix();
    void setMatrix(const Matrix &matrix);
    Matrix switchRows(int a, int b);
    Matrix multiplyRow(int row, double number);
    Matrix addOneRowToAnother(int a, int b);
    Matrix upperTriangular();
    static Matrix reducedEchelon(Matrix matrix);
    static Matrix fullReducedEchelon(Matrix matrix);
    Matrix resolveSystemOfLinearEquations();
};

#endif //UNTITLED7_GAUSSIANELIMINATION_H
