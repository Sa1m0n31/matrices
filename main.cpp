#include<iostream>
#include<vector>
#include<iomanip>
#include<limits>
#include<cmath>
#include "src/GaussianElimination.h"
#include "src/Matrix.h"

using namespace std;

int main() {
    /* Zmienne */
    int n = 1;
    vector<double> row;
    vector<vector<double> > vec;
    vec.push_back(row);
    vec.push_back(row);
    vec[0].push_back(2);
    vec[0].push_back(4);
    vec[1].push_back(6);
    vec[1].push_back(8);

    vector<vector<double> > vec2;
    vec2.push_back(row);
    vec2.push_back(row);
    vec2.push_back(row);
    vec2.push_back(row);
    vec2[0].push_back(4);
    vec2[0].push_back(-2);
    vec2[0].push_back(4);
    vec2[0].push_back(-2);
    vec2[0].push_back(8);
    vec2[1].push_back(3);
    vec2[1].push_back(1);
    vec2[1].push_back(4);
    vec2[1].push_back(2);
    vec2[1].push_back(7);
    vec2[2].push_back(2);
    vec2[2].push_back(4);
    vec2[2].push_back(2);
    vec2[2].push_back(1);
    vec2[2].push_back(10);
    vec2[3].push_back(2);
    vec2[3].push_back(-2);
    vec2[3].push_back(4);
    vec2[3].push_back(2);
    vec2[3].push_back(2);

    GaussianElimination gaussianElimination;
    /* MultipleOperation operation;
    SingleOperation singleOperation; */
    Matrix *matrixA = new Matrix(2, 2, vec);
    Matrix *matrixB = new Matrix(2, 2, vec);
    Matrix *matrixC = new Matrix(4, 5, vec2);
    Matrix matrixD;

    matrixA->printMatrix();

    //*matrixA = gaussianElimination.switchRows(1, 2);
    //*matrixA = gaussianElimination.multiplyRow(2, 5);
    //*matrixA = gaussianElimination.addOneRowToAnother(1, 2);


    /* Menu glowne */
    /*
    while(n != 0) {
        cout << "Wybierz co chcesz zrobic:" << endl;
        cout << "(0) Wyjdz z programu" << endl;
        cout << "(1) Dodawanie macierzy" << endl;
        cout << "(2) Odejmowanie macierzy" << endl;
        cout << "(3) Mnozenie macierzy" << endl;
        cout << "(4) Obliczanie wyznacznika macierzy kwadratowej" << endl;
        cout << "(5) Obliczanie sladu macierzy kwadratowej" << endl;
        cout << "(6) Transponowanie macierzy" << endl;
        cout << "(7) Obliczanie macierzy odwrotnej" << endl;
        cout << "(8) Wyznaczenie podmacierzy" << endl;
        cout << "(9) Wczytywanie macierzy Vandermonde'a" << endl;
        cout << "(10) Rozwiazywanie ukladu rownan liniowych" << endl;

        cin >> n;
        if(n != 9) {
            switch(n) {
                case 1: // Dodawanie macierzy
                    break;
                case 2: // Odejmowanie macierzy
                    break;
                case 3: // Obliczanie wyznacznika macierzy kwadratowej
                    break;
                case 4: // Obliczanie sladu macierzy kwadratowej
                    break;
                default:
                    break;

            }
        }
        else if(n == 9) {

        }
    }
     */

    return 0;
}