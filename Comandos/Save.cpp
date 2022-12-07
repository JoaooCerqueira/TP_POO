#include "Save.h"

bool Save::executar(std::vector<std::string> &args, Jogo &game) {
    if (validarNumeroArgumentos(2, game, "save <nome>")){
        return game.save(args[1]);
    }
    return true;
}

