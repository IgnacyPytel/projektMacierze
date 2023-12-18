//
// Created by pytlu on 18.12.2023.
//

#include "GaussWyborKolumny.h"
#include <iostream>
#include <algorithm>


int GaussWyborKolumny::znajdzMaksymalnyElement(int col) {
    double maxEl = std::abs(A[col][col]);
    int maxRow = col;
    for (int k = col + 1; k < A.size(); k++) {
        if (std::abs(A[k][col]) > maxEl) {
            maxEl = std::abs(A[k][col]);
            maxRow = k;
        }
    }
    return maxRow;
}


void GaussWyborKolumny::eliminacjaGaussa(int col) {
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


std::vector<double> GaussWyborKolumny::rozwiazUklad() {
    unsigned long long n = A.size();
    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i] / A[i][i];
        for (int k = i - 1; k >= 0; k--) {
            b[k] -= A[k][i] * x[i];
        }
    }
    return x;
}

void GaussWyborKolumny::rozwiaz() {
    unsigned long long n = A.size();

    for (int i = 0; i < n; i++) {

        int maxRow = znajdzMaksymalnyElement(i);
        std::swap(A[maxRow], A[i]);
        std::swap(b[maxRow], b[i]);

        eliminacjaGaussa(i);
    }


    std::vector<double> x = rozwiazUklad();


    for (int i = 0; i < n; i++) {
        std::cout << "x" << i << " = " << x[i] << std::endl;
    }
}
GaussWyborKolumny::GaussWyborKolumny(){
    //macierz A to macierz wartosci z X
    A = {{0, 0}, {0, 0}};
    //wektor b to wektor wartosci "rownosci"
    b = {0, 0};
}
GaussWyborKolumny::GaussWyborKolumny(const std::vector<std::vector<double>>& A, const std::vector<double>& b) {
    this->A = A;
    this->b = b;
}