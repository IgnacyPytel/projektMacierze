#include <iostream>
#include <vector>
#include "GaussPodstawowy/GaussPodstawowy.h"
#include "GaussWyborKolumny/GaussWyborKolumny.h"
#include "GaussPelnyWybor/GaussPelnyWybor.h"


void wprowadzDaneWejsciowe(std::vector<std::vector<double>>& A,
                           std::vector<double>& b) {
    int iloscRownan;
    std::cout << "Wpisz ilosc rownan: ";
    std::cin >> iloscRownan;


    if (iloscRownan <= 0) {
        std::cout << "Nieodpowiednia ilosc rownan\n";
        return;
    }


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
    int wyborTypu;
    while (true) {
        std::cout << "Menu:\n"
                     "1. Metoda Podstawowa Gaussa\n"
                     "2. Metoda Wyboru najwiekszego elementu w kolumnie\n"
                     "3. Metoda Pelnego Gaussa\n"
                     "4. Wyjscie\n";
        std::cin >> wyborTypu;
        if (wyborTypu == 4) {
            break;
        }
        std::vector<std::vector<double>> A;
        std::vector<double> b;
        int wyborMetody;
        while (true) {
            std::cout << "Menu:\n"
                         "1. Wprowadz dane\n"
                         "2. Uzyj danych testowych\n"
                         "3. Cofnij sie do Menu\n";
            std::cin >> wyborMetody;
            if (wyborMetody == 1) {
                wprowadzDaneWejsciowe(A, b);
                break;
            } else if (wyborMetody == 2) {
                switch (wyborTypu) {
                    case 1: {
                        GaussPodstawowy::daneTestowePodstawowy(A, b);
                        break;
                    }
                    case 2: {
                        GaussWyborKolumny::daneTestoweKolumny(A, b);
                        break;
                    }
                    case 3: {
                        GaussPelnyWybor::daneTestowePelny(A, b);
                        break;
                    }
                }
                break;
            } else if (wyborMetody == 3) {
                break;
            }
        }
        if (wyborMetody == 3) {
            continue;
        }
        switch (wyborTypu) {
            case 1: {
                GaussPodstawowy gp(A, b);
                gp.rozwiaz();
                break;
            }
            case 2: {
                GaussWyborKolumny gwk(A, b);
                gwk.rozwiaz();
                break;
            }
            case 3: {
                GaussPelnyWybor gpw(A, b);
                gpw.rozwiaz();
                break;
            }
        }
    }
    return 0;
}