#ifndef PROJECT_POO_COMANDO_H
#define PROJECT_POO_COMANDO_H

#include "../Jogo.h"
#include <vector>
#include <string>

class Comando {
public:
    Comando(const std::vector<std::string> args) : args(args) {}
    virtual bool validarNumeroArgumentos(int size, Jogo &game, std::string string_erro);
    virtual bool executar(std::vector<std::string>& args, Jogo& game) = 0;
    float string2Num(std::string converter, Jogo& game);
    std::vector<int> string2Coord(std::vector<std::string> converter_coords, Jogo& game);
    bool encontrarTipo(std::vector<std::string> tipos, std::string tipo, Jogo &game);

    virtual ~Comando();
private:
    std::vector<std::string> args;
};


#endif //PROJECT_POO_COMANDO_H
