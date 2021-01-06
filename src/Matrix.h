#ifndef UNTITLED7_MATRIX_H
#define UNTITLED7_MATRIX_H

#include<vector>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    vector<vector<double> > matrix;

public:
    /* KONSTRUKTORY */
    Matrix();
    Matrix(int rows, int cols = 0);
    Matrix(int rows, int cols, vector<vector<double> > matrix = {{1, 1}, {1, 1}});

    /* Getters and setters */
    int getRows();
    void setRows(int rows);
    int getCols() const;
    void setCols(int cols);
    const vector<vector<double>> getMatrix() const;
    void setMatrix(const vector<vector<double>> &matrix);

    /* METODY */
    void loadMatrix();
    void loadSquareMatrix();
    void loadGaussianEliminationMatrix();
    void printMatrix();
};

#endif //UNTITLED7_MATRIX_H
