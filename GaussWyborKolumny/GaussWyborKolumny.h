
#ifndef PROJEKTMACIERZE_GAUSSWYBORKOLUMNY_H
#define PROJEKTMACIERZE_GAUSSWYBORKOLUMNY_H


#include "../MetodaGaussa/MetodaGaussa.h"

class GaussWyborKolumny : public MetodaGaussa {
public:

    GaussWyborKolumny(const std::vector<std::vector<double>>& A,
                      const std::vector<double>& b);

    int znajdzMaksymalnyElement(int kolumna);

    static void daneTestoweKolumny(std::vector<std::vector<double>>& A,
                                   std::vector<double>& b);

    void wypiszMacierz() const;
    void wypiszRozwiazanie(const std::vector<double>& x) override;
    void eliminacjaGaussa(int kolumna) override;
    std::vector<double> rozwiazUklad() override;
    void rozwiaz() override;
};


#endif //PROJEKTMACIERZE_GAUSSWYBORKOLUMNY_H
