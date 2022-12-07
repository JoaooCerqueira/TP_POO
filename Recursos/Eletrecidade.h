#ifndef PROJECT_POO_ELETRECIDADE_H
#define PROJECT_POO_ELETRECIDADE_H

#include "Recurso.h"

class Eletrecidade : public Recurso{
public:
    std::string getTipo() override;
    std::string getDescription() override;
    Recurso * clone() override;
private:
};


#endif //PROJECT_POO_ELETRECIDADE_H
