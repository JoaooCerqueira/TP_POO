#ifndef PROJECT_POO_DEBCASH_H
#define PROJECT_POO_DEBCASH_H

#include "Comando.h"

class debcash : public Comando{
public:
    debcash(std::vector<std::string> args) : Comando(args) {}
    bool executar(std::vector<std::string> &args, Jogo &game) override;
private:
};


#endif //PROJECT_POO_DEBCASH_H
