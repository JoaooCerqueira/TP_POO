#ifndef PROJECT_POO_MELHORAR_H
#define PROJECT_POO_MELHORAR_H

#include "Comando.h"

class Melhorar : public Comando{
public:
    Melhorar(const std::vector<std::string> args) : Comando(args) {}
    bool executar(std::vector<std::string> &args, Jogo &game) override;
};


#endif //PROJECT_POO_MELHORAR_H
