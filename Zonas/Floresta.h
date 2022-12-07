#ifndef PROJETO_POO_FLOREST_H
#define PROJETO_POO_FLOREST_H

#include "ZonaRecurso.h"

class Floresta : public ZonaRecurso{
public:
    Floresta(Recurso *recurso) : ZonaRecurso(recurso) {}
    Floresta(ZonaRecurso &zona,std::vector<Recurso*> recursos) : ZonaRecurso(zona,recursos,recursos[4]){}
    std::string getTipo() override;
    void faseRecolha() override;
    Zona *clone(std::vector<Recurso *> recursos) override;
private:
    void atualizarDeposito();
    void novaArvore();

    float arvores = rand() % (40 - 20 + 1);
    float crescer = 0;
};


#endif //PROJETO_POO_FLOREST_H

