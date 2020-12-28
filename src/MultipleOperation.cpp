/*
 * Klasa odpowiedzialna za operacje na dwoch lub wiecej macierzach - dodawanie, odejmowanie i mnozenie macierzy
 */

#ifndef MULTIPLEOPERATION_CPP
#define MULTIPLEOPERATION_CPP

#include<vector>
#include<iostream>

#include "./Matrix.cpp"

using namespace std;

class MultipleOperation {
public:
    Matrix A, B;

    vector<double> row1 = {-9999.9999, -9999.9999};
    vector<double> row2 = {-9999.9999, -9999.9999};
    vector<vector<double> > matrixErr = {row1, row2};
    const Matrix *errorMatrix = new Matrix(2, 2, matrixErr);

    /* GETTERY I SETTERY */

public:
    /* KONSTRUKTORY */
    MultipleOperation() {

    }

    MultipleOperation(Matrix A, Matrix B) {
        this->A = A;
        this->B = B;
    }

    const Matrix &getA() const {
        return A;
    }

    void setA(Matrix &a) {
        A = a;
    }

    const Matrix &getB() const {
        return B;
    }

    void setB(Matrix &b) {
        B = b;
    }

    /* METODY */
public:
    /* Dodawanie macierzy */
    Matrix addMatrices() {
        int rowsA = A.getRows(), colsA = A.getCols(), rowsB = B.getRows(), colsB = B.getCols();
        int i, j;
        Matrix *result;
        vector<vector<double> > resultMatrix;
        vector<double> resultRow;

        if((rowsA != rowsB)||(colsA != colsB)) {
            cout << "Blad: Dodawac mozna tylko macierze o tych samych wymiarach" << endl;
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
    Matrix subtractMatrices() {
        int rowsA = A.getRows(), colsA = A.getCols(), rowsB = B.getRows(), colsB = B.getCols();
        int i, j;
        Matrix *result;
        vector<vector<double> > resultMatrix;
        vector<double> resultRow;

        if((rowsA != rowsB)||(colsA != colsB)) {
            cout << "Blad: Odejmowac mozna tylko macierze o tych samych wymiarach" << endl;
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
    Matrix multiplyMatrices() {
        int rowsA = A.getRows(), colsA = A.getCols(), rowsB = B.getRows(), colsB = B.getCols();
        int i, j, k;
        Matrix result;
        vector<vector<double> > resultMatrix;
        vector<double> resultRow;
        double single;

        if(colsA != rowsB) {
            cout << "Blad: Mnozenie macierzy dozwolone tylko gdy row(a) = col(b)" << endl;
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
};

#endif