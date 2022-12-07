#include "debed.h"

bool debed::executar(std::vector<std::string> &args, Jogo &game) {
    if(validarNumeroArgumentos(4, game, "debed <tipo> <linha> <coluna>")){
        std::vector<int> cords = string2Coord({args[2],args[3]},game);
        if (cords[0] != -1 && encontrarTipo(edificios,args[1],game)){
            return game.adicionarEdificioGratis(args[1],cords[0],cords[1]);
        }
    }
    return false;
}
