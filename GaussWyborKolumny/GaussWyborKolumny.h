//
// Created by pytlu on 18.12.2023.
//

#ifndef PROJEKTMACIERZE_GAUSSWYBORKOLUMNY_H
#define PROJEKTMACIERZE_GAUSSWYBORKOLUMNY_H


#include "../MetodaGaussa/MetodaGaussa.h"

class GaussWyborKolumny : public MetodaGaussa {
public:
    GaussWyborKolumny(const std::vector<std::vector<double>>& A, const std::vector<double>& b);
    GaussWyborKolumny();
    int znajdzMaksymalnyElement(int col);
    void eliminacjaGaussa(int col) override;
    std::vector<double> rozwiazUklad() override;
    void rozwiaz() override;
};


#endif //PROJEKTMACIERZE_GAUSSWYBORKOLUMNY_H
