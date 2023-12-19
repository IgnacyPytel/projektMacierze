//
// Created by pytlu on 18.12.2023.
//

#ifndef PROJEKTMACIERZE_GAUSSPODSTAWOWY_H
#define PROJEKTMACIERZE_GAUSSPODSTAWOWY_H

#include "../MetodaGaussa/MetodaGaussa.h"

class GaussPodstawowy : public MetodaGaussa {
public:
    GaussPodstawowy(const std::vector<std::vector<double>>& A, const std::vector<double>& b);
    GaussPodstawowy();
    void eliminacjaGaussa(int kolumna) override;
    std::vector<double>  rozwiazUklad() override;
    void wypiszRozwiazanie(const std::vector<double>& x) override;
    void rozwiaz() override;

};


#endif //PROJEKTMACIERZE_GAUSSPODSTAWOWY_H
