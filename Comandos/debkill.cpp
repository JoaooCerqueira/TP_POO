#include "debkill.h"

bool debkill::executar(std::vector<std::string> &args, Jogo &game) {
    if(validarNumeroArgumentos(2, game, "debkill <id>")){
        int id = string2Num(args[1],game);
        if (id != -1){
            return game.apagarTrabalhador(id);
        }
    }
    return false;
}
