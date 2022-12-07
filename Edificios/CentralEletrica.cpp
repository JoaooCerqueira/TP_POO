#include "CentralEletrica.h"
#include "../Zonas/Zona.h"

std::string CentralEletrica::getTipo() {
    return "cen";
}

bool CentralEletrica::atualizarDeposito(Zona *zona) {
    if (estaLigado() && zona->zonaAdjacente("flr", 1)){
        Edificio::atualizarDeposito(zona);
        Edificio *bateria = EdificioAdjacente(zona, "bat");
        if (bateria){
            bateria->Edificio::atualizarDeposito(zona);
        }
    }
    return true;
}

void CentralEletrica::destruir(float &dinheiro) {
    dinheiro += getDeposito();
    Edificio::destruir(dinheiro);
}

Edificio *CentralEletrica::clone(std::vector<Recurso *> recursos) {
    Edificio *edificio = new CentralEletrica(*this, recursos[1]);
    return edificio;
}