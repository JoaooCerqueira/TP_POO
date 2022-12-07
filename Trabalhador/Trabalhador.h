#ifndef PROJETO_POO_WORKER_H
#define PROJETO_POO_WORKER_H

#include <string>

class Zona;

class Trabalhador {
public:
    Trabalhador();
    void setInfo();
    int getDia();
    int getId();

    virtual std::string getTipo() = 0;
    std::string getInfo();

    virtual bool despedir(int adicional);
    virtual float trabalhar(Zona *zona);
    virtual void updateIndetificador();

    virtual Trabalhador *clone() = 0;
    virtual ~Trabalhador();
private:
    std::string info;
    int id;
    int dia = 1;
    inline static int novo_id = 0;
};

#endif //PROJETO_POO_WORKER_H
