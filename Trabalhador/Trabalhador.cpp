#include "Trabalhador.h"
#include <sstream>
#include "../Zonas/Zona.h"

Trabalhador::Trabalhador(){
    id = ++novo_id;
    setInfo();
}

void Trabalhador::updateIndetificador() {
    ++dia;
    setInfo();
}

int Trabalhador::getDia() {return dia;}

std::string Trabalhador::getInfo() {return info;}

int Trabalhador::getId() {return id;}

void Trabalhador::setInfo() {
    std::ostringstream oss;
    oss << id << "." << dia;
    info = oss.str();
}

bool Trabalhador::despedir(int adicional) {return false;}

float Trabalhador::trabalhar(Zona *zona) {
    if (zona->getTipo() == "mnt" || zona->getTipo() == "gru"){
        return 0.1;
    }
    return 0;
}

Trabalhador::~Trabalhador() {}
