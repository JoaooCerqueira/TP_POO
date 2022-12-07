#include "Operario.h"
#include "../Zonas/Zona.h"

std::string Operario::getTipo() {
    return "operario";
}

bool Operario::despedir(int extra) {
    if (rand() % 100 <= 5 + extra && getDia() >= 10){
        return true;
    }
    return false;
}

float Operario::trabalhar(Zona *zona) {
    return Trabalhador::trabalhar(zona);
}

Trabalhador *Operario::clone() {
    return new Operario(*this);
}
