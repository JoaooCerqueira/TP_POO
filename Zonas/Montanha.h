#ifndef PROJETO_POO_MONTAIN_H
#define PROJETO_POO_MONTAIN_H

#include "ZonaRecurso.h"

class Montanha : public ZonaRecurso {
public:
    Montanha(Recurso *recurso) : ZonaRecurso(recurso) {}
    Montanha(ZonaRecurso &zona,std::vector<Recurso*> recursos) : ZonaRecurso(zona,recursos,recursos[0]) {}
    std::string getTipo() override;
    void faseRecolha() override;
    Zona * clone(std::vector<Recurso *> recursos) override;
private:
    void atualizarDeposito();
};

#endif //PROJETO_POO_MONTAIN_H
