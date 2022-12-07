#include "Aco.h"

std::string Aco::getTipo() {
    return "aco";
}

std::string Aco::getDescription() {
    return "Aco: " + Recurso::getDescription();
}

Recurso *Aco::clone() {
    return new Aco(*this);
}

