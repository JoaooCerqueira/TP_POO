#ifndef PROJECT_POO_LOAD_H
#define PROJECT_POO_LOAD_H

#include "Comando.h"

class Load : public Comando{
public:
    Load(std::vector<std::string> args) : Comando(args) {}
    bool executar(std::vector<std::string> &args, Jogo &game) override;
};


#endif //PROJECT_POO_LOAD_H
