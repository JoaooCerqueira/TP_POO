#ifndef PROJECT_POO_PRECO_H
#define PROJECT_POO_PRECO_H

#include "../Recursos/Recurso.h"
#include <vector>

class Preco {
public:
    Preco(std::string tipo,int preco,float recurso = 0) : preco(preco) , tipo(tipo) , recurso(recurso) {}
    std::string getTipo() const;
    int getPreco() const;
    std::string getDescricao();
    float getRecurso() const;
    void setRecurso(float recurso);
    void setPreco(int preco);
private:
    std::string tipo;
    int preco = 0;
    float recurso = 0;
};

#endif //PROJECT_POO_PRECO_H
