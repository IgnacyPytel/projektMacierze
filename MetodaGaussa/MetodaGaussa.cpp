//
// Created by pytlu on 18.12.2023.
//

#include "MetodaGaussa.h"
#include <algorithm>
#include <iostream>

void MetodaGaussa::eliminacjaGaussa(int col) {
    int n = A.size();
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

std::vector<double> MetodaGaussa::rozwiazUklad() {
    int n = A.size();
    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i] / A[i][i];
        for (int k = i - 1; k >= 0; k--) {
            b[k] -= A[k][i] * x[i];
        }
    }
    return x;
}

void MetodaGaussa::wypiszRozwiazanie(const std::vector<double>& x) {
    for (int i = 0; i < x.size(); i++) {
        std::cout << "x" << i << " = " << x[i] << std::endl;
    }
}

void MetodaGaussa::rozwiaz() {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        eliminacjaGaussa(i);
    }

    std::vector<double> x = rozwiazUklad();

    wypiszRozwiazanie(x);
}
MetodaGaussa::MetodaGaussa(){
    //macierz A to macierz wartosci z X
    A = {{0, 0}, {0, 0}};
    //wektor b to wektor wartosci "rownosci"
    b = {0, 0};
}
MetodaGaussa::MetodaGaussa(const std::vector<std::vector<double>>& A, const std::vector<double>& b) {
    this->A = A;
    this->b = b;
}