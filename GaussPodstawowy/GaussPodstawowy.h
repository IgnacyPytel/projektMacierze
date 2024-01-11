

#ifndef PROJEKTMACIERZE_GAUSSPODSTAWOWY_H
#define PROJEKTMACIERZE_GAUSSPODSTAWOWY_H

#include "../MetodaGaussa/MetodaGaussa.h"

class GaussPodstawowy : public MetodaGaussa {
public:

    GaussPodstawowy(const std::vector<std::vector<double>>& A,
                    const std::vector<double>& b);

    static void daneTestowePodstawowy(std::vector<std::vector<double>>& A,
                                      std::vector<double>& b);
    void wypiszMacierz() const;
    void eliminacjaGaussa(int kolumna) override;
    std::vector<double>  rozwiazUklad() override;
    void wypiszRozwiazanie(const std::vector<double>& x) override;
    void rozwiaz() override;

};


#endif //PROJEKTMACIERZE_GAUSSPODSTAWOWY_H
