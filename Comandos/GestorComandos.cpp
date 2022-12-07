#include "GestorComandos.h"
#include "Exec.h"
#include "Cons.h"
#include "Next.h"
#include "Cont.h"
#include "Move.h"
#include "List.h"
#include "Liga.h"
#include "Desliga.h"
#include "debkill.h"
#include "Apaga.h"
#include "Vende.h"
#include "debcash.h"
#include "debed.h"
#include "Save.h"
#include "Load.h"
#include "Melhorar.h"
#include "Config.h"
#include "quit.h"
#include <sstream>

std::vector<std::string> GestorComandos::splitargs(std::string line) {
    std::istringstream iss(line);
    std::string arg;
    std::vector<std::string> args;
    while(iss >> arg){
        args.push_back(arg);
    }
    return args;
}

bool GestorComandos::handleComando(const std::string& line, Jogo &jogo){
    std::vector<std::string> args = splitargs(line);
    command = callCommand(args, jogo);
    if (command == nullptr){
        jogo.setError("comando",comamndos);
        return false;
    }
    return command->executar(args, jogo);
}

Comando* GestorComandos::callCommand(std::vector<std::string>& args, Jogo& game) {
    if ("exec" == args[0])
        return new Exec(args);
    else if("cons" == args[0])
        return new Cons(args);
    else if("cont" == args[0])
        return new Cont(args);
    else if("next" == args[0])
        return new Next(args);
    else if("liga" == args[0])
        return new Liga(args);
    else if("desliga" == args[0])
        return new Desliga(args);
    else if("move" == args[0])
        return new Move(args);
    else if("list" == args[0])
        return new List(args);
    else if("config" == args[0])
        return new Config(args);
    else if("vende" == args[0])
        return new Vende(args);
    else if("load" == args[0])
        return new Load(args);
    else if("melhorar" == args[0])
        return new Melhorar(args);
    else if("apaga" == args[0])
        return new Apaga(args);
    else if("save" == args[0])
        return new Save(args);
    else if("debcash" == args[0])
        return new debcash(args);
    else if("debed" == args[0])
        return new debed(args);
    else if("quit" == args[0])
        return new quit(args);
    else if("debkill" == args[0])
        return new debkill(args);
    else
        return nullptr;
}

GestorComandos::~GestorComandos() {
    delete command;
}


