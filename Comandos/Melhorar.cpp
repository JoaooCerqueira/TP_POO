#include "Melhorar.h"

bool Melhorar::executar(std::vector<std::string> &args, Jogo &game) {
    if (validarNumeroArgumentos(3, game, "melhorar <linha> <coluna>")){
        std::vector<int> cords = string2Coord( {args[1],args[2]},game);
        if (cords[0] != -1){
            return game.melhorarEdificio(cords[0], cords[1]);
        }
    }
    return false;
}
