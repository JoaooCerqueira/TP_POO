#ifndef PROJECT_POO_MERCADO_H
#define PROJECT_POO_MERCADO_H

#include <vector>
#include "../Recursos/Recurso.h"
#include "Preco.h"

class Mercado {
public:
    Mercado();
    int comprarEdificio(std::string tipo, int fac, float &dinheiro, Recurso* vigas_de_madeira);
    bool comprarTrabalhador(std::string tipo, float &dinheiro);
    void vende(std::string tipo, float &dinheiro);
    std::string getDescription(std::string);
    void modificar(std::string tipo, int quantidade);
    int melhorarEdificio(std::string tipo, float &dinheiro, Recurso* vigas_de_madeira);
    void vendeRecurso(float &dinheiro,float quantitade, std::string tipo);
private:
    int comprarMina(Preco preco, int fac, float &dinheiro, Recurso* vigas_de_madeira);

    std::vector<Preco> precos {
            Preco("operario",15),Preco("lenhador",20),
            Preco("mineiro",10),Preco("mnf",0,10),
            Preco("mnc",10,10),Preco("cen",15,10),
            Preco("bat",10,10),Preco("fun",10),
            Preco("edx",30)
    };
    std::vector<Preco> melhorar_edificio;
};


#endif //PROJECT_POO_MERCADO_H
