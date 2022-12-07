#include "Gruta.h"

std::string Gruta::getTipo() {
    return "gru";
}

void Gruta::faseRecolha() {
    atualizarDeposito();
    Zona::faseRecolha();
    despedir(10);
}

void Gruta::atualizarDeposito() {*this += Zona::trabalhar();}

Zona *Gruta::clone(std::vector<Recurso *> recursos) {
    Gruta *zona = new Gruta(*this,recursos);
    return zona;
}