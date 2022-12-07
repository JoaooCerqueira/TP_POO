#include "Madeira.h"

std::string Madeira::getTipo() {return "madeira";}

std::string Madeira::getDescription() {
    return "Madeira: " + Recurso::getDescription();
}

Recurso *Madeira::clone() {
    return new Madeira(*this);
}
