#include "Lenhador.h"
#include "../Zonas/Zona.h"

std::string Lenhador::getTipo() {
    return "lenhador";
}

bool Lenhador::despedir(int extra) {
    //Dado o descanso e o trabalho ao ar livre, em princípio não se despede.
    if (rand() % 100 < extra){
        return true;
    }
    return false;
}

float Lenhador::trabalhar(Zona *zona) {
    if (getDia() % 4 == 0){
        return 0;
    }
    else if (zona->getTipo() == "flr"){
        return 1;
    }
    return Trabalhador::trabalhar(zona);
}

Trabalhador *Lenhador::clone() {
    return new Lenhador(*this);
}
