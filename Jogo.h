#ifndef PROJETO_POO_GAME_H
#define PROJETO_POO_GAME_H

#include "Recursos/Recurso.h"
#include "Mercado/Mercado.h"
#include "Trabalhador/Trabalhador.h"
#include <vector>
#include <string>

class Zona;
class EstadoDoJogo;

class Jogo {
public:
    Jogo();
    Jogo(Jogo &outro);
    Jogo& operator=(Jogo& outro);
    void endGame();
    bool quitGame() const;
    int& IslandHeight();
    int& IslandWidth();

    std::string getUltimoErro();
    std::string desenharJogo();

    bool executar(std::string line);
    bool adicionarEdificio(std::string &tipo, int &x, int &y);
    bool adicionarEdificioGratis(std::string &tipo, int &x, int &y);
    bool ligarEdificio(const int &x, const int &y);
    bool desligarEdificio(const int &x, const int &y);
    bool melhorarEdificio(const int &x, const int &y);

    bool adicionarTrabalhador(const std::string &tipo);
    bool moverTrabalhador(const int id, const int &x, const int &y);
    bool apagarTrabalhador(int id);

    bool apagaHistorico(std::string nome);

    bool venderRecurso(float &remover, std::string tipo);
    bool venderEdificio(const int &x, const int &y);
    void configuracao(std::string tipo, int quantidade);

    Zona *getZona(int x,int y);
    float &getDinheiro() {return dinheiro;}
    void proximoDia();
    void informacaoGlobal();
    void informacaoZona(const int&, const int&);
    bool load(std::string file_name);
    bool save(std::string name);
    void criarIlha();
    void inicializarZonas();

    ~Jogo();
    void setError(std::string,std::vector<std::string>); //Invalid worker,edificio...
    void setError(std::string error_type, std::string aditional_msg = "");  //Invalid number of arguments
    void setError();    //coordinates not inside bound?
    bool verificarTamanhoIlha();
    int verificarCordenadas(int x, int y);
private:
    bool verificaFimDoJogo();
    void removerRecurso(Recurso *recurso,float &quantidade);
    Trabalhador *removerTrabalhador(const int id);
    int comprarEdificio(std::string &tipo, const int &x, const int &y);
    Recurso* encontrarRecurso(const std::string tipo);

    Zona* newZone(int index_zone);
    void deleteZones();

    bool quit = false;
    std::string error,draw;
    int altura,largura;
    int x,y;
    Zona*** ilha;
    int dia = 1;
    float dinheiro = 500;

    std::vector<Recurso*> inventario;

    std::vector<EstadoDoJogo*> historico;

    Mercado mercado;

    std::vector<std::vector<int>> pos_pas;
};

#endif //PROJETO_POO_GAME_H
