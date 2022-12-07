#include "Recurso.h"

void Recurso::update(float quantidade) {this->quantidade += quantidade;}

std::string Recurso::getDescription() {return std::to_string(quantidade);}

float Recurso::getQuantidade() const {return quantidade;}

Recurso &Recurso::operator-=(float quantidade) {
    this->quantidade -= quantidade;
    return *this;
}

Recurso &Recurso::operator+=(float quantidade) {
    this->quantidade += quantidade;
    return *this;
}

Recurso::~Recurso() {}
