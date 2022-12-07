#include "EdificioX.h"
#include "../Zonas/Zona.h"

std::string EdificioX::getTipo() {
    return "edx";
}

bool EdificioX::atualizarDeposito(Zona *zona) {
    if (estaLigado() && zona->zonaAdjacente("flr", 2)){
        Edificio::atualizarDeposito(zona);
    }
    return true;
}

void EdificioX::destruir(float &dinheiro) {
    dinheiro += getDeposito() * 2;
    Edificio::destruir(dinheiro);
}

Edificio *EdificioX::clone(std::vector<Recurso *> recursos) {
    Edificio *edificio = new EdificioX(*this,recursos[5]);
    return edificio;
}