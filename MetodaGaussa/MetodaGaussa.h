//
// Created by pytlu on 18.12.2023.
//

#ifndef PROJEKTMACIERZE_METODAGAUSSA_H
#define PROJEKTMACIERZE_METODAGAUSSA_H

#include <vector>

class MetodaGaussa {
protected:
    std::vector<std::vector<double>> A;
    std::vector<double> b;
    double epsilon = 1e-7;
public:
    MetodaGaussa();
    MetodaGaussa(const std::vector<std::vector<double>>& A, const std::vector<double>& b);

    virtual void eliminacjaGaussa(int col);

    virtual std::vector<double> rozwiazUklad();

    virtual void wypiszRozwiazanie(const std::vector<double>& x);
    virtual void rozwiaz();
};


#endif //PROJEKTMACIERZE_METODAGAUSSA_H
