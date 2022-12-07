#include "ZonaRecurso.h"

void ZonaRecurso::removerRecurso(Recurso *recurso, float &quantidade) {
    if (recurso == this->recurso && deposito > 0 && quantidade > 0) {
        if (ZonaRecurso::getZonaDeposito() > quantidade) {

            *this -= quantidade;
            quantidade = 0;
            return;
        }
        *this -= deposito;
        deposito = 0;
    }
    Zona::removerRecurso(recurso, quantidade);
}

bool ZonaRecurso::transformarRecurso(int quantidade) {
    if (ZonaRecurso::getZonaDeposito() < quantidade){return false;}
    *this -= quantidade;
    return true;
}

ZonaRecurso &ZonaRecurso::operator+=(float quantidade) {
    deposito += quantidade;
    *recurso += quantidade;
    return *this;
}

ZonaRecurso &ZonaRecurso::operator-=(float quantidade) {
    deposito -= quantidade;
    *recurso -= quantidade;
    return *this;
}
