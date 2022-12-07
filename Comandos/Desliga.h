#ifndef PROJECT_POO_DESLIGA_H
#define PROJECT_POO_DESLIGA_H

#include "Comando.h"

class Desliga : public Comando{
public:
    Desliga(std::vector<std::string> args) : Comando(args) {}
    bool executar(std::vector<std::string> &, Jogo &) override;
private:
};


#endif //PROJECT_POO_DESLIGA_H
