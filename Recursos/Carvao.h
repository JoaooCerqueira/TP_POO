#ifndef PROJECT_POO_CARVAO_H
#define PROJECT_POO_CARVAO_H

#include "Recurso.h"

class Carvao : public Recurso{
public:
    std::string getTipo() override;
    std::string getDescription() override;
    Recurso * clone() override;
private:
};


#endif //PROJECT_POO_CARVAO_H
