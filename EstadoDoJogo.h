#ifndef PROJECT_POO_ESTADODOJOGO_H
#define PROJECT_POO_ESTADODOJOGO_H

#include "Jogo.h"

class EstadoDoJogo {
public:
    EstadoDoJogo(const std::string nome,Jogo *outro) :nome(nome) , jogo(*outro) {}
    void loadJogo(Jogo &jogo);
    std::string getName() const {return nome;}
private:
    std::string nome;
    Jogo jogo;
};

#endif //PROJECT_POO_ESTADODOJOGO_H
