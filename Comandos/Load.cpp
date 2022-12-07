#include "Load.h"

bool Load::executar(std::vector<std::string> &args, Jogo &game) {
    if (validarNumeroArgumentos(2, game, "load <nome>")){
        return game.load(args[1]);
    }
    return false;
}