#ifndef PROJECT_POO_MOVE_H
#define PROJECT_POO_MOVE_H

#include "Comando.h"

class Move : public Comando{
public:
    Move(std::vector<std::string> args) : Comando(args) {}
    bool executar(std::vector<std::string> &args, Jogo &jogo) override;
};


#endif //PROJECT_POO_MOVE_H
