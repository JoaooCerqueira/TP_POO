#ifndef PROJECT_POO_NEXT_H
#define PROJECT_POO_NEXT_H

#include "Comando.h"

class Next : public Comando{
public:
    Next(std::vector<std::string> args) : Comando(args) {}
    bool executar(std::vector<std::string> &args, Jogo &game) override;
private:
};


#endif //PROJECT_POO_NEXT_H
