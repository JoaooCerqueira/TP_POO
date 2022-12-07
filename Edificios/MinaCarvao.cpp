#include "MinaCarvao.h"

std::string MinaCarvao::getTipo() {
    return "mnc";
}

bool MinaCarvao::atualizarDeposito(Zona *zona) {
    Mina::atualizarDeposito(zona);
    return Mina::desabar(10);
}

Edificio *MinaCarvao::clone(std::vector<Recurso *> recursos) {
    Edificio *edificio = new MinaCarvao(*this, recursos[1]);
    return edificio;
}
