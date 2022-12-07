#include "Preco.h"

std::string Preco::getTipo() const {
    return tipo;
}

int Preco::getPreco() const {
    return preco;
}

void Preco::setPreco(int preco){
    this->preco = preco;
}

float Preco::getRecurso() const {
    return recurso;
}

void Preco::setRecurso(float recurso){
    this->recurso = recurso;
}

std::string Preco::getDescricao() {
    return getTipo() + "\nPreco: " + std::to_string(preco) +"\nVigas de Madeira: " + std::to_string(recurso) + "\n";
}
