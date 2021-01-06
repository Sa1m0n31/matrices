#include<iostream>
#include<vector>
#include<iomanip>

#include "Matrix.h"

using namespace std;

/* Konstruktor bez argumentow */
Matrix::Matrix() {

}

/* Konstruktor z dwoma argumentami - przydatny to tworzenia macierzy oznaczajacej blad */
Matrix::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
}

/* Konstruktor z trzema argumentami */
Matrix::Matrix(int rows, int cols, vector<vector<double> > matrix) {
    this->rows = rows;
    this->cols = cols;
    this->matrix = matrix;
}

/* Gettery i settery */
int Matrix::getRows() {
    return rows;
}

void Matrix::setRows(int rows) {
    Matrix::rows = rows;
}

int Matrix::getCols() const {
    return cols;
}

void Matrix::setCols(int cols) {
    Matrix::cols = cols;
}

const vector<vector<double> > Matrix::getMatrix() const {
    return matrix;
}

void Matrix::setMatrix(const vector<vector<double> > &matrix) {
    Matrix::matrix = matrix;
}

/* Wczytywanie macierzy */
void Matrix::loadMatrix() {
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

/* Wczytywanie macierzy kwadratowej */
void Matrix::loadSquareMatrix() {
    int i, j;
    double number;
    vector<double> row;

    cout << "Liczba wierszy i kolumn: ";
    cin >> rows;

    this->setCols(this->getRows());

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

/* Wczytywanie macierzy rozszerzonej ukladu rownan liniowych (o n wierszach i n+1 kolumnach) */
void Matrix::loadGaussianEliminationMatrix() {
    int i, j;
    double number;
    vector<double> row;

    cout << "Liczba niewiadomych: ";
    cin >> rows;

    this->setCols(this->getRows() + 1);

    for(i=0; i<rows; i++) {
        cout << "Wczytaj " << i+1 << ". rownanie (" << rows << ". wspolczynnikow i jeden wyraz wolny): ";
        for(j=0; j<cols; j++) {
            cin >> number;
            row.push_back(number);
        }
        matrix.push_back(row);
        row.clear();
    }
    cout << "Macierz rozszerzona ukladu rownan liniowych zostala wczytana" << endl;
}

/* Wypisywanie macierzy na ekran */
void Matrix::printMatrix() {
        int i, j;
        int printedMatrixRows = matrix.size();
        int printedMatrixCols = matrix[0].size();
        for(i=0; i<printedMatrixRows; i++) {
            for(j=0; j<printedMatrixCols; j++) {
                cout << setw(10) << fixed << setprecision(4) << matrix[i][j];
            }
            cout << endl;
        }
}