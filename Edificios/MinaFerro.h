#ifndef PROJECT_POO_MINAFERRO_H
#define PROJECT_POO_MINAFERRO_H

#include "Mina.h"

class MinaFerro : public Mina{
public:
    MinaFerro(std::vector<Recurso*> recursos) : Mina(recursos[0]) {}
    MinaFerro(Edificio &outro,Recurso *recurso) : Mina(outro,recurso) {}
    std::string getTipo() override;
    bool atualizarDeposito(Zona *zona) override;
    Edificio * clone(std::vector<Recurso *> recursos) override;
private:
};


#endif //PROJECT_POO_MINAFERRO_H
