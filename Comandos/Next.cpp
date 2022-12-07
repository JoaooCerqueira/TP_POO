#include "Next.h"

bool Next::executar(std::vector<std::string> &args, Jogo &game) {
    if (validarNumeroArgumentos(1, game, "next")){
        game.proximoDia();
        return true;
    }
    return false;
}


