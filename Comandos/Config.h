#ifndef PROJECT_POO_CONFIG_H
#define PROJECT_POO_CONFIG_H

#include "Comando.h"

class Config : public Comando{
public:
    Config(std::vector<std::string> args) : Comando(args) {}
    bool readFile(const std::string&,Jogo& game);
    bool executar(std::vector<std::string> &, Jogo &) override;
private:
};


#endif //PROJECT_POO_CONFIG_H
