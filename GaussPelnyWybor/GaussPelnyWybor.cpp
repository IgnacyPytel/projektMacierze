
#include "GaussPelnyWybor.h"
#include <algorithm>
#include <iostream>


void GaussPelnyWybor::daneTestowePelny(std::vector<std::vector<double>>& A,
                                       std::vector<double>& b) {
    //uklad rownan
    A = {{14, -13, 3, -16, -42},
         {3.5, -18, 13, -23.75, -21},
         {3.5, 3, -5.25, 9.25, 10.5},
         {2, 14.5, -10.5, 18.5, 21},
         {1.5, 6.75, -9.25, 17, -10.5}};

    //wektor wyrazow wolnych
    b = {-37, -5.5, 12.5, 23.5, -45.25};
}

GaussPelnyWybor::GaussPelnyWybor(const std::vector<std::vector<double>>& A,
                                 const std::vector<double>& b) {
    this->A = A;
    this->b = b;
}

void GaussPelnyWybor::wypiszMacierz() const {
    for (const auto& wiersz : A) {
        for (const auto& element : wiersz) {

            std::cout << element << "\t";

        }
        std::cout << '\n';
    }
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

std::pair<int, int> GaussPelnyWybor::znajdzMaksymalnyElement(int poczatek) {
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
    std::cout << "Maksymalny element: " << maxElement << std::endl;
    return {indeksMaksymalnegoElementuWiersza,
            indeksMaksymalnegoElementuKolumny};
}

void GaussPelnyWybor::wypiszRozwiazanie(const std::vector<double>& x) {
    for (int i = 0; i < x.size(); i++) {

        std::cout << "x" << i+1 << " = " << x[i] << std::endl;

    }
}

void GaussPelnyWybor::eliminacjaGaussa(int kolumna) {
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
    // wektor permutacji przechowuje z informacje z swapowaniu wierszy i kolumn miejscami
    std::vector<int> Permutacje(rozmiarMacierzy);


    // sprawdzanie zgodnie z zalozeniem uzywajac epsilona
    for (int i = 0; i < rozmiarMacierzy; i++) {
        if (std::abs(A[i][i]) < epsilon) {
            std::cout << "Uwaga: Element na glownej przekatnej jest rowny zero w kroku " << i+1 << std::endl;
            throw std::runtime_error("Element na glownej przekatnej jest rowny zero");

        }
    }

    for (int i = 0; i < rozmiarMacierzy; i++) {

        Permutacje[i] = i;

    }

    for (int i = 0; i < rozmiarMacierzy; i++) {

        auto [indeksMaksymalnegoElementuWiersza,
                indeksMaksymalnegoElementuKolumny] = znajdzMaksymalnyElement(i);

        zamienWiersze(indeksMaksymalnegoElementuWiersza, i);
        zamienKolumny(indeksMaksymalnegoElementuKolumny, i);
        // zapis informacji o swapowaniu ^^
        std::swap(Permutacje[indeksMaksymalnegoElementuKolumny], Permutacje[i]);
        eliminacjaGaussa(i);

        std::cout << "Krok " << i+1 << ": " << std::endl;
        wypiszMacierz();
    }
    std::vector<double> x = rozwiazUklad();
    // kopia wektora rozwiazan 
    std::vector<double> y = x;

    for (int i = 0; i < rozmiarMacierzy; i++) {
        // dzieki permutacjom mozemy wypisac rozwiazania w odpowiedniej kolejnosci
        x[Permutacje[i]] = y[i];

    }
    wypiszRozwiazanie(x);
}
