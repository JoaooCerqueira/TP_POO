#include "Mina.h"
#include "../Zonas/Zona.h"


bool Mina::atualizarDeposito(Zona *zona) {
    if (estaLigado() && zona->encontrarTrabalhador("mineiro")){
        if (zona->getTipo() == "mnt"){
            depositarMinerio(2);
        }
        else if(zona->getTipo() == "dsr"){
            depositarMinerio(0.5);
        }
        else{
            depositarMinerio(1);
        }
    }
    return true;
}

void Mina::depositarMinerio(float fac) {
    if ((getDeposito() + 1 + getLevel()) * fac <= 90 + (getLevel() * 10)){
        float nova_deposito = 1 + getLevel() * fac;
        *this += nova_deposito;
    }
}

bool Mina::desabar(int perc) {
    if (rand() % 100 <= perc){
        return false;
    }
    return true;
}

void Mina::destruir(float &dinheiro) {
    dinheiro += getDeposito();
    Edificio::destruir(dinheiro);
}


