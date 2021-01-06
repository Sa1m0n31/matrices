/*
 * Klasa odpowiedzialna za operacje na dwoch lub wiecej macierzach - dodawanie, odejmowanie i mnozenie macierzy
 */

#include<vector>

#include "MultipleOperation.h"
#include "Matrix.h"

using namespace std;

MultipleOperation::MultipleOperation() {

}

MultipleOperation::MultipleOperation(Matrix A, Matrix B) {
    this->A = A;
    this->B = B;
}

const Matrix MultipleOperation::getA() {
    return A;
}

void MultipleOperation::setA(Matrix &a) {
    A = a;
}

const Matrix MultipleOperation::getB() {
    return B;
}

void MultipleOperation::setB(Matrix &b) {
    B = b;
}

/* Dodawanie macierzy */
Matrix MultipleOperation::addMatrices() {
    int rowsA = A.getRows(), colsA = A.getCols(), rowsB = B.getRows(), colsB = B.getCols();
    int i, j;
    Matrix *result;
    vector<vector<double> > resultMatrix;
    vector<double> resultRow;
    Matrix *errorMatrix = new Matrix(0);


    if((rowsA != rowsB)||(colsA != colsB)) {
        return *errorMatrix;
    }

    for(i=0; i<rowsA; i++) {
        resultMatrix.push_back(resultRow);
        for(j=0; j<colsA; j++) {
            resultMatrix[i].push_back(A.getMatrix().at(i).at(j) + B.getMatrix().at(i).at(j));
        }
    }

    result = new Matrix(rowsA, colsA, resultMatrix);

    return *result;
}

/* Odejmowanie macierzy */
Matrix MultipleOperation::subtractMatrices() {
    int rowsA = A.getRows(), colsA = A.getCols(), rowsB = B.getRows(), colsB = B.getCols();
    int i, j;
    Matrix *result;
    vector<vector<double> > resultMatrix;
    vector<double> resultRow;
    Matrix *errorMatrix = new Matrix(0);

    if((rowsA != rowsB)||(colsA != colsB)) {
        return *errorMatrix;
    }

    for(i=0; i<rowsA; i++) {
        resultMatrix.push_back(resultRow);
        for(j=0; j<colsA; j++) {
            resultMatrix[i].push_back(A.getMatrix().at(i).at(j) - B.getMatrix().at(i).at(j));
        }
    }

    result = new Matrix(rowsA, colsA, resultMatrix);

    return *result;
}

/* Mnozenie macierzy */
Matrix MultipleOperation::multiplyMatrices() {
    int rowsA = A.getRows(), colsA = A.getCols(), rowsB = B.getRows(), colsB = B.getCols();
    int i, j, k;
    Matrix result;
    vector<vector<double> > resultMatrix;
    vector<double> resultRow;
    double single;
    Matrix *errorMatrix = new Matrix(0);

    if(colsA != rowsB) {
        return *errorMatrix;
    }

    for(i=0; i<rowsA; i++) {
        resultMatrix.push_back(resultRow);
        for(j=0; j<colsB; j++) {
            single = 0;
            for(k=0; k<colsA; k++) {
                single += A.getMatrix()[i][k] * B.getMatrix()[k][j];
            }
            resultMatrix[i].push_back(single);
        }
    }

    result.setRows(rowsA);
    result.setCols(colsB);
    result.setMatrix(resultMatrix);

    return result;
}