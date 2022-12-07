#ifndef PROJECT_POO_EDIFICIOX_H
#define PROJECT_POO_EDIFICIOX_H

#include "Edificio.h"

class EdificioX : public Edificio{
public:
    EdificioX(std::vector<Recurso *> recursos) : Edificio(recursos[5]) {}
    EdificioX(Edificio &outro,Recurso *recurso) : Edificio(outro,recurso) {}
    std::string getTipo() override;
    bool atualizarDeposito(Zona *zona) override;
    void destruir(float &dinheiro) override;
    Edificio * clone(std::vector<Recurso *> recursos);

private:
};


#endif //PROJECT_POO_EDIFICIOX_H
