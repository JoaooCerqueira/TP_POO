#include <iostream>
#include "Mercado.h"

Mercado::Mercado(){
    melhorar_edificio.push_back(Preco("mnf",15,1));
    melhorar_edificio.push_back(Preco("mnc",10,1));
    melhorar_edificio.push_back(Preco("bat",5));
}

void Mercado::modificar(std::string tipo, int quantidade) {
    auto it = precos.begin();
    while(it != precos.end()){
        if (it->getTipo() == tipo){
            if (it->getPreco() != 0){
                it->setPreco(quantidade);
            }
            else{
                it->setRecurso(quantidade);
            }
        }
        ++it;
    }
}

int Mercado::melhorarEdificio(std::string tipo, float &dinheiro, Recurso* vigas_de_madeira) {
    for (auto preco: melhorar_edificio) {
        if(preco.getTipo() == tipo && dinheiro >= preco.getPreco() && vigas_de_madeira->getQuantidade() >= preco.getRecurso()){
            dinheiro -= preco.getPreco();
            return preco.getRecurso();
        }
    }
    return -1;
}

void Mercado::vende(std::string tipo, float &dinheiro) {
    for (auto preco : precos) {
        if(preco.getTipo() == tipo){
            dinheiro += preco.getPreco();
        }
    }
}

bool Mercado::comprarTrabalhador(std::string tipo, float &dinheiro) {
    for (auto preco: precos) {
        if(preco.getTipo() == tipo && dinheiro >= preco.getPreco()){
            dinheiro -= preco.getPreco();
            return true;
        }
    }
    return false;
}

int Mercado::comprarEdificio(std::string tipo, int fac, float &dinheiro, Recurso* vigas_de_madeira) {
    for (auto preco: precos) {
        if(preco.getTipo() == tipo){
            if (tipo == "mnf" || tipo == "mnc"){
                return comprarMina(preco,fac,dinheiro,vigas_de_madeira);
            }
            else if(dinheiro >= preco.getPreco() * fac){
                if (tipo == "bat" || tipo == "cen"){
                    if (vigas_de_madeira->getQuantidade() >= preco.getRecurso() *fac){
                        dinheiro -= preco.getPreco() * fac;
                        return preco.getPreco() * fac;
                    }
                    else{
                        return -1;
                    }
                }
                dinheiro -= preco.getPreco() * fac;
                return 0;
            }
        }
    }
    return -1;
}

int Mercado::comprarMina(Preco preco, int fac, float &dinheiro, Recurso* vigas_de_madeira) {
    if (vigas_de_madeira->getQuantidade() >= preco.getRecurso() * fac && dinheiro >= preco.getPreco() * fac){
        return preco.getRecurso() * fac;
    }
    else{
        if (dinheiro >= preco.getPreco() * fac && vigas_de_madeira->getQuantidade() +  ((dinheiro - preco.getPreco()) / 10) >= preco.getRecurso() * fac){
            dinheiro -= ((preco.getRecurso() - vigas_de_madeira->getQuantidade()) * 10) * fac;
            dinheiro -= preco.getPreco() * fac;
            return vigas_de_madeira->getQuantidade();
        }
    }
    return -1;
}

void Mercado::vendeRecurso(float &dinheiro, float quantitade, std::string tipo) {
    if (tipo == "ferro" || tipo == "carvao" || tipo == "madeira"){
        dinheiro += quantitade;
    }
    else if (tipo == "eletricidade"){
        dinheiro += quantitade * 1.5;
    }
    else if (tipo == "aco" || tipo == "vigasmadeira"){
        dinheiro += quantitade * 2;
    }
}

std::string Mercado::getDescription(std::string tipo) {
    for (auto preco : precos) {
        if (preco.getTipo() == tipo){
            return preco.getDescricao();
        }
    }
}
