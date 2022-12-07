#ifndef PROJECT_POO_FERRO_H
#define PROJECT_POO_FERRO_H

#include "Recurso.h"

class Ferro : public Recurso{
public:
    std::string getTipo() override;
    std::string getDescription() override;
    Recurso * clone() override;
private:
};


#endif //PROJECT_POO_FERRO_H
