#include "Desliga.h"

bool Desliga::executar(std::vector<std::string> &args, Jogo &game) {
    if (validarNumeroArgumentos(3, game, "desliga <linha> <coluna>")){
        std::vector<int> cords = string2Coord({args[1],args[2]},game);
        if (cords[0] != -1){
            return game.desligarEdificio(cords[0], cords[1]);
        }
    }
    return false;
}