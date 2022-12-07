#ifndef PROJECT_POO_ACO_H
#define PROJECT_POO_ACO_H

#include "Recurso.h"

class Aco : public Recurso{
public:
    std::string getTipo() override;
    std::string getDescription() override;
    Recurso * clone() override;
private:
};


#endif //PROJECT_POO_ACO_H
