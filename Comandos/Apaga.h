#ifndef PROJECT_POO_APAGA_H
#define PROJECT_POO_APAGA_H

#include "Comando.h"

class Apaga : public Comando{
public:
    Apaga(std::vector<std::string> args) : Comando(args) {}
    bool executar(std::vector<std::string> &args, Jogo &game) override;
private:
};


#endif //PROJECT_POO_APAGA_H
