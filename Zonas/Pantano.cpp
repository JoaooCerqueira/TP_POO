#include "Pantano.h"

std::string Pantano::getTipo() {return "pnt";}

void Pantano::faseRecolha() {
    Zona::faseRecolha();
    if (existeEdificio()){
        ++dia;
        if (dia == 10){
            deleteEdificio();
            despedir(100);
        }
    }
    else{
        dia = 0;
    }
    despedir();
}

Zona *Pantano::clone(std::vector<Recurso *> recursos) {
    return new Pantano(*this,recursos);
}
