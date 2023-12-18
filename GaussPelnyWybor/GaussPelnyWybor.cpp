//
// Created by pytlu on 18.12.2023.
//

#include "GaussPelnyWybor.h"
#include <algorithm>
#include <iostream>


std::pair<int, int> GaussPelnyWybor::znajdzPivot(int start) {
    double maxEl = std::abs(A[start][start]);
    int maxRow = start;
    int maxCol = start;
    for (int k = start; k < A.size(); k++) {
        for (int j = start; j < A.size(); j++) {
            if (std::abs(A[k][j]) > maxEl) {
                maxEl = std::abs(A[k][j]);
                maxRow = k;
                maxCol = j;
            }
        }
    }
    return {maxRow, maxCol};
}


void GaussPelnyWybor::zamienWiersze(int wiersz1, int wiersz2) {
    std::swap(A[wiersz1], A[wiersz2]);
    std::swap(b[wiersz1], b[wiersz2]);
}


void GaussPelnyWybor::zamienKolumny(int kolumna1, int kolumna2) {
    for (auto & i : A) {
        std::swap(i[kolumna1], i[kolumna2]);
    }
}


void GaussPelnyWybor::eliminacjaGaussa(int col) {
    unsigned long long n = A.size();
    for (int k = col + 1; k < n; k++) {
        double c = -A[k][col] / A[col][col];
        for (int j = col; j < n; j++) {
            if (col == j) {
                A[k][j] = 0;
            } else {
                A[k][j] += c * A[col][j];
            }
        }
        b[k] += c * b[col];
    }
}
std::vector<double> GaussPelnyWybor::rozwiazUklad() {
    unsigned long long int n = A.size();
    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i] / A[i][i];
        for (int k = i - 1; k >= 0; k--) {
            b[k] -= A[k][i] * x[i];
        }
    }
    return x;
}

void GaussPelnyWybor::rozwiaz() {
    unsigned long long int n = A.size();
    std::vector<int> P(n);
    for (int i = 0; i < n; i++) {
        P[i] = i;
    }

    for (int i = 0; i < n; i++) {

        auto [maxRow, maxCol] = znajdzPivot(i);
        zamienWiersze(maxRow, i);
        zamienKolumny(maxCol, i);
        std::swap(P[maxCol], P[i]);


        eliminacjaGaussa(i);
    }


    std::vector<double> x = rozwiazUklad();


    std::vector<double> y = x;
    for (int i = 0; i < n; i++) {
        x[P[i]] = y[i];
    }


    for (int i = 0; i < n; i++) {
        std::cout << "x" << i << " = " << x[i] << std::endl;
    }
}
GaussPelnyWybor::GaussPelnyWybor() {
    //macierz A to macierz wartosci z X
    A = {{0, 0}, {0, 0}};
    //wektor b to wektor wartosci "rownosci"
    b = {0, 0};
}
GaussPelnyWybor::GaussPelnyWybor(const std::vector<std::vector<double>>& A, const std::vector<double>& b) {
    this->A = A;
    this->b = b;
}
