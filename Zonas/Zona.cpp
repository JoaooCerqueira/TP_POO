#include <iostream>
#include "Zona.h"
#include "../Trabalhador/Mineiro.h"
#include "../Trabalhador/Lenhador.h"
#include "../Trabalhador/Operario.h"
#include "../Edificios/MinaCarvao.h"
#include "../Edificios/MinaFerro.h"
#include "../Edificios/CentralEletrica.h"
#include "../Edificios/Bateria.h"
#include "../Edificios/Fundicao.h"
#include "../Edificios/EdificioX.h"

Zona::Zona(Zona &outro, std::vector<Recurso*> recursos) {
    num_trabalhadores = outro.num_trabalhadores;
    for (auto trabalhador: outro.trabalhadores) {
        trabalhadores.push_back(trabalhador->clone());
    }
    if (outro.edificio){
        edificio = outro.edificio->clone(recursos);
    }
}

bool Zona::adicionarEdificio(const std::string tipo, std::vector<Recurso*> recursos) {
    if (edificio == nullptr){
        edificio = construirEdificio(tipo, recursos);
        return true;
    }
    return false;
}

Edificio *Zona::construirEdificio(const std::string tipo, std::vector<Recurso*> recursos) {
    if (tipo == "mnf"){
        return new MinaFerro(recursos);
    } else if(tipo == "mnc"){
        return new MinaCarvao(recursos);
    } else if(tipo == "cen"){
        return new CentralEletrica(recursos);
    } else if(tipo == "bat"){
        return new Bateria(recursos);
    } else if(tipo == "edx"){
        return new EdificioX(recursos);
    }
    return new Fundicao(recursos);
}

void Zona::adicionarTrabalhador(const std::string type) {
    ++num_trabalhadores;
    trabalhadores.push_back(contratarTrabalhador(type));
}

bool Zona::adicionarTrabalhador(Trabalhador* trabalhador) {
    if (trabalhador == nullptr){
        return false;
    }
    ++num_trabalhadores;
    trabalhadores.push_back(trabalhador);
    return true;
}

Trabalhador *Zona::contratarTrabalhador(const std::string type) {
    if (type == "mineiro"){
        return new Mineiro();
    } else if(type == "operario"){
        return new Operario();
    }
    return new Lenhador();
}

float Zona::trabalhar() {
    float recolha = 0;
    for (auto trabalhador: trabalhadores) {
        recolha += trabalhador->trabalhar(this);
    }
    return recolha;
}

void Zona::faseRecolha() {
    atualizarDadosTrabalhador();
    if(edificio && !edificio->atualizarDeposito(this)){
        deleteEdificio();
    }
}

void Zona::removerRecurso(Recurso* recurso, float &quantidade) {
    if (edificio){
        edificio->removerRecurso(recurso,quantidade);
    }
}

void Zona::despedir(int extra) {
    auto it = trabalhadores.begin();
    while(it != trabalhadores.end()){
        if((*it)->despedir(extra)){
            delete *it;
            trabalhadores.erase(it);
        }
        else{
            ++it;
        }
    }
    num_trabalhadores = trabalhadores.size();
}

bool Zona::melhorarEdificio() {
    if (edificio->getTipo() == "mnf" || edificio->getTipo() == "mnc" || edificio->getTipo() == "bat"){
        return edificio->proximoNivel();
    }
    return false;
}

bool Zona::ligarEdificio(){
    if (edificio){
        edificio->ligar();
        return true;
    }
    return false;
}

bool Zona::desligarEdificio(){
    if (edificio){
        edificio->desligar();
        return true;
    }
    return false;
}

void Zona::deleteEdificio() {
    edificio->destruir(jogo->getDinheiro());
    delete edificio;
    edificio = nullptr;
}

void Zona::atualizarDadosTrabalhador() {
    for (auto trabalhador: trabalhadores) {
        trabalhador->updateIndetificador();
    }
}

bool Zona::existeEdificio() {return edificio != nullptr;}

Trabalhador* Zona::removeTrabalhador(int id) {
    auto it = trabalhadores.begin();
    while(it != trabalhadores.end()){
        if ((*it)->getId() == id){
            break;
        }
        ++it;
    }
    if (it == trabalhadores.end()) {return nullptr;}

    Trabalhador* aux;
    aux = *it;
    trabalhadores.erase(it);
    num_trabalhadores = trabalhadores.size();
    return aux;
}

bool Zona::zonaAdjacente(std::string tipo, int fac) {
    std::vector<std::vector<int>> adjacencias {{1,0},{0,1},{-1,0},{0,-1}};
    for (auto i: adjacencias) {
        Zona *zona = jogo->getZona(i[0], i[1]);
        if (zona && zona->getTipo() == tipo){
            if (zona->transformarRecurso(fac)){
                return true;
            }
        }
    }
    return false;
}

bool Zona::findTrabalhador(int id){
    for (auto trabalhador: trabalhadores){
        if (trabalhador->getId() == id){
            return true;
        }
    }
    return false;
}

bool Zona::encontrarTrabalhador(std::string tipo) {
    for (auto trabalhador: trabalhadores)
        if (trabalhador->getTipo() == tipo){
            return true;
        }
    return false;
}

Edificio *Zona::getEdificio(int x, int y) {
    if (jogo->getZona(x,y)){return jogo->getZona(x,y)->edificio;}
    return nullptr;
}

int Zona::getEdificioLevel() const {
    if (edificio){return edificio->getLevel();}
    return 5;
}

Zona::~Zona() {
    for (auto trabalhador : trabalhadores){
        delete trabalhador;
    }
    delete edificio;
}

void Zona::associarIlha(Jogo *jogo) {this->jogo = jogo;}

std::string Zona::getTipoTrabalhador(int index) const{return trabalhadores[index]->getTipo();}

std::string Zona::getInfoTrabalhador(int index) const {return trabalhadores[index]->getInfo();}

int Zona::getNumTrabalhadores() const {return num_trabalhadores;}

std::string Zona::getTipoEdificio() const {return edificio == nullptr ? "   " : edificio->getTipo();}

int Zona::getEdificioStatus() const {return edificio == nullptr ?  0 : edificio->estaLigado();}

float Zona::getEdificioDeposito() const{return edificio == nullptr ?  0 :edificio->getDeposito();}

float Zona::getZonaDeposito() const {return 0;}

