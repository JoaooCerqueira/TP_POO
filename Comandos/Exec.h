#ifndef PROJECT_POO_EXEC_H
#define PROJECT_POO_EXEC_H

#include "Comando.h"

class Exec : public  Comando{
public:
    Exec(std::vector<std::string> args) : Comando(args) {}
    bool executar(std::vector<std::string>& args, Jogo& game) override;
    bool readFile(const std::string&,Jogo& game);
private:
};


#endif //PROJECT_POO_EXEC_H
