#include "quit.h"

bool quit::executar(std::vector<std::string> &args, Jogo &game) {
    if (validarNumeroArgumentos(1, game, "quit")){
        game.endGame();
    }
    return false;
}
