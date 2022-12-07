#include "Cont.h"

bool Cont::executar(std::vector<std::string> &args, Jogo &game) {
    if (validarNumeroArgumentos(2, game, "cont <Trabalhador>")){
        if (encontrarTipo(trabalhadores, args[1], game))
            return game.adicionarTrabalhador(args[1]);
    }
    return false;
}