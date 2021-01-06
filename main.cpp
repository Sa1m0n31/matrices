#include<iostream>
#include "src/GaussianElimination.h"
#include "src/Matrix.h"
#include "src/SingleOperation.h"
#include "src/MultipleOperation.h"
#include "src/SpecialMatrix.h"

using namespace std;

/* 1. Dodawanie macierzy */
void dodawanieMacierzy() {
    Matrix matrixA, matrixB, result;
    MultipleOperation add;

    /* Wczytywanie dwoch macierzy do dodawania */
    cout << "MACIERZ A" << endl;
    matrixA.loadMatrix();
    cout << "MACIERZ B" << endl;
    matrixB.loadMatrix();

    add.setA(matrixA);
    add.setB(matrixB);

    result = add.addMatrices();
    if(result.getRows() == 0) {
        cout << "Niepoprawne wymiary macierzy" << endl;
    }
    else {
        cout << "WYNIK DODAWANIA MACIERZY" << endl;
        result.printMatrix();
    }
}

/* 2. Odejmowanie macierzy */
void odejmowanieMacierzy() {
    Matrix matrixA, matrixB, result;
    MultipleOperation sub;

    /* Wczytywanie dwoch macierzy do odejmowania */
    cout << "MACIERZ A" << endl;
    matrixA.loadMatrix();
    cout << "MACIERZ B" << endl;
    matrixB.loadMatrix();

    sub.setA(matrixA);
    sub.setB(matrixB);

    result = sub.subtractMatrices();
    if(result.getRows() == 0) {
        cout << "Niepoprawne wymiary macierzy" << endl;
    }
    else {
        cout << "WYNIK ODEJMOWANIA MACIERZY" << endl;
        result.printMatrix();
    }
}

/* 3. Mnozenie macierzy */
void mnozenieMacierzy() {
    Matrix matrixA, matrixB, result;
    MultipleOperation multiply;

    /* Wczytywanie dwoch macierzy do mnozenia */
    cout << "MACIERZ A" << endl;
    matrixA.loadMatrix();
    cout << "MACIERZ B" << endl;
    matrixB.loadMatrix();

    multiply.setA(matrixA);
    multiply.setB(matrixB);

    result = multiply.multiplyMatrices();
    if(result.getRows() == 0) {
        cout << "Niepoprawne wymiary macierzy" << endl;
    }
    else {
        cout << "WYNIK MNOZENIA MACIERZY" << endl;
        result.printMatrix();
    }
}

/* 4. Wyznacznik macierzy kwadratowej */
void wyznacznikMacierzy() {
    double det;
    SingleOperation singleOperation;
    Matrix matrix;

    matrix.loadSquareMatrix();
    singleOperation.setMatrix(matrix);

    det = singleOperation.determinant();

    cout << "WYZNACZNIK WYNOSI: " << det << endl;
}

/* 5. Wyznaczanie sladu macierzy kwadratowej */
void sladMacierzy() {
    Matrix matrix;
    SingleOperation singleOperation;
    double trc;

    /* Wczytywanie macierzy */
    matrix.loadSquareMatrix();
    singleOperation.setMatrix(matrix);

    trc = singleOperation.trace();
    cout << "SLAD WYNOSI: " << trc << endl;

}

/* 6. Transponowanie macierzy */
void transponowanieMacierzy() {
    Matrix matrix, result;
    SingleOperation singleOperation;

    /* Wczytywanie macierzy */
    matrix.loadMatrix();
    singleOperation.setMatrix(matrix);

    cout << "MACIERZ TRANSPONOWANA" << endl;
    singleOperation.transpose().printMatrix();
}

/* 7. Obliczanie macierzy odwrotnej */
void macierzOdwrotna() {
    Matrix matrix, result;
    SingleOperation singleOperation;

    /* Wczytywanie macierzy */
    matrix.loadSquareMatrix();
    singleOperation.setMatrix(matrix);

    result = singleOperation.inverse();
    if(result.getRows() == 0) {
        cout << "Macierz osoblica (det A = 0) - macierz odwrotna nie istnieje" << endl;
    }
    else {
        cout << "MACIERZ ODWROTNA" << endl;
        result.printMatrix();
    }
}

/* 8. Wyznaczanie podmacierzy */
void podmacierz() {
    int rowStart, rowEnd, colStart, colEnd;
    Matrix matrix, result;
    SingleOperation singleOperation;

    /* Wczytywanie macierzy */
    matrix.loadMatrix();
    singleOperation.setMatrix(matrix);

    /* Wczytywanie informacji o podmacierzy */
    cout << "PODAJ INFORMACJE O NOWE PODMACIERZY" << endl;
    cout << "Od wiersza: ";
    cin >> rowStart;
    cout << "Do wiersza: ";
    cin >> rowEnd;
    cout << "Od kolumny: ";
    cin >> colStart;
    cout << "Do kolumny: ";
    cin >> colEnd;

    result = singleOperation.getSubmatrix(rowStart, rowEnd, colStart, colEnd);
    if(result.getRows() == 0) {
        cout << "Bledne dane wejsciowe" << endl;
    }
    else {
        cout << "PODMACIERZ" << endl;
        result.printMatrix();
    }
}

/* 9. Wyznaczanie macierzy Vandermonde'a */
void macierzVandermonde() {
    Matrix vandermonde;

    vandermonde = SpecialMatrix::getVandermondeMatrix();

    cout << "MACIERZ VANDERMONDE'A" << endl;
    vandermonde.printMatrix();
}

/* 10. Wyznaczanie macierzy Toeplitza */
void macierzToeplitza() {
    Matrix toeplitz;

    toeplitz = SpecialMatrix::getToeplitzMatrix();

    cout << "MACIERZ TOEPLITZA" << endl;
    toeplitz.printMatrix();
}

/* 11. Wyznaczanie macierzy permutacji */
void macierzPermutacji() {
    Matrix perm;

    perm = SpecialMatrix::getPermutationMatrix();

    cout << "MACIERZ PERMUTACJI" << endl;
    perm.printMatrix();
}

/* 12. Obliczanie ukladu rownan liniowych metoda eliminacji Gaussa */
void gauss() {
    Matrix matrix, res;
    GaussianElimination gaussianElimination;

    matrix.loadGaussianEliminationMatrix();
    gaussianElimination.setMatrix(matrix);

    res = GaussianElimination::fullReducedEchelon(GaussianElimination::reducedEchelon(gaussianElimination.upperTriangular()));
    cout << "ROZWIAZANIE" << endl;
    res.printMatrix();
}


int main() {
    /* Zmienne */
    int n = 1;
    char dec;

    /* Menu glowne */
    while(n != 0) {
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
        cout << "(10) Wczytywanie macierzy Toeplitza" << endl;
        cout << "(11) Wczytywanie macierzy permutacji" << endl;
        cout << "(12) Rozwiazywanie ukladu rownan liniowych metoda eliminacji Gaussa" << endl;
        cout << "Wybierz co chcesz zrobic:" << endl;

        cin >> n;
            switch(n) {
                case 1: // Dodawanie macierzy
                    dodawanieMacierzy();
                    break;
                case 2: // Odejmowanie macierzy
                    odejmowanieMacierzy();
                    break;
                case 3: // Mnozenie macierzy
                    mnozenieMacierzy();
                    break;
                case 4: // Obliczanie wyznacznika macierzy kwadratowej
                    wyznacznikMacierzy();
                    break;
                case 5: // Obliczanie sladu macierzy kwadratowej
                    sladMacierzy();
                    break;
                case 6: // Transponowanie macierzy
                    transponowanieMacierzy();
                    break;
                case 7: // Wyznaczanie macierzy odwrotnej
                    macierzOdwrotna();
                    break;
                case 8: // Wyznaczanie podmacierzy
                    podmacierz();
                    break;
                case 9: // Wyznaczanie macierzy Vandermonde'a
                    macierzVandermonde();
                    break;
                case 10: // Wczytywanie macierzy Toeplitza
                    macierzToeplitza();
                    break;
                case 11: // Wyznaczanie macierzy permutacji
                    macierzPermutacji();
                    break;
                case 12: // Rozwiazywanie ukladu rownan liniowych metoda eliminacji Gaussa
                    gauss();
                    break;
                default:
                    cout << "Podana opcja nie znajduje sie na liscie" << endl;
                    break;

            }
            cout << "Wrocic do menu glownego? (t/n)";
            cin >> dec;
            if(dec == 'n') break;
    }

    return 0;
}