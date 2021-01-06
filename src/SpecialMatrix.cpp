#include<vector>
#include<iostream>
#include<cmath>

#include "SpecialMatrix.h"
#include "Matrix.h"

using namespace std;

/* Macierz Vandermonde'a - macierz, w ktorej kolejne kolumny sa kolejnymi potegami liczby z drugiej kolumny */
Matrix SpecialMatrix::getVandermondeMatrix() {
    int rows, cols, i, j;
    double number;
    vector<double> firstColumn;
    vector<vector<double> > vandermondeMatrix;
    Matrix resultMatrix;

    /* Input - wymiary */
    cout << "Liczba wierszy: ";
    cin >> rows;
    cout << "Liczba kolumn: ";
    cin >> cols;

    /* Inicjalizacja */
    for (i = 0; i < rows; i++) {
        vandermondeMatrix.push_back(firstColumn);
        for (j = 0; j < cols; j++) {
            vandermondeMatrix[i].push_back(1);
        }
    }

    /* Input - wspolaczynniki */
    cout << "Wspolczynniki w pierwszej kolumnie: ";
    for (i = 0; i < rows; i++) {
        cin >> number;
        firstColumn.push_back(number);
        vandermondeMatrix[i][1] = number;
    }

    /* Obliczanie kolejnych kolumn */
    for (i = 2; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            vandermondeMatrix[j][i] = pow(firstColumn[j], i);
        }
    }

    resultMatrix.setRows(rows);
    resultMatrix.setCols(cols);
    resultMatrix.setMatrix(vandermondeMatrix);

    return resultMatrix;
}

/* Macierz Teoplitza - macierz o takich samych elementach na danych diagonaliach */
Matrix SpecialMatrix::getToeplitzMatrix() {
    int i, j, k, l=1, u, n;
    double value;

    vector<double> row;
    vector<vector<double> > matrix;
    Matrix resultMatrix;

    cout << "Liczba kolumn i wierszy: ";
    cin >> n;

    /* Inicjalizacja */
    for(i=0; i<n; i++) {
        matrix.push_back(row);
        for(j=0; j<n; j++) {
            matrix[i].push_back(0);
        }
    }

    /* Wczytywanie diagonalii */
    /* Dolne i glowna diagonalia */
    for(i=0; i<n; i++) {
        cout << i+1 << ". diagonalia (od lewego dolnego rogu): ";
        cin >> value;
        for(j=0; j<l; j++) {
            matrix[n-i-1+j][j] = value;
        }
        l++;
    }
    /* Gorne diagonalia */
    l=3;
    k=1;
    for(i=0; i<n-1; i++) {
        cout << i+1+n << ". diagonalia (od lewego dolnego rogu): ";
        cin >> value;
        u=0;
        for(j=k; j<=l; j++) {
            matrix[u][j] = value;
            u++;
        }
        k++;
    }

    resultMatrix.setRows(n);
    resultMatrix.setCols(n);
    resultMatrix.setMatrix(matrix);

    return resultMatrix;
}

/* Macierz permutacji */
Matrix SpecialMatrix::getPermutationMatrix() {
    bool err;
    int i, j, n, pos;
    Matrix *errorMatrix = new Matrix(0);
    cout << "Liczba wierszy i kolumn: ";
    cin >> n;

    Matrix resultMatrix;
    vector<vector<double> > newMatrix;
    vector<double> newRow;

    /* Inicjalizacja */
    for(i=0; i<n; i++) {
        newMatrix.push_back(newRow);
        for(j=0; j<n; j++) {
            newMatrix[i].push_back(0);
        }
    }

    /* Input */
    for(i=0; i<n; i++) {
        cout << "Pozycja jedynki w " << i+1 << ". wierszu: ";
        cin >> pos;
        if(pos <= n) newMatrix[i][pos-1] = 1;
        else return *errorMatrix;
    }

    resultMatrix.setRows(n);
    resultMatrix.setCols(n);
    resultMatrix.setMatrix(newMatrix);

    return resultMatrix;
}
