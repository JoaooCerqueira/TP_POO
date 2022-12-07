#include "UserInterface.h"
#include <iostream>

UserInterface::UserInterface(Jogo &game) : game(game){}

void UserInterface::run() {
    getIslandSize();
    game.criarIlha();
    game.inicializarZonas();
    std::cout << game.desenharJogo() << std::endl;

    while(!game.quitGame()){
        getCommand();
        if(!game.executar(line)){
            std::cout << game.getUltimoErro() << std::endl;
        }
        else{
            std::cout << game.desenharJogo() << std::endl;
        }
    }
}

void UserInterface::getCommand() {
    std::cout << "Escreva um comando:\n";
    std::getline(std::cin,line);
    while(line.empty()){
        std::cout << "Por Favor introduza algo\n";
        std::cin.clear();
        std::getline(std::cin,line);
    }
}

void UserInterface::getIslandSize() {
    do {
        std::cout << game.getUltimoErro();
        std::cout << "Introduza as dimesoes da ilha\nAltura:";
        std::cin >>game.IslandHeight();
        std::cin.clear();std::cin.ignore(1,'\n');
        std::cout << "Largura:";
        std::cin >> game.IslandWidth();
        std::cin.clear();std::cin.ignore(1,'\n');
    }while(!game.verificarTamanhoIlha());
}