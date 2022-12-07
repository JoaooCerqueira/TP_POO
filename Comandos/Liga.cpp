#include "Liga.h"

bool Liga::executar(std::vector<std::string> &args, Jogo &game) {
    if (validarNumeroArgumentos(3, game, "liga <linha> <coluna>")){
        std::vector<int> cords = string2Coord({args[1],args[2]},game);
        if (cords[0] != -1){
            return game.ligarEdificio(cords[0], cords[1]);
        }
    }
    return false;
}