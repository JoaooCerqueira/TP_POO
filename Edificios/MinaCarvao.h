#ifndef PROJECT_POO_MINACARVAO_H
#define PROJECT_POO_MINACARVAO_H

#include "Mina.h"

class MinaCarvao : public Mina{
public:
    MinaCarvao(std::vector<Recurso*> recursos) : Mina(recursos[1]) {}
    MinaCarvao(Edificio &outro,Recurso *recurso) : Mina(outro,recurso) {}
    std::string getTipo() override;
    bool atualizarDeposito(Zona *zona) override;
    Edificio * clone(std::vector<Recurso *> recursos) override;
private:
};

#endif //PROJECT_POO_MINACARVAO_H
