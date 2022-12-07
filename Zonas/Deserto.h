#ifndef PROJETO_POO_DESERT_H
#define PROJETO_POO_DESERT_H

#include "Zona.h"

class Deserto : public Zona{
public:
    Deserto() = default;
    Deserto(Zona &zona,std::vector<Recurso*> recursos) : Zona(zona,recursos) {}
    std::string getTipo() override;
    void faseRecolha() override;
    Zona *clone(std::vector<Recurso *> recursos) override;
private:
};

#endif //PROJETO_POO_DESERT_H