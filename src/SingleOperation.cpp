#ifndef SINGLEOPERATION_CPP
#define SINGLEOPERATION_CPP

#include "./Matrix.cpp"

using namespace std;

class SingleOperation {
private:
    Matrix matrix;
public:
    const Matrix &getMatrix() const {
        return matrix;
    }

    void setMatrix(const Matrix &matrix) {
        SingleOperation::matrix = matrix;
    }

public:
    /* Transponowanie macierzy */
    Matrix transpose() {
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
    Matrix inverse(Matrix m) {
        return m;
    }

    /* Wyliczanie wyznacznika */
    double determinant(Matrix m) {
        if(isSquare(m)) {
            return 0;
        }
        else {
            return 1;
        }
    }

    /* Wyliczanie sladu */
    double trace(Matrix m) {
        return 0;
    }

    /* Wyznaczanie podmacierzy */
    Matrix getSubmatrix(Matrix m, int rows, int cols) {
        return m;
    }

    /* Sprawdzanie czy macierz jest kwadratowa */
    bool isSquare(Matrix m) {
        return m.getCols() == m.getRows();
    }
};


#endif