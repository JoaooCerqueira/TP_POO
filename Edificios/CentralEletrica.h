#ifndef PROJECT_POO_CENTRALELETRICA_H
#define PROJECT_POO_CENTRALELETRICA_H

#include "Edificio.h"

class CentralEletrica : public Edificio{
public:
    CentralEletrica(std::vector<Recurso *> recursos) : Edificio(recursos[1]) {}
    CentralEletrica(Edificio &outro,Recurso *recurso) : Edificio(outro,recurso) {}
    std::string getTipo() override;
    bool atualizarDeposito(Zona *zona) override;
    void destruir(float &dinheiro) override;

    Edificio * clone(std::vector<Recurso *> recursos) override;
private:
};


#endif //PROJECT_POO_CENTRALELETRICA_H
