#include "MinaFerro.h"

std::string MinaFerro::getTipo() {
    return "mnf";
}

bool MinaFerro::atualizarDeposito(Zona *zona) {
    Mina::atualizarDeposito(zona);
    return Mina::desabar(15);
}

Edificio *MinaFerro::clone(std::vector<Recurso *> recursos) {
    Edificio *edificio = new MinaFerro(*this,recursos[0]);
    return edificio;
}
