#include "Pastagem.h"

std::string Pastagem::getTipo() {return "pas";}

void Pastagem::faseRecolha() {
    Zona::faseRecolha();
}

Zona *Pastagem::clone(std::vector<Recurso *> recursos) {
    return new Pastagem(*this,recursos);
}

