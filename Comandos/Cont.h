#ifndef PROJECT_POO_CONT_H
#define PROJECT_POO_CONT_H

#include "Comando.h"

class Cont : public Comando{
public:
    Cont(std::vector<std::string> args) : Comando(args) {}
    bool executar(std::vector<std::string> &, Jogo &) override;

private:
    std::vector<std::string> trabalhadores {"operario", "lenhador", "mineiro"};
};


#endif //PROJECT_POO_CONT_H
