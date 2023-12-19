//
// Created by pytlu on 18.12.2023.
//

#include "GaussPelnyWybor.h"
#include <algorithm>
#include <iostream>


std::pair<int, int> GaussPelnyWybor::znajdzPivot(int poczatek) {

    double maxElement = std::abs(A[poczatek][poczatek]);
    int indeksMaksymalnegoElementuWiersza = poczatek;
    int indeksMaksymalnegoElementuKolumny = poczatek;

    for (int k = poczatek; k < A.size(); k++) {
        for (int j = poczatek; j < A.size(); j++) {
            if (std::abs(A[k][j]) > maxElement) {

                maxElement = std::abs(A[k][j]);

                indeksMaksymalnegoElementuWiersza = k;

                indeksMaksymalnegoElementuKolumny = j;

            }
        }
    }
    return {indeksMaksymalnegoElementuWiersza, indeksMaksymalnegoElementuKolumny};
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


void GaussPelnyWybor::eliminacjaGaussa(int kolumna) {
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
std::vector<double> GaussPelnyWybor::rozwiazUklad() {

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

void GaussPelnyWybor::rozwiaz() {

    unsigned long long int rozmiarMacierzy = A.size();
    std::vector<int> P(rozmiarMacierzy);

    for (int i = 0; i < rozmiarMacierzy; i++) {

        P[i] = i;

    }

    for (int i = 0; i < rozmiarMacierzy; i++) {

        auto [indeksMaksymalnegoElementuWiersza, indeksMaksymalnegoElementuKolumny] = znajdzPivot(i);

        zamienWiersze(indeksMaksymalnegoElementuWiersza, i);
        zamienKolumny(indeksMaksymalnegoElementuKolumny, i);
        std::swap(P[indeksMaksymalnegoElementuKolumny], P[i]);


        eliminacjaGaussa(i);
    }


    std::vector<double> x = rozwiazUklad();
    std::vector<double> y = x;

    for (int i = 0; i < rozmiarMacierzy; i++) {

        x[P[i]] = y[i];

    }


    for (int i = 0; i < rozmiarMacierzy; i++) {

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
