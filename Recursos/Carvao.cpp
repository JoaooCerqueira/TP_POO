#include "Carvao.h"

std::string Carvao::getTipo() {
    return "carvao";
}

std::string Carvao::getDescription() {
    return "Carvao: " + Recurso::getDescription();
}

Recurso *Carvao::clone() {
    return new Carvao(*this);
}
