#ifndef PROJECT_POO_MINA_H
#define PROJECT_POO_MINA_H

#include "Edificio.h"

class Mina : public Edificio{
public:
    Mina(Recurso* recurso) : Edificio(recurso) {}
    Mina(Edificio &outro,Recurso *recurso) : Edificio(outro,recurso) {}
    bool atualizarDeposito(Zona *zona) override;
    bool desabar(int perc);
    void destruir(float &dinheiro) override;
    Edificio * clone(std::vector<Recurso *> recursos) = 0;
private:
    void depositarMinerio(float fac);
};


#endif //PROJECT_POO_MINA_H
