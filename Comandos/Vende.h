#ifndef PROJECT_POO_VENDE_H
#define PROJECT_POO_VENDE_H

#include "Comando.h"

class Vende : public Comando{
public:
    Vende(std::vector<std::string> args) : Comando(args) {}
    bool executar(std::vector<std::string> &, Jogo &) override;
private:
    std::vector<std::string> recursos {"ferro","carvao","eletricidade","aco","vigasmadeira","madeira"};
};


#endif //PROJECT_POO_VENDE_H
