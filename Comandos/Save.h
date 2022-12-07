#ifndef PROJECT_POO_SAVE_H
#define PROJECT_POO_SAVE_H

#include "Comando.h"

class Save : public Comando{
public:
    Save(std::vector<std::string> args) : Comando(args) {}
    bool executar(std::vector<std::string> &args, Jogo &game) override;
private:
};


#endif //PROJECT_POO_SAVE_H
