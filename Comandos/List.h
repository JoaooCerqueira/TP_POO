#ifndef PROJECT_POO_LIST_H
#define PROJECT_POO_LIST_H

#include "Comando.h"

class List : public Comando{
public:
    List(std::vector<std::string> args) : Comando(args) {}
    bool validarNumeroArgumentos(int size, Jogo &game, std::string string_erro) override;
    bool executar(std::vector<std::string> &, Jogo &) override;
private:
};


#endif //PROJECT_POO_LIST_H
