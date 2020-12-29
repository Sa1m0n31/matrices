#include<cmath>

#include "SingleOperation.h"
#include "GaussianElimination.h"

using namespace std;

Matrix SingleOperation::getMatrix() {
    return matrix;
}

void SingleOperation::setMatrix(const Matrix &matrix) {
    SingleOperation::matrix = matrix;
}

/* Transponowanie macierzy */
Matrix SingleOperation::transpose() {
    Matrix result;
    vector<vector<double> > newMatrix;
    vector<double> newRow;
    int i, j;

    for(i=0; i<matrix.getCols(); i++) {
        newMatrix.push_back(newRow);
        for(j=0; j<matrix.getRows(); j++) {
            newMatrix[i].push_back(matrix.getMatrix()[j][i]);
        }
    }

    result.setRows(matrix.getCols());
    result.setCols(matrix.getRows());
    result.setMatrix(newMatrix);

    return result;
}

/* Wyliczanie macierzy odwrotnej */
Matrix SingleOperation::inverse(Matrix m) {
    return m;
}

/* Zwracanie macierzy z wykreslonym wierszem i kolumna */
Matrix SingleOperation::getMatrixForLaplaceTransform(Matrix m, int rowToDelete, int columnToDelete) {
    int i, j;
    rowToDelete--;
    columnToDelete--;
    Matrix resultMatrix;
    vector<vector<double> > newMatrix;
    vector<double> newRow;

    for(i=0; i<m.getRows(); i++) {
        newMatrix.push_back(newRow);
        for(j=0; j<m.getCols(); j++) {
            newMatrix[i].push_back(m.getMatrix()[i][j]);
        }
    }

    for(i=0; i<m.getRows(); i++) {
        newMatrix[i].erase(newMatrix[i].begin() + columnToDelete);
    }
    newMatrix.erase(newMatrix.begin()+rowToDelete);

    resultMatrix.setRows(m.getRows()-1);
    resultMatrix.setCols(m.getCols()-1);
    resultMatrix.setMatrix(newMatrix);

    return resultMatrix;
}

/* Wyliczanie wyznacznika */
/* Rozwiniecie Laplace'a wzgledem pierwszej kolumny */
double SingleOperation::determinant() {
    if(isSquare(matrix)) {
        int i;
        double det = 1;
        GaussianElimination gaussianElimination;
        gaussianElimination.setMatrix(matrix);

        Matrix upperTriangular = gaussianElimination.upperTriangular();

        for(i=0; i<upperTriangular.getCols(); i++) {
            det *= upperTriangular.getMatrix()[i][i];
        }
        return det;

        /*cout << "MACIERZ:" << endl;
        m.printMatrix();
        cout << endl;

        if(m.getRows() == 1) {
            return m.getMatrix()[0][0];
        }
        else {
            double res = 0;
            int i;

            for(i=0; i<m.getRows(); i++) {
                cout << "Element: " << m.getMatrix()[laplaceRow-1+i][0] << endl;
                res = (pow(-1, laplaceRow+1+i) * m.getMatrix()[laplaceRow-1+i][0] * determinant(getMatrixForLaplaceTransform(m, laplaceRow+i, 1), laplaceRow+i));
                cout << "result: " << res << endl;
            }

            return res;
        } */
    }
    else {
        return -9999.9999;
    }
}

/* Wyliczanie sladu */
double SingleOperation::trace(Matrix m) {
    if(isSquare(m)) {
        int i, res = 0;
        for(i=0; i<m.getRows(); i++) {
            res += m.getMatrix()[i][i];
        }
        return res;
    }
    else return 0;
}

/* Wyznaczanie podmacierzy */
/* Zwraca macierz od wiersza rowsStart do wiersza rowsEnd-1 oraz od kolumny colsStart do kolumny colsEnd-1 */
Matrix SingleOperation::getSubmatrix(Matrix m, int rowsStart, int rowsEnd, int colsStart, int colsEnd) {
    Matrix resultMatrix;
    vector<vector<double> > newMatrix;
    vector<double> newRow;
    int i, j;

    /* Obsluga bledow */
    if((rowsStart <= rowsEnd)||(colsStart <= colsEnd)) {
        return *errorMatrix;
    }

    rowsStart--;
    rowsEnd--;
    colsStart--;
    colsEnd--;

    for(i=rowsStart; i<rowsEnd; i++) {
        newMatrix.push_back(newRow);
        for(j=colsStart; j<colsEnd; j++) {
            newMatrix[i-rowsStart][j-colsStart] = m.getMatrix()[i][j];
        }
    }

    resultMatrix.setRows(rowsEnd - rowsStart);
    resultMatrix.setCols(colsEnd - colsStart);
    resultMatrix.setMatrix(newMatrix);

    return resultMatrix;
}

/* Sprawdzanie czy macierz jest kwadratowa */
bool SingleOperation::isSquare(Matrix m) {
    return m.getCols() == m.getRows();
}