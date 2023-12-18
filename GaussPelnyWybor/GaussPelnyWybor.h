//
// Created by pytlu on 18.12.2023.
//

#ifndef PROJEKTMACIERZE_GAUSSPELNYWYBOR_H
#define PROJEKTMACIERZE_GAUSSPELNYWYBOR_H

#include "../MetodaGaussa/MetodaGaussa.h"

class GaussPelnyWybor : public MetodaGaussa {
public:
    GaussPelnyWybor();
    GaussPelnyWybor(const std::vector<std::vector<double>>& A, const std::vector<double>& b);
    std::pair<int, int> znajdzPivot(int start);
    void zamienWiersze(int wiersz1, int wiersz2);
    void zamienKolumny(int kolumna1, int kolumna2);
    void eliminacjaGaussa(int col) override;
    std::vector<double> rozwiazUklad() override;
    void rozwiaz() override;
};


#endif //PROJEKTMACIERZE_GAUSSPELNYWYBOR_H
