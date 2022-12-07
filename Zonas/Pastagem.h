#ifndef PROJETO_POO_PASTURE_H
#define PROJETO_POO_PASTURE_H

#include "Zona.h"

class Pastagem : public Zona{
public:
    Pastagem() = default;
    Pastagem(Zona &zona,std::vector<Recurso*> recursos) : Zona(zona,recursos) {}
    std::string getTipo() override;
    void faseRecolha() override;
    Zona * clone(std::vector<Recurso *> recursos) override;
private:
};


#endif //PROJETO_POO_PASTURE_H
