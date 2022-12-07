#include "Comando.h"
#include <sstream>

float Comando::string2Num(std::string converter, Jogo& game) {
    float num;
    std::istringstream iss(converter);
    if (iss >> num){
        return num;
    }
    game.setError();
    return -1;
}

bool Comando::encontrarTipo(std::vector<std::string> tipos, std::string tipo, Jogo &game) {
    if(std::find(tipos.begin(),tipos.end(),tipo) != tipos.end()){
        return true;
    }
    game.setError("Lista",tipos);
    return false;
}

std::vector<int> Comando::string2Coord(std::vector<std::string> converter_coords, Jogo &game) {
    std::vector<int> cords;
    cords.push_back(string2Num(converter_coords[0], game) - 1);
    cords.push_back(string2Num(converter_coords[1], game) - 1);
    if (!game.verificarCordenadas(cords[0],cords[1])){
        std::fill(cords.begin(),cords.end(),-1);
    }
    return cords;
}

bool Comando::validarNumeroArgumentos(int size, Jogo &game, std::string string_erro) {
    if(args.size() != size){
        game.setError("Numero de argumentos Invalidos", string_erro);
        return false;
    }
    return true;
}

Comando::~Comando() {

}
