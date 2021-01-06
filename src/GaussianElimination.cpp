/*
 * Klasa odpowiedzialna za operacje elementarne, wykorzystywane w Metodzie Eliminacji Gaussa
 */

#include<vector>
#include<iostream>

#include "GaussianElimination.h"

GaussianElimination::GaussianElimination() {

}

GaussianElimination::GaussianElimination(Matrix matrix) {
    this->matrix = matrix;
    this->row1 = {-9999.9999, -9999.9999};
    this->row2 = {-9999.9999, -9999.9999};
    this->matrixErr = { row1, row2 };
    this->errorMatrix = new Matrix(2, 2, matrixErr);
}

Matrix GaussianElimination::getMatrix() {
    return matrix;
}

void GaussianElimination::setMatrix(const Matrix &matrix) {
    GaussianElimination::matrix = matrix;
}

/* METHODS */

/* Zamiana dwoch wierszy */
Matrix GaussianElimination::switchRows(int a, int b) {
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
Matrix GaussianElimination::multiplyRow(int row, double number) {
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
Matrix GaussianElimination::addOneRowToAnother(int a, int b) {
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

/* Upper triangular */
/* Eliminacja Gaussa - dziala jesli zaden z elementow na przekatnej nie jest ani nie bedzie 0 */
Matrix GaussianElimination::upperTriangular() {
    Matrix upperTriangularMatrix;
    vector<vector<double> > copyMatrix = matrix.getMatrix();
    int i, j, l, k = 1;
    double divideBy, mnoznik;
    Matrix errorMatrix;

    for(i=0; i<matrix.getRows(); i++) {
        divideBy = copyMatrix[i][i];
        if(divideBy == 0) {
            cout << "ERRROR MATRIX";
            return errorMatrix;
        }

        for(j=k; j<matrix.getRows(); j++) {
            mnoznik = -copyMatrix[j][i] / divideBy;
            for(l=0; l<matrix.getCols(); l++) {
                copyMatrix[j][l] += copyMatrix[i][l] * mnoznik;
            }
        }
        k++;
    }

    upperTriangularMatrix.setRows(copyMatrix.size());
    upperTriangularMatrix.setCols(copyMatrix[0].size());
    upperTriangularMatrix.setMatrix(copyMatrix);
    return upperTriangularMatrix;
}

/* Jedynki w pierwszych kolumnach */
Matrix GaussianElimination::reducedEchelon(Matrix matrix) {
    Matrix resultMatrix;
    int i, j, k = 0;
    double mnoznik;
    vector<vector<double> > newMatrix;
    vector<double> newRow;

    /* Inicjalizacja */
    for(i=0; i<matrix.getRows(); i++) {
        newMatrix.push_back(newRow);
        for(j=0; j<matrix.getCols(); j++) {
            newMatrix[i].push_back(matrix.getMatrix()[i][j]);
        }
    }

    /* Pierwszy niezerowy wyraz w wierszu - jedynka */
    for(i=0; i<matrix.getRows(); i++) {
        mnoznik = 1 / matrix.getMatrix()[i][k];
        for(j=0; j<matrix.getCols(); j++) {
            newMatrix[i][j] *= mnoznik;
            if(newMatrix[i][j] == -0) newMatrix[i][j] = 0;
        }
        k++;
    }

    resultMatrix.setRows(matrix.getRows());
    resultMatrix.setCols(matrix.getCols());
    resultMatrix.setMatrix(newMatrix);

    return resultMatrix;
}

Matrix GaussianElimination::fullReducedEchelon(Matrix matrix) {
    Matrix resultMatrix;
    int i, j, k = 0;
    double mnoznik;
    vector<vector<double> > newMatrix;
    vector<double> newRow;

    /* Inicjalizacja */
    for(i=0; i<matrix.getRows(); i++) {
        newMatrix.push_back(newRow);
        for(j=0; j<matrix.getCols(); j++) {
            newMatrix[i].push_back(matrix.getMatrix()[i][j]);
        }
    }

    /* Redukcja */
    for(i=matrix.getRows()-1; i>0; i--) {
        /* Mnozymy kolumne i-ta i ostatnia kolumne kazdego wiersza powyzej */
        for(j=i-1; j>=0; j--) {
            mnoznik = -newMatrix[j][i];
            /*cout << "Mnoznik = " << mnoznik << endl;
            cout << "Dodajemy do " << newMatrix[j][i] << " to: " << newMatrix[i][i] * mnoznik << endl;
            cout << "Dodajemy do " << newMatrix[j][matrix.getCols()-1] << " to: " << newMatrix[i][matrix.getCols()-1] * mnoznik << endl;
            */
            newMatrix[j][i] += newMatrix[i][i] * mnoznik;
            newMatrix[j][matrix.getCols()-1] += newMatrix[i][matrix.getCols()-1] * mnoznik;
        }
    }

    resultMatrix.setMatrix(newMatrix);
    resultMatrix.setRows(matrix.getRows());
    resultMatrix.setCols(matrix.getCols());

    return resultMatrix;
}

Matrix GaussianElimination::resolveSystemOfLinearEquations() {
    return fullReducedEchelon(reducedEchelon(this->upperTriangular()));
}

