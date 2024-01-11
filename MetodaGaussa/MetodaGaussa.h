
#ifndef PROJEKTMACIERZE_METODAGAUSSA_H
#define PROJEKTMACIERZE_METODAGAUSSA_H
#pragma once

#include <vector>

class MetodaGaussa {
protected:

    std::vector<std::vector<double>> A;
    std::vector<double> b;
    double epsilon = 1e-14;
public:

    virtual void eliminacjaGaussa(int kolumna) = 0;
    virtual std::vector<double> rozwiazUklad() = 0;
    virtual void wypiszRozwiazanie(const std::vector<double>& x) = 0;
    virtual void rozwiaz() = 0;
};


#endif //PROJEKTMACIERZE_METODAGAUSSA_H
