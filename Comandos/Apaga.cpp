#include "Apaga.h"

bool Apaga::executar(std::vector<std::string> &args, Jogo &game) {
    if (validarNumeroArgumentos(2, game, "apaga <nome>")){
        return game.apagaHistorico(args[1]);
    }
    return false;
}
