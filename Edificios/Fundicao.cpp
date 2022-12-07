#include "Fundicao.h"
#include "../Zonas/Zona.h"

std::string Fundicao::getTipo() {
    return "fun";
}

bool Fundicao::atualizarDeposito(Zona *zona) {
    Edificio *ferro = EdificioAdjacente(zona, "mnf");
    if(estaLigado() && ferro && ferro->getDeposito() >= 1.5 && zona->encontrarTrabalhador("operario")){
        Edificio *carvao = encontrarCarvao(zona);
        if (carvao){
            Edificio::atualizarDeposito(zona);
            carvao->transformarRecurso(0.5);
            ferro->transformarRecurso(1.5);
        }
    }
    return true;
}

Edificio *Fundicao::encontrarCarvao(Zona *zona) {
    if(EdificioAdjacente(zona, "cen")){
        Edificio *carvao = EdificioAdjacente(zona, "cen");
        if(carvao->getDeposito() >= 0.5){
            return EdificioAdjacente(zona, "cen");
        }
    }
    Edificio *carvao = EdificioAdjacente(zona, "mnc");
    if(carvao->getDeposito() >=  0.5){
        return carvao;
    }
    return nullptr;
}

void Fundicao::destruir(float &dinheiro) {
    dinheiro += getDeposito() * 2;
    Edificio::destruir(dinheiro);
}

Edificio *Fundicao::clone(std::vector<Recurso *> recursos) {
    Edificio *edificio = new Fundicao(*this,recursos[2]);
    return edificio;
}


