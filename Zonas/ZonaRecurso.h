#ifndef PROJECT_POO_ZONARECURSO_H
#define PROJECT_POO_ZONARECURSO_H

#include "Zona.h"

class ZonaRecurso : public Zona{
public:
    ZonaRecurso(Recurso *recurso) : recurso(recurso) {}
    ZonaRecurso(ZonaRecurso &zona,std::vector<Recurso*> recursos,Recurso *recurso) : recurso(recurso), deposito(zona.deposito) ,Zona(zona,recursos) {}

    std::string getTipo() = 0;
    void faseRecolha() = 0;
    Zona *clone(std::vector<Recurso *> recursos) = 0;

    bool transformarRecurso(int quantidade);
    void removerRecurso(Recurso *recurso, float &quantidade);
    float getZonaDeposito() const override {return deposito;}
protected:
    ZonaRecurso& operator+=(float quantidade);
    ZonaRecurso& operator-=(float quantidade);
private:
    Recurso *recurso;
    float deposito = 0;
};


#endif //PROJECT_POO_ZONARECURSO_H
