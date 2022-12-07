#ifndef PROJECT_POO_MINEIRO_H
#define PROJECT_POO_MINEIRO_H

#include "Trabalhador.h"

class Mineiro : public  Trabalhador{
public:
    std::string getTipo() override;
    bool despedir(int extra) override;
    float trabalhar(Zona *zona) override;

    Trabalhador * clone() override;
private:
};


#endif //PROJECT_POO_MINEIRO_H
