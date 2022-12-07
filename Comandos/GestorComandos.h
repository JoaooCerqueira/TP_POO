#ifndef PROJECT_POO_GESTORCOMANDOS_H
#define PROJECT_POO_GESTORCOMANDOS_H

#include "Comando.h"

class GestorComandos {
public:
    bool handleComando(const std::string& line, Jogo& jogo);
    std::vector<std::string> splitargs(std::string);
    ~GestorComandos();
private:
    Comando* callCommand(std::vector<std::string>&, Jogo&);
    Comando* command = nullptr;
    std::vector<std::string> comamndos{
        "cont <trabalhador> - Contrata um trabalhador",
        "cons <edificio> - Constroi um edificio",
        "config <texto> - Altera os precos dos Edificios e Trabalhadores",
        "desliga <linha> <coluna> - Desliga edificio",
        "liga <linha> <coluna> - Liga edificio",
        "list <linha> <coluna> - Informacao dessa zona",
        "list - Informacao global",
        "next - Avanca um dia no jogo",
        "move <id> <linha> <coluna> - Move um trabbalador para outra zona",
        "vende <tipo> - Vende um recurso",
        "vende <linha> <coluna> - Vende o edificio (so o dinheiro)"
        "apaga <nome> - apaga o historico",
        "debcash <quantidade> - adiciona dinheiro",
        "debed <tipo > <linha> <coluna> - adiciona um edificio sem gastar",
        "debkill <id> - remove um trabalhador",
        "melhorar <linha> <coluna> - evolui o nivel do edicicio",
        "quit - termina o jogo",
        "save <nome> - guarda o estado atual do jogo",
        "load <nome> - abre um estado anterior do jogo"
    };
};

#endif //PROJECT_POO_GESTORCOMANDOS_H