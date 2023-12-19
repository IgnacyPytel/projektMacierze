#include <iostream>
#include <vector>
#include "MetodaGaussa/MetodaGaussa.h"
#include "GaussPodstawowy/GaussPodstawowy.h"
#include "GaussWyborKolumny/GaussWyborKolumny.h"
#include "GaussPelnyWybor/GaussPelnyWybor.h"


void wprowadzDaneWejsciowe(std::vector<std::vector<double>>& A, std::vector<double>& b) {
    int iloscRownan;
    std::cout << "Wpisz ilosc rownan: ";
    std::cin >> iloscRownan;

    A.resize(iloscRownan, std::vector<double>(iloscRownan));
    b.resize(iloscRownan);

    std::cout << "Podaj wspolczynniki przy x'ach:\n";
    for (int i = 0; i < iloscRownan; i++) {
        for (int j = 0; j < iloscRownan; j++) {
            std::cin >> A[i][j];
        }
    }

    std::cout << "Podaj wektor B:\n";
    for (int i = 0; i < iloscRownan; i++) {
        std::cin >> b[i];
    }
}

int main() {
    int wybor;
    std::cout << "Wybierz metode:\n"
                 "1. GaussPodstawowy\n"
                 "2. GaussWyborKolumny\n"
                 "3. GaussPelnyWybor\n";
    std::cin >> wybor;

    std::vector<std::vector<double>> A;
    std::vector<double> b;

    int wyborWprowadzania;
    std::cout << "Czy chcesz wprowadzic dane wejsciowe?\n"
                 "1. Tak\n"
                 "2. Nie\n";
    std::cin >> wyborWprowadzania;

    if (wyborWprowadzania == 1) {
        wprowadzDaneWejsciowe(A, b);
    } else {
        // tutaj na testy trzeba dodac
    }

    switch (wybor) {
        case 1: {
            GaussPodstawowy gp(A, b);
            gp.rozwiaz();
            break;
        }
        case 2: {
            GaussWyborKolumny gw(A, b);
            gw.rozwiaz();
            break;
        }
        case 3: {
            GaussPelnyWybor gpw(A,b);
            gpw.rozwiaz();
            break;
        }
        default:
            std::cout << "Nieprawidlowy wybor\n";
            break;
    }

    return 0;
}