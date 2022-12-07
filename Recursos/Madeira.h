#ifndef PROJECT_POO_MADEIRA_H
#define PROJECT_POO_MADEIRA_H

#include "Recurso.h"

class Madeira : public Recurso{
public:
    std::string getTipo() override;
    std::string getDescription() override;
    Recurso * clone() override;
private:
};


#endif //PROJECT_POO_MADEIRA_H
