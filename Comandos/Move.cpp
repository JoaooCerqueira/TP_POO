#include "Move.h"

bool Move::executar(std::vector<std::string> &args, Jogo &game) {
    if (validarNumeroArgumentos(4, game, "move <id> <linha> <coluna>")){
        std::vector<int> cords = string2Coord({args[2],args[3]},game);
        if (cords[0] != -1){
            return  game.moverTrabalhador((int)string2Num(args[1],game),cords[0], cords[1]);
        }
    }
    return false;
}