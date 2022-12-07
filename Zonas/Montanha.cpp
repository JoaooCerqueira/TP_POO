#include <iostream>
#include "Montanha.h"

std::string Montanha::getTipo() {return "mnt";}

void Montanha::faseRecolha() {
    atualizarDeposito();
    Zona::faseRecolha();
    despedir(5);
}

void Montanha::atualizarDeposito() { *this += Zona::trabalhar();}

Zona *Montanha::clone(std::vector<Recurso *> recursos) {
    Montanha *zona = new Montanha(*this,recursos);
    return zona;
}