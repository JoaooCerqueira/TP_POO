#ifndef PROJECT_POO_GRUTA_H
#define PROJECT_POO_GRUTA_H

#include "ZonaRecurso.h"

class Gruta : public ZonaRecurso{
public:
    Gruta(std::vector<Recurso*> recursos) : ZonaRecurso(recursos[1]) {}
    Gruta(ZonaRecurso &zona, std::vector<Recurso*> recursos) : ZonaRecurso(zona, recursos,recursos[1]) {}
    std::string getTipo() override;
    void faseRecolha() override;
    Zona *clone(std::vector<Recurso *> recursos) override;
private:
    void atualizarDeposito();
};

#endif //PROJECT_POO_GRUTA_H
