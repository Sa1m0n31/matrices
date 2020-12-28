/* #include "../main.cpp"

/* Typy macierzy specjalnych:

class SpecialMatrix {
    Macierz Vandermonde'a
    static Matrix getVandermondeMatrix() {
        int rows, cols, i, j;
        double number;
        vector<double> firstColumn;
        vector<vector<double> > vandermondeMatrix;
        Matrix resultMatrix;

        Input - wymiary
        cout << "Liczba wierszy: ";
        cin >> rows;
        cout << "Liczba kolumn: ";
        cin >> cols;

        /* Initialization
        for(i=0; i<rows; i++) {
            vandermondeMatrix.push_back(firstColumn);
            for(j=0; j<cols; j++) {
                vandermondeMatrix[i].push_back(1);
            }
        }

        /* Input - wspolaczynniki
        cout << "Wspolczynniki w pierwszej kolumnie: ";
        for(i=0; i<rows; i++) {
            cin >> number;
            firstColumn.push_back(number);
            vandermondeMatrix[i][1] = number;
        }

        /* Obliczanie kolejnych kolumn
        for(i=2; i<cols; i++) {
            for(j=0; j<rows; j++) {
                vandermondeMatrix[j][i] = pow(firstColumn[j], i);
            }
        }

        resultMatrix.setRows(rows);
        resultMatrix.setCols(cols);
        resultMatrix.setMatrix(vandermondeMatrix);

        return resultMatrix;
    }
}; */
