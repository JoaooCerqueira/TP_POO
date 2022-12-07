#include "Config.h"
#include "GestorComandos.h"
#include <fstream>

bool Config::readFile(const std::string& file_name, Jogo& game) {
    std::ifstream file;
    file.open(file_name);
    GestorComandos command;

    if (!file.is_open()){
        return false;
    }

    std::string cmd_str;
    std::vector<std::string> args;
    while(getline(file,cmd_str)){
        args = command.splitargs(cmd_str);
        if (validarNumeroArgumentos(2, game, "<Trabalhador> ou <edificio> <tipo>")){
            int quantidade = string2Num(args[1], game);
            if (quantidade != -1){
                game.configuracao(args[0], quantidade);
            }
        }
    }
    file.close();
    return true;
}

bool Config::executar(std::vector<std::string>& args, Jogo& game) {
    if(validarNumeroArgumentos(2, game, "config <ficheiro>")){
        return readFile(args[1],game);
    }
    return false;
}