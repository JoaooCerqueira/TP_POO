#include "Deserto.h"

std::string Deserto::getTipo() {return "dsr";}

void Deserto::faseRecolha() {
    Zona::faseRecolha();
    despedir();
}

Zona *Deserto::clone(std::vector<Recurso *> recursos) {
    return new Deserto(*this,recursos);
}
