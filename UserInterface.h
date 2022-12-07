#ifndef PROJETO_POO_USERINTERFACE_H
#define PROJETO_POO_USERINTERFACE_H

#include "Jogo.h"
#include <vector>
#include <string>

class UserInterface {
public:
    UserInterface(Jogo &);
    void run();

    void getIslandSize();
    void getCommand();
private:
    Jogo &game;
    std::string line;
};


#endif //PROJETO_POO_USERINTERFACE_H
