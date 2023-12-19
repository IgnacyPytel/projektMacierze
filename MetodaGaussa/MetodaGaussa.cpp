//
// Created by pytlu on 18.12.2023.
//

#include "MetodaGaussa.h"
#include <algorithm>
#include <iostream>

void MetodaGaussa::eliminacjaGaussa(int kolumna) {
    unsigned long long int rozmiarMacierzy = A.size();

    for (int k = kolumna + 1; k < rozmiarMacierzy; k++) {

        double c = -A[k][kolumna] / A[kolumna][kolumna];

        for (int j = kolumna; j < rozmiarMacierzy; j++) {
            if (kolumna == j) {

                A[k][j] = 0;

            } else {

                A[k][j] += c * A[kolumna][j];

            }
        }

        b[k] += c * b[kolumna];

    }
}

std::vector<double> MetodaGaussa::rozwiazUklad() {

    unsigned long long int rozmiarMacierzy = A.size();
    std::vector<double> x(rozmiarMacierzy);

    for (int i = rozmiarMacierzy - 1; i >= 0; i--) {

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
    unsigned long long int rozmiarMacierzy = A.size();

    for (int i = 0; i < rozmiarMacierzy; i++) {
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