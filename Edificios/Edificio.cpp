#include "Edificio.h"
#include "../Zonas/Zona.h"

Edificio::Edificio(Edificio &outro,Recurso *recurso) {
    nivel = outro.nivel;
    ligado = outro.ligado;
    deposito = outro.deposito;
    this->recurso = recurso;
}

Recurso &Edificio::getRecurso() {return *recurso;}

bool Edificio::atualizarDeposito(Zona *zona) {
    if (ligado){
        if (deposito + 1 < 90 + (nivel * 10)){
            *this += 1;
        }
    }
    return true;
}

Edificio * Edificio::EdificioAdjacente(Zona *zona, std::string tipo) {
    std::vector<std::vector<int>> adjacencias {{1,0},{0,1},{-1,0},{0,-1}};
    for (auto i: adjacencias) {
        Edificio *edificio = zona->getEdificio(i[0],i[1]);
        if (edificio && edificio->getTipo() == tipo){
            return edificio;
        }
    }
    return nullptr;
}

bool Edificio::proximoNivel(){
    if (nivel <= 4){
        ++nivel;
        return true;
    }
    return false;
}

void Edificio::removerRecurso(Recurso* recurso, float &quantidade) {
    if (recurso == this->recurso && quantidade > 0 && deposito > 0){
        if (deposito > quantidade) {
            *this -= quantidade;
            quantidade = 0;
            return;
        }
        *this -= deposito;
        deposito = 0;
    }
}

int Edificio::getLevel() const {return nivel;}

bool Edificio::estaLigado() const {return ligado;}

float Edificio::getDeposito() const {return deposito;}

void Edificio::setDeposito(float deposito) {this->deposito += deposito;}

Edificio &Edificio::operator+=(float quantidade) {
    deposito += quantidade;
    *recurso += quantidade;
    return *this;
}

Edificio &Edificio::operator-=(float quantidade) {
    deposito -= quantidade;
    *recurso -= quantidade;
    return *this;
}

Edificio::~Edificio() {}