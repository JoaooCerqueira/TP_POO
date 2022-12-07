#ifndef PROJECT_POO_OPERARIO_H
#define PROJECT_POO_OPERARIO_H

#include "Trabalhador.h"

class Operario : public Trabalhador{
public:
    std::string getTipo() override;
    bool despedir(int extra) override;
    float trabalhar(Zona *zona) override;

    Trabalhador * clone() override;
private:
};


#endif //PROJECT_POO_OPERARIO_H
