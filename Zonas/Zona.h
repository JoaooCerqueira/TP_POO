#ifndef PROJETO_POO_ZONE_H
#define PROJETO_POO_ZONE_H

#include "../Jogo.h"
#include "../Edificios/Edificio.h"
#include "../Trabalhador/Trabalhador.h"
#include <string>
#include <vector>

class Zona {
public:
    Zona() = default;
    Zona(Zona &outro,std::vector<Recurso*> recursos);
    virtual std::string getTipo() = 0;
    void associarIlha(Jogo *jogo);
    bool zonaAdjacente(std::string tipo, int fac);

    std::string getTipoTrabalhador(int index) const;
    std::string getInfoTrabalhador(int index) const;
    int getNumTrabalhadores() const;
    std::string getTipoEdificio() const;
    int getEdificioStatus() const;
    int getEdificioLevel() const;
    float getEdificioDeposito() const;
    virtual float getZonaDeposito() const;

    bool adicionarEdificio(const std::string tipo, std::vector<Recurso*> recursos);
    void deleteEdificio();
    bool existeEdificio();
    bool ligarEdificio();
    bool desligarEdificio();
    bool melhorarEdificio();
    Edificio *getEdificio(int x, int y);

    void adicionarTrabalhador(const std::string type);
    bool adicionarTrabalhador(Trabalhador* trabalhador);
    bool findTrabalhador(int id);
    Trabalhador* removeTrabalhador(int id);
    bool encontrarTrabalhador(std::string tipo);

    virtual void removerRecurso(Recurso *recurso, float &quantidade);
    virtual void faseRecolha();

    virtual Zona *clone(std::vector<Recurso *> recursos) = 0;
    virtual ~Zona();
protected:
    virtual bool transformarRecurso(int quantidade) {return false;}
    float trabalhar();
    void despedir(int extra = 0);
private:
    Trabalhador* contratarTrabalhador(const std::string type);
    Edificio* construirEdificio(const std::string tipo, std::vector<Recurso*> recursos);
    void atualizarDadosTrabalhador();

    Jogo *jogo;
    Edificio *edificio = nullptr;
    std::vector<Trabalhador*> trabalhadores;
    int num_trabalhadores = 0;
};


#endif //PROJETO_POO_ZONE_H