#ifndef PROJECT_POO_FUNDICAO_H
#define PROJECT_POO_FUNDICAO_H

#include "Edificio.h"

class Fundicao : public Edificio{
public:
    Fundicao(std::vector<Recurso *> recursos) : Edificio(recursos[2]) {}
    Fundicao(Edificio &outro,Recurso *recurso) : Edificio(outro,recurso) {}
    std::string getTipo() override;
    bool atualizarDeposito(Zona *zona) override;
    Edificio *encontrarCarvao(Zona *zona);
    void destruir(float &dinheiro) override;

    Edificio * clone(std::vector<Recurso *> recursos) override;
private:
};


#endif //PROJECT_POO_FUNDICAO_H
