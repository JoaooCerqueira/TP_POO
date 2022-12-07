#ifndef PROJETO_POO_BUILDING_H
#define PROJETO_POO_BUILDING_H

#include <string>
#include "../Recursos/Recurso.h"
#include "../Jogo.h"

class Edificio {
public:
    Edificio(Recurso * recurso) : recurso(recurso){}
    Edificio(Edificio &outro,Recurso *recurso);
    Edificio &operator+=(float quantidade);
    Edificio &operator-=(float quantidade);

    virtual std::string getTipo() = 0;
    int getLevel() const;
    bool proximoNivel();
    bool estaLigado() const;
    void setDeposito(float deposito);
    float getDeposito() const;
    Recurso &getRecurso();

    virtual bool atualizarDeposito(Zona *zona);
    virtual void destruir(float &dinheiro) {*this -= deposito;}

    void transformarRecurso(float quantidade) {*this -= quantidade;}
    void removerRecurso(Recurso* recurso,float &quantidade);
    
    void ligar() { ligado = true;}
    void desligar() { ligado = false;}

    virtual Edificio * EdificioAdjacente(Zona *zona, std::string tipo);
    virtual Edificio *clone(std::vector<Recurso*> recursos) = 0;
    virtual ~Edificio();
private:
    int nivel = 1;
    bool ligado = false;
    Recurso* recurso;
    float deposito = 0;
};


#endif //PROJETO_POO_BUILDING_H
