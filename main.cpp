#include <iostream>
#include <vector>
#include "MetodaGaussa/MetodaGaussa.h"
#include "GaussPodstawowy/GaussPodstawowy.h"
#include "GaussWyborKolumny/GaussWyborKolumny.h"
#include "GaussPelnyWybor/GaussPelnyWybor.h"


void wprowadzDaneWejsciowe(std::vector<std::vector<double>>& A, std::vector<double>& b) {
    int n;
    std::cout << "Wpisz ilosc rownan: ";
    std::cin >> n;

    A.resize(n, std::vector<double>(n));
    b.resize(n);

    std::cout << "Podaj wspolczynniki przy x'ach:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> A[i][j];
        }
    }

    std::cout << "Podaj wektor B:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
}

int main() {
    int choice;
    std::cout << "Wybierz metode:\n1. GaussPodstawowy\n2. GaussWyborKolumny\n3. GaussPelnyWybor\n";
    std::cin >> choice;

    std::vector<std::vector<double>> A;
    std::vector<double> b;

    int inputChoice;
    std::cout << "Czy chcesz wprowadzic dane wejsciowe?\n1. Tak\n2. Nie\n";
    std::cin >> inputChoice;

    if (inputChoice == 1) {
        wprowadzDaneWejsciowe(A, b);
    } else {
        // tutaj na testy trzeba dodac
    }

    switch (choice) {
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