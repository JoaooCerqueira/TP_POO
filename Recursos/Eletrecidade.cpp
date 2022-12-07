#include "Eletrecidade.h"

std::string Eletrecidade::getTipo() {
    return "eletricidade";
}

std::string Eletrecidade::getDescription() {
    return  "Eletricidade: " + Recurso::getDescription();
}

Recurso *Eletrecidade::clone() {
    return new Eletrecidade(*this);
}
