#ifndef MATRIX_CPP
#define MATRIX_CPP

#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

class Matrix {
    /* ZMIENNE */
private:
    int rows;
    int cols;
    vector<vector<double> > matrix;

public:
    /* KONSTRUKTORY */
    Matrix() {

    }

    Matrix(int rows, int cols, vector<vector<double> > matrix = {{1, 1}, {1, 1}}) {
        this->rows = rows;
        this->cols = cols;
        this->matrix = matrix;
    }

    /* Getters and setters */
    int getRows() {
        return rows;
    }

    void setRows(int rows) {
        Matrix::rows = rows;
    }

    int getCols() const {
        return cols;
    }

    void setCols(int cols) {
        Matrix::cols = cols;
    }

    const vector<vector<double>> &getMatrix() const {
        return matrix;
    }

    void setMatrix(const vector<vector<double>> &matrix) {
        Matrix::matrix = matrix;
    }

    /* METODY */

    /* Wczytywanie macierzy */
    void loadMatrix() {
        int i, j;
        double number;
        vector<double> row;

        cout << "Liczba wierszy: ";
        cin >> rows;
        cout << "Liczba kolumn: ";
        cin >> cols;

        for(i=0; i<rows; i++) {
            cout << "Wczytaj wiersz " << i+1 << ": ";
            for(j=0; j<cols; j++) {
                cin >> number;
                row.push_back(number);
            }
            matrix.push_back(row);
            row.clear();
        }
        cout << "Macierz zostala wczytana" << endl;
    }

    /* Wypisywanie macierzy na ekran */
    void printMatrix() {
        int i, j;
        int printedMatrixRows = matrix.size();
        int printedMatrixCols = matrix[0].size();
        for(i=0; i<printedMatrixRows; i++) {
            for(j=0; j<printedMatrixCols; j++) {
                cout << setw(10) << matrix[i][j];
            }
            cout << endl;
        }
    }
};

#endif