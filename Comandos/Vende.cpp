#include "Vende.h"

bool Vende::executar(std::vector<std::string> &args, Jogo &game) {
    if (validarNumeroArgumentos(3, game, "vende <tipo> <quantidade> [ou] vende <linha> <coluna>")) {
        std::vector<int> cords = string2Coord({args[1], args[2]}, game);
        if (cords[0] != -1) {
            return game.venderEdificio(cords[0], cords[1]);
        }

        float quantidade = string2Num(args[2], game);
        if (quantidade != -1 && encontrarTipo(recursos, args[1], game)) {
            return game.venderRecurso(quantidade, args[1]);
        }

    }
    return false;
}