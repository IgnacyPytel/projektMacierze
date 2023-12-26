//
// Created by pytlu on 18.12.2023.
//

#include "GaussPodstawowy.h"
#include <algorithm>
#include <iostream>

void GaussPodstawowy::daneTestowePodstawowy(std::vector<std::vector<double>>& A,
                                            std::vector<double>& b) {
    //uklad rownan
    A = {{2, -2, -2},
         {5, 2, 3},
         {-1, 3, 4}};

    //wektor wyrazow wolnych
    b = {-2, 8, 4};
}

GaussPodstawowy::GaussPodstawowy(const std::vector<std::vector<double>>& A,
                                 const std::vector<double>& b) {
    this->A = A;
    this->b = b;
}

void GaussPodstawowy::wypiszMacierz() const {
    for (const auto& row : A) {
        for (const auto& element : row) {

            std::cout << element << "\t";

        }
        std::cout << '\n';
    }
}

void GaussPodstawowy::wypiszRozwiazanie(const std::vector<double>& x) {
    for (int i = 0; i < x.size(); i++) {

        std::cout << "x" << i << " = " << x[i] << std::endl;

    }
}

void GaussPodstawowy::eliminacjaGaussa(int kolumna) {

    unsigned long long rozmiarMacierzy = A.size();

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


std::vector<double> GaussPodstawowy::rozwiazUklad() {

    unsigned long long rozmiarMacierzy = A.size();
    std::vector<double> x(rozmiarMacierzy);

    for (int i = rozmiarMacierzy - 1; i >= 0; i--) {

        x[i] = b[i] / A[i][i];

        for (int k = i - 1; k >= 0; k--) {

            b[k] -= A[k][i] * x[i];

        }
    }
    return x;
}


void GaussPodstawowy::rozwiaz() {

    unsigned long long rozmiarMacierzy = A.size();


    for (int i = 0; i < rozmiarMacierzy; i++) {

        eliminacjaGaussa(i);
        std::cout << "Krok " << i+1 << ": " << std::endl;
        wypiszMacierz();
    }

    std::vector<double> x = rozwiazUklad();

    wypiszRozwiazanie(x);
}
