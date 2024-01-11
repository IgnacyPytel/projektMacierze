

#ifndef PROJEKTMACIERZE_GAUSSPELNYWYBOR_H
#define PROJEKTMACIERZE_GAUSSPELNYWYBOR_H

#include "../MetodaGaussa/MetodaGaussa.h"

class GaussPelnyWybor : public MetodaGaussa {
public:

    GaussPelnyWybor(const std::vector<std::vector<double>>& A,
                    const std::vector<double>& b);

    std::pair<int, int> znajdzMaksymalnyElement(int poczatek);
    void zamienWiersze(int wiersz1, int wiersz2);
    void zamienKolumny(int kolumna1, int kolumna2);

    static void daneTestowePelny(std::vector<std::vector<double>>& A,
                                 std::vector<double>& b);

    void wypiszMacierz() const;
    void wypiszRozwiazanie(const std::vector<double>& x) override;
    void eliminacjaGaussa(int kolumna) override;
    std::vector<double> rozwiazUklad() override;
    void rozwiaz() override;
};


#endif //PROJEKTMACIERZE_GAUSSPELNYWYBOR_H
