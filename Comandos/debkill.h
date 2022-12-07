#ifndef PROJECT_POO_DEBKILL_H
#define PROJECT_POO_DEBKILL_H

#include "Comando.h"

class debkill : public Comando{
public:
    debkill(std::vector<std::string> args) : Comando(args) {}
    bool executar(std::vector<std::string> &args, Jogo &game) override;
private:
};


#endif //PROJECT_POO_DEBKILL_H
