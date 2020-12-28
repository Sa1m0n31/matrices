/*
 * Klasa odpowiedzialna za operacje elementarne, wykorzystywane w Metodzie Eliminacji Gaussa
 */

#ifndef GAUSSIANELIMINACTION_CPP
#define GAUSSIANELIMINATION_CPP

#include<vector>
#include<iostream>

#include "./Matrix.cpp"

class GaussianElimination {
private:
    Matrix matrix;

public:
    const Matrix &getMatrix() const {
        return matrix;
    }

    void setMatrix(const Matrix &matrix) {
        GaussianElimination::matrix = matrix;
    }

    /* METHODS */

    /* Zamiana dwoch wierszy */
    Matrix switchRows(int a, int b) {
        Matrix resultMatrix;
        vector<vector<double> > newMatrix = matrix.getMatrix();
        resultMatrix.setRows(matrix.getRows());
        resultMatrix.setCols(matrix.getCols());

        vector<double> rowA = matrix.getMatrix()[a-1];
        vector<double> rowB = matrix.getMatrix()[b-1];
        vector<double> tmpRow = rowA;
        newMatrix[a-1] = rowB;
        newMatrix[b-1] = tmpRow;

        resultMatrix.setMatrix(newMatrix);

        return resultMatrix;
    }

    /* Pomnozenie wiersza przez liczbe */
    Matrix multiplyRow(int row, double number) {
        Matrix resultMatrix;
        vector<vector<double> > newMatrix = matrix.getMatrix();
        int i;

        row--;

        for(i=0; i<matrix.getCols(); i++) {
            newMatrix[row][i] = matrix.getMatrix()[row][i] * number;
        }

        resultMatrix.setRows(matrix.getRows());
        resultMatrix.setCols(matrix.getCols());
        resultMatrix.setMatrix(newMatrix);

        return resultMatrix;
    }

    /* Dodanie wiersza A do wiersza B */
    Matrix addOneRowToAnother(int a, int b) {
        Matrix resultMatrix;
        vector<vector<double > > newMatrix = matrix.getMatrix();
        int i;

        a--;
        b--;

        for(i=0; i<matrix.getCols(); i++) {
            newMatrix[b][i] += newMatrix[a][i];
        }

        resultMatrix.setRows(matrix.getRows());
        resultMatrix.setCols(matrix.getCols());
        resultMatrix.setMatrix(newMatrix);

        return resultMatrix;
    }
};

#endif