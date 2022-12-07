#include "Mineiro.h"
#include "../Zonas/Zona.h"

std::string Mineiro::getTipo() {
    return "mineiro";
}

bool Mineiro::despedir(int extra) {
    if (rand() % 100 <= 10 + extra && getDia() >= 2){
        return true;
    }
    return false;
}

float Mineiro::trabalhar(Zona *zona) {
    return Trabalhador::trabalhar(zona);
}

Trabalhador *Mineiro::clone() {
    return new Mineiro(*this);
}
