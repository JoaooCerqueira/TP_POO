#ifndef PROJECT_POO_CONS_H
#define PROJECT_POO_CONS_H

#include "Comando.h"

class Cons : public Comando{
public:
    Cons(std::vector<std::string> args) : Comando(args) {}
    bool executar(std::vector<std::string>& args, Jogo& game) override;
private:
    const std::vector<std::string> edificios {"mnf", "mnc", "cen","bat","fun","edx"};
};

#endif //PROJECT_POO_CONS_H
