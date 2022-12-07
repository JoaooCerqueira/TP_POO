#ifndef PROJETO_POO_SWAMP_H
#define PROJETO_POO_SWAMP_H

#include "Zona.h"

class Pantano : public Zona{
public:
    Pantano() = default;
    Pantano(Zona &zona,std::vector<Recurso*> recursos) : Zona(zona,recursos) {}
    std::string getTipo() override;
    void faseRecolha() override;
    Zona * clone(std::vector<Recurso *> recursos) override;
private:
    int dia = 0;
};


#endif //PROJETO_POO_SWAMP_H
