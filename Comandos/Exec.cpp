#include "Exec.h"
#include "GestorComandos.h"
#include <fstream>

bool Exec::readFile(const std::string& file_name, Jogo& game) {
    std::ifstream file;
    file.open(file_name);

    if (!file.is_open()){
        return false;
    }

    std::string cmd_str;
    while(getline(file,cmd_str)){
        GestorComandos command;
        command.handleComando(cmd_str, game);
    }
    file.close();
    return true;
}

bool Exec::executar(std::vector<std::string>& args, Jogo& game) {
    if(validarNumeroArgumentos(2, game, "exec <ficheiro>")){
        return readFile(args[1],game);
    }
    return false;
}
