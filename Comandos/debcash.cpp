#include "debcash.h"

bool debcash::executar(std::vector<std::string> &args, Jogo &game) {
    int dinheiro;
    if(validarNumeroArgumentos(2, game, "debcash <valor>")){
        dinheiro = string2Num(args[1],game);
        if (dinheiro != -1){
            game.getDinheiro() += dinheiro;
            return true;
        }
    }
    return false;
}
