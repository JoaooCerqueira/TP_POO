#ifndef PROJECT_POO_LIGA_H
#define PROJECT_POO_LIGA_H

#include "Comando.h"

class Liga : public Comando{
public:
    Liga(std::vector<std::string> args) : Comando(args) {}
    bool executar(std::vector<std::string> &, Jogo &) override;
private:
    int x,y;
};


#endif //PROJECT_POO_LIGA_H
