#ifndef PROJECT_POO_QUIT_H
#define PROJECT_POO_QUIT_H

#include "Comando.h"

class quit : public Comando{
public:
    quit(const std::vector<std::string> args) : Comando(args) {}
    bool executar(std::vector<std::string> &args, Jogo &game) override;
};


#endif //PROJECT_POO_QUIT_H
