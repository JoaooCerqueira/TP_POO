#include "Bateria.h"
#include "../Zonas/Zona.h"

std::string Bateria::getTipo() {
    return "bat";
}

void Bateria::destruir(float &dinheiro) {
    dinheiro += getDeposito() * 1.5;
    Edificio::destruir(dinheiro);
}

Edificio *Bateria::clone(std::vector<Recurso *> recursos) {
    Edificio *edificio = new Bateria(*this,recursos[3]);
    return edificio;
}
