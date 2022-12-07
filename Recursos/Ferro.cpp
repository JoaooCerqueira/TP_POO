#include "Ferro.h"

std::string Ferro::getTipo() {
    return "ferro";
}

std::string Ferro::getDescription() {
    return "Ferro: " + Recurso::getDescription();
}

Recurso *Ferro::clone() {
    return new Ferro(*this);
}
