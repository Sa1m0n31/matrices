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
/* Wyliczamy macierz odwrotna jako transponowana macierz dopelnien algebraicznych, podzielona przez wyznacznik */
Matrix SingleOperation::inverse() {
    int i, j;
    double det;
    Matrix pureMatrix, resultMatrix;
    SingleOperation matrixToTranspose;
    vector<vector<double> > invertedMatrix;
    vector<double> invertedRow;
    Matrix *errorMatrix = new Matrix(0); /* Macierz osobliwa - wyznacznik rowny 0 */
    Matrix *error2Matrix = new Matrix(-1); /* Macierz nie kwadratowa */

    /* 1. krok - wyliczamy wyznacznik */
    if(isSquare(this->getMatrix())) {
        det = this->determinant();
        if (det != 0) {
            /* 2. krok - dla kazdego elementu macierzy liczymy jego dopelnienie algebraiczne dzielone przez wyznacznik */
            for (i = 0; i < this->getMatrix().getRows(); i++) {
                invertedMatrix.push_back(invertedRow);
                for (j = 0; j < this->getMatrix().getCols(); j++) {
                    invertedMatrix[i].push_back(this->adjugate(i, j) / det);
                }
            }
            pureMatrix.setMatrix(invertedMatrix);
            pureMatrix.setRows(this->getMatrix().getRows());
            pureMatrix.setCols(this->getMatrix().getCols());

            matrixToTranspose.setMatrix(pureMatrix);

            /* 3. krok - transponujemy otrzymana macierz */
            resultMatrix = matrixToTranspose.transpose();

            return resultMatrix;
        }
        else {
            return *errorMatrix;
        }
    }
    else {
        return *error2Matrix;
    }
}

/* Wykreslanie k-tego wiersza i l-tej kolumny macierzy */
/* Metoda uzywana przy obliczaniu dopelnien algebraicznych */
Matrix SingleOperation::crossRowAndColumn(int k, int l) {
    Matrix resultMatrix;
    vector<vector<double> > newMatrix;
    vector<double> newRow;
    int i, j;

    /* Przepisywanie */
    for(i=0; i<matrix.getRows(); i++) {
        newMatrix.push_back(newRow);
        for(j=0; j<matrix.getCols(); j++) {
            newMatrix[i].push_back(matrix.getMatrix()[i][j]);
        }
    }

    /* Usuwanie */
    newMatrix.erase(newMatrix.begin() + k);
    for(i=0; i<matrix.getRows()-1; i++) {
        newMatrix[i].erase(newMatrix[i].begin() + l);
    }

    resultMatrix.setRows(matrix.getRows()-1);
    resultMatrix.setCols(matrix.getCols()-1);
    resultMatrix.setMatrix(newMatrix);

    return resultMatrix;
}

/* Dopelnienie algebraiczne elementu na pozycji i, j */
double SingleOperation::adjugate(int i, int j) {
    Matrix newMatrix;
    SingleOperation newSingle;

    newMatrix = this->crossRowAndColumn(i, j);
    newSingle.setMatrix(newMatrix);

    return pow(-1, i+j) * newSingle.determinant();
}

/* Wyliczanie wyznacznika */
/* Metoda: sprowadzamy macierz do postaci gornoschodkowej i obliczamy iloczyn elementow lezacych na przekatnej macierzy */
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
    }
    else {
        return -9999.9999; /* Blad */
    }
}

/* Wyliczanie sladu */
double SingleOperation::trace() {
    if(isSquare(this->getMatrix())) {
        int i, res = 0;
        for(i=0; i<this->getMatrix().getRows(); i++) {
            res += this->getMatrix().getMatrix()[i][i];
        }
        return res;
    }
    else return -9999.9999; /* Blad */
}

/* Wyznaczanie podmacierzy */
/* Zwraca macierz od wiersza rowsStart do wiersza rowsEnd-1 oraz od kolumny colsStart do kolumny colsEnd-1 */
Matrix SingleOperation::getSubmatrix(int rowsStart, int rowsEnd, int colsStart, int colsEnd) {
    Matrix resultMatrix;
    vector<vector<double> > newMatrix;
    vector<double> newRow;
    int i, j;
    Matrix *errorMatrix = new Matrix(0);

    /* Blad */
    if((rowsStart <= rowsEnd)||(colsStart <= colsEnd)) {
        return *errorMatrix;
    }

    rowsStart--;
    rowsEnd--;
    colsStart--;
    colsEnd--;

    /* Inicjalizacja */
    for(i=0; i<this->getMatrix().getRows(); i++) {
        newMatrix.push_back(newRow);
        for(j=0; j<this->getMatrix().getCols(); j++) {
            newMatrix[i].push_back(0);
        }
    }

    for(i=rowsStart; i<rowsEnd; i++) {
        newMatrix.push_back(newRow);
        for(j=colsStart; j<colsEnd; j++) {
            newMatrix[i-rowsStart][j-colsStart] = this->getMatrix().getMatrix()[i][j];
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