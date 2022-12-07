#include "Floresta.h"

std::string Floresta::getTipo() {return "flr";}

void Floresta::faseRecolha() {
    novaArvore();
    atualizarDeposito();
    Zona::faseRecolha();
    despedir();
}

void Floresta::novaArvore() {
    if (!existeEdificio()){
        ++crescer;
        if (crescer == 2 && arvores <= 100){
            ++arvores;
            crescer = 0;
        }
        return;
    }
    if (arvores > 0){
        --arvores;
    }
}

void Floresta::atualizarDeposito() {
    int madeira_cortada = trabalhar();
    if (arvores > madeira_cortada) {
        *this += madeira_cortada;
        arvores -= madeira_cortada;
    }
    else{
        *this += arvores;
        arvores = 0;
    }
}

Zona *Floresta::clone(std::vector<Recurso *> recursos) {
    Floresta* zona = new Floresta(*this,recursos);
    return zona;
}