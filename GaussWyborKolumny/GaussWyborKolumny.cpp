//
// Created by pytlu on 18.12.2023.
//

#include "GaussWyborKolumny.h"
#include <iostream>
#include <algorithm>


GaussWyborKolumny::GaussWyborKolumny(){
    //macierz A to macierz wartosci z X
    A = {{0, 0}, {0, 0}};
    //wektor b to wektor wartosci "rownosci"
    b = {0, 0};
}

GaussWyborKolumny::GaussWyborKolumny(const std::vector<std::vector<double>>& A,
                                     const std::vector<double>& b) {
    this->A = A;
    this->b = b;
}

int GaussWyborKolumny::znajdzMaksymalnyElement(int kolumna) {

    double maxElement = std::abs(A[kolumna][kolumna]);
    int indeksMaksymalnegoElementu = kolumna;

    for (int k = kolumna + 1; k < A.size(); k++) {
        if (std::abs(A[k][kolumna]) > maxElement) {

            maxElement = std::abs(A[k][kolumna]);
            indeksMaksymalnegoElementu = k;

        }
    }
    return indeksMaksymalnegoElementu;
}

void GaussWyborKolumny::wypiszRozwiazanie(const std::vector<double>& x) {
    for (int i = 0; i < x.size(); i++) {
        std::cout << "x" << i << " = " << x[i] << std::endl;
    }
}


void GaussWyborKolumny::eliminacjaGaussa(int kolumna) {
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


std::vector<double> GaussWyborKolumny::rozwiazUklad() {
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

void GaussWyborKolumny::rozwiaz() {
    unsigned long long rozmiarMacierzy = A.size();

    for (int i = 0; i < rozmiarMacierzy; i++) {
        if (std::abs(A[i][i]) <= epsilon) {
            throw std::runtime_error("Element na glownej przekatnej jest rowny zero");
        }
    }

    for (int i = 0; i < rozmiarMacierzy; i++) {

        int maxRow = znajdzMaksymalnyElement(i);
        std::swap(A[maxRow], A[i]);
        std::swap(b[maxRow], b[i]);

        eliminacjaGaussa(i);
    }


    std::vector<double> x = rozwiazUklad();
    wypiszRozwiazanie(x);

}
