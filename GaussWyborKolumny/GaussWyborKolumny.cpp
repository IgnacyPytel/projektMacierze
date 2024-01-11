

#include "GaussWyborKolumny.h"
#include <iostream>
#include <algorithm>


void GaussWyborKolumny::daneTestoweKolumny(std::vector<std::vector<double>>& A,
                                           std::vector<double>& b) {
    //uklad rownan
    A = {{1, 1, 1},
         {2, 1, 5},
         {1, -1, -1}};

    //wektor wyrazow wolnych
    b = {1, 0, 0};
}

GaussWyborKolumny::GaussWyborKolumny(const std::vector<std::vector<double>>& A,
                                     const std::vector<double>& b) {
    this->A = A;
    this->b = b;
}

void GaussWyborKolumny::wypiszMacierz() const {
    for (const auto& wiersz : A) {
        for (const auto& element : wiersz) {

            std::cout << element << "\t";

        }
        std::cout << '\n';
    }
}

int GaussWyborKolumny::znajdzMaksymalnyElement(int kolumna) {

    double maxElementKolumna = std::abs(A[kolumna][kolumna]);
    int indeksMaksymalnegoElementu = kolumna;

    for (int k = kolumna + 1; k < A.size(); k++) {
        if (std::abs(A[k][kolumna]) > maxElementKolumna) {

            maxElementKolumna = std::abs(A[k][kolumna]);
            indeksMaksymalnegoElementu = k;

        }
    }
    std::cout << "Maksymalny element: " << maxElementKolumna << std::endl;
    return indeksMaksymalnegoElementu;
}

void GaussWyborKolumny::wypiszRozwiazanie(const std::vector<double>& x) {
    for (int i = 0; i < x.size(); i++) {
        std::cout << "x" << i+1 << " = " << x[i] << std::endl;
    }
}


void GaussWyborKolumny::eliminacjaGaussa(int kolumna) {
    unsigned long long rozmiarMacierzy = A.size();

    for (int k = kolumna + 1; k < rozmiarMacierzy; k++) {

        double p = -A[k][kolumna] / A[kolumna][kolumna];

        for (int j = kolumna; j < rozmiarMacierzy; j++) {
            if (kolumna == j) {

                A[k][j] = 0;

            } else {

                A[k][j] += p * A[kolumna][j];

            }
        }

        b[k] += p * b[kolumna];

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
    // sprawdzanie zgodnie z zalozeniem uzywajac epsilona

    for (int i = 0; i < rozmiarMacierzy; i++) {
        if (std::abs(A[i][i]) < epsilon) {
            std::cout << "Uwaga: Element na glownej przekatnej jest rowny zero w kroku " << i+1 << std::endl;
            throw std::runtime_error("Element na glownej przekatnej jest rowny zero");
        }
    }

    for (int i = 0; i < rozmiarMacierzy; i++) {

        int maxWiersz = znajdzMaksymalnyElement(i);
        std::swap(A[maxWiersz], A[i]);
        std::swap(b[maxWiersz], b[i]);

        eliminacjaGaussa(i);
        std::cout << "Krok " << i+1 << ": " << std::endl;
        wypiszMacierz();
    }


    std::vector<double> x = rozwiazUklad();
    wypiszRozwiazanie(x);

}
