#include "List.h"

bool List::validarNumeroArgumentos(int size, Jogo &game, std::string string_erro) {
    if(!(size == 1 || size == 3)){
        game.setError("Nummero de argumentos Invalidos","list ou list <linha> <coluna>");
        return false;
    }
    return true;
}

bool List::executar(std::vector<std::string> &args, Jogo &game) {
    if(!validarNumeroArgumentos(args.size(), game, std::string())){
        return false;
    }
    if (args.size() == 1){
        game.informacaoGlobal();
    }
    else {
        std::vector<int> cords = string2Coord({args[1],args[2]},game);
        if (cords[0] == -1){
            game.setError("Cordenadas invalidas tente novamente","list <linha> <coluna>");
            return false;
        }
        game.informacaoZona(cords[0], cords[1]);
    }
    return true;
}
