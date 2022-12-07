#ifndef PROJECT_POO_BATERIA_H
#define PROJECT_POO_BATERIA_H

#include "Edificio.h"

class Bateria : public Edificio{
public:
    Bateria(std::vector<Recurso*> recursos) : Edificio(recursos[3]){}
    Bateria(Edificio &outro,Recurso* recursos) : Edificio(outro,recursos) {}
    std::string getTipo() override;
    bool atualizarDeposito(Zona *zona) override {return true;}
    void destruir(float &dinheiro) override;

    Edificio * clone(std::vector<Recurso *> recursos) override;
private:
};


#endif //PROJECT_POO_BATERIA_H
