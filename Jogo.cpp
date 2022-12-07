#include "Jogo.h"
#include "Recursos/Ferro.h"
#include "Recursos/Aco.h"
#include "Recursos/Carvao.h"
#include "Recursos/Eletrecidade.h"
#include "Recursos/Madeira.h"
#include "Recursos/VigasMadeira.h"
#include "Zonas/Montanha.h"
#include "Zonas/Gruta.h"
#include "Zonas/Pantano.h"
#include "Zonas/Pastagem.h"
#include "Zonas/Floresta.h"
#include "Zonas/Deserto.h"
#include "./Comandos/GestorComandos.h"
#include "EstadoDoJogo.h"
#include <cstdlib>
#include <ctime>
#include <sstream>

Jogo::Jogo(){
    srand(time(nullptr));

    inventario.push_back(new Ferro());
    inventario.push_back(new Carvao());
    inventario.push_back(new Aco());
    inventario.push_back(new Eletrecidade());
    inventario.push_back(new Madeira());
    inventario.push_back(new VigasMadeira());
}

Jogo::Jogo(Jogo &outro){
    dinheiro = outro.dinheiro;
    dia = outro.dia;
    largura = outro.largura;
    altura = outro.altura;
    mercado = outro.mercado;

    for(auto recurso : outro.inventario){
        inventario.push_back(recurso->clone());
    }

    criarIlha();

    for (int x = 0; x < altura; ++x) {
        for (int y = 0; y < largura; ++y) {
            ilha[x][y] = outro.ilha[x][y]->clone(inventario);
        }
    }
}

bool Jogo::quitGame() const{
    return quit;
}

void Jogo::criarIlha() {
    ilha = new Zona**[altura];
    for (int x = 0; x < altura; ++x){
        ilha[x] = new Zona*[largura];
    }
    for (int x = 0; x < altura; ++x){
        for (int y = 0; y < largura; ++y) {
            ilha[x][y] = nullptr;
        }
    }
}

void Jogo::inicializarZonas() {
    std::vector<int> distribuicao;
    distribuicao.resize(6);
    std::fill(distribuicao.begin(), distribuicao.end(), (largura * altura) / 6);
    for (int resto = 0; resto < (largura * altura) % 6; ++resto) {
        ++distribuicao[rand() % distribuicao.size()];
    }

    pos_pas.resize(distribuicao[3]);
    for (int zona = 0,quantidade = 0; zona < distribuicao.size(); ++zona, quantidade = 0) {
        while(quantidade != distribuicao[zona]){
            int x = rand() % altura, y = rand() % largura;
            if(ilha[x][y] == nullptr){
                if (zona == 3){
                    pos_pas[quantidade] = {x, y};
                }
                ilha[x][y] = newZone(zona);
                ilha[x][y]->associarIlha(this);
                ++quantidade;
            }
        }
    }
}

Zona *Jogo::newZone(int zone_index) {
    Zona *new_zone;
    switch (zone_index) {
        case 0:
            new_zone = new Montanha(inventario[0]);
            break;
        case 1:
            new_zone = new Deserto();
            break;
        case 2:
            new_zone = new Pantano();
            break;
        case 3:
            new_zone = new Pastagem();
            break;
        case 4:
            new_zone  = new Floresta(inventario[4]);
            break;
        case 5:
            new_zone  = new Gruta({inventario[0],inventario[1]});
            break;
    }
    return new_zone;
}


bool Jogo::executar(std::string line){
    if (!verificaFimDoJogo()) {return false;}
    GestorComandos comando;
    return comando.handleComando(line, *this);
}

bool Jogo::adicionarEdificio(std::string& tipo, int& x, int& y) {
    if (!ilha[x][y]->existeEdificio()){
        setError("Ja existe um edificio nessa zona");
    }
    float remover = comprarEdificio(tipo, x, y);
    if(remover == -1){
        setError("Nao tem inventario sufientes para comprar esse edificio",mercado.getDescription(tipo));
        return false;
    }
    removerRecurso(inventario[5], remover);
    ilha[x][y]->adicionarEdificio(tipo, inventario);
    return true;
}

bool Jogo::adicionarEdificioGratis(std::string &tipo, int &x, int &y) {
    if (!ilha[x][y]->existeEdificio()){
        setError("Ja existe um edificio nessa zona");
    }
    ilha[x][y]->adicionarEdificio(tipo, inventario);
    return true;
}


int Jogo::comprarEdificio(std::string &tipo, const int &x, const int &y) {
    if (ilha[x][y]->getTipo() == "mnt"){
        return mercado.comprarEdificio(tipo, 2,dinheiro,inventario[5]);
    }
    return mercado.comprarEdificio(tipo, 1,dinheiro,inventario[5]);
}

bool Jogo::ligarEdificio(const int &x, const int &y) {
    if(!ilha[x][y]->ligarEdificio()){
        setError("Nao existe edificio nessa zona");
        return false;
    }
    return true;
}

bool Jogo::desligarEdificio(const int &x, const int &y) {
    if(!ilha[x][y]->desligarEdificio()){
        setError("Nao existe edificio nessa zona");
        return false;
    }
    return true;
}

bool Jogo::verificaFimDoJogo() {
    int flag = 0;
    bool inventario_vazio = std::count_if(inventario.begin(), inventario.end(), [&] (Recurso * recurso) {return recurso->getQuantidade() == 0;}) == inventario.size();
    for (int x = 0; x < altura; ++x) {
        for (int y = 0; y < largura; ++y) {
            flag += ilha[x][y]->getNumTrabalhadores();
        }
    }
    if (!flag && !dinheiro && inventario_vazio){
        endGame();
        return false;
    }
    return true;
}


void Jogo::proximoDia() {
    ++dia;
    for (x = 0; x < altura; ++x ) {
        for (y = 0; y < largura; ++y) {
            ilha[x][y]->faseRecolha();
        }
    }
}

bool Jogo::venderRecurso(float &remover, std::string tipo) {
    Recurso *recurso = encontrarRecurso(tipo);
    if (remover <= recurso->getQuantidade() && remover > 0){
        mercado.vendeRecurso(dinheiro, remover, tipo);
        removerRecurso(recurso, remover);
        return true;
    }
    setError("Essa quantidade e invalida");
    return false;
}

void Jogo::removerRecurso(Recurso *recurso,float &quantidade) {
    for (int x = 0; x < largura; ++x) {
        for (int y = 0; y < altura; ++y) {
            ilha[x][y]->removerRecurso(recurso, quantidade);
        }
    }
}

bool Jogo::venderEdificio(const int &x, const int &y) {
    if (!ilha[x][y]->existeEdificio()){
        setError("Nao existe edificio nessa zona");
        return false;
    }
    mercado.vende(ilha[x][y]->getTipoEdificio(),dinheiro);
    ilha[x][y]->deleteEdificio();
    return true;
}

bool Jogo::melhorarEdificio(const int &x, const int &y) {
    if (ilha[x][y]->getEdificioLevel() == 5){
        setError("Ou nao existe edificio ou ja chegou o ao nivel maximo [5]");
        return false;
    }

    float remover = mercado.melhorarEdificio(ilha[x][y]->getTipoEdificio(),dinheiro,inventario[5]);
    if(remover == -1){
        setError("Nao tem recursos suficientes para melhorar o edificio");
        return false;
    }
    removerRecurso(inventario[5],remover);
    ilha[x][y]->melhorarEdificio();
    return true;
}


Recurso* Jogo::encontrarRecurso(const std::string tipo){
    auto it = inventario.begin();
    while(it != inventario.end()){
        if ((*it)->getTipo() == tipo){
            break;
        }
        ++it;
    }
    return *it;
}

bool Jogo::adicionarTrabalhador(const std::string &tipo) {
    if(!mercado.comprarTrabalhador(tipo,dinheiro)){
        setError("Nao tem inventario sufientes para comprar esse Trabalhador",tipo);
        return false;
    }
    int pastagem = rand() % pos_pas.size();
    ilha[pos_pas[pastagem][0]][pos_pas[pastagem][1]]->adicionarTrabalhador(tipo);
    return true;
}

void Jogo::configuracao(std::string tipo, int quantidade) {
    mercado.modificar(tipo, quantidade);
}

bool Jogo::moverTrabalhador(const int id, const int &x, const int &y) {
    Trabalhador* trabalhador = removerTrabalhador(id);
    if (!ilha[x][y]->adicionarTrabalhador(trabalhador)) {
        setError("O id do trabalhador nao existe", "Utilize o comando list para ver os trabalhadores existentes");
        return false;
    }
    return true;
}

Trabalhador *Jogo::removerTrabalhador(const int id) {
    for (int x = 0; x < largura; ++x) {
        for (int y = 0; y < altura; ++y) {
            if(ilha[x][y]->findTrabalhador(id)){
                return ilha[x][y]->removeTrabalhador(id);
            }
        }
    }
    return nullptr;
}

bool Jogo::apagarTrabalhador(int id) {
    Trabalhador *trabalhador = removerTrabalhador(id);
    if (trabalhador){
        delete(trabalhador);
        return true;
    }
    setError("Nao existe trabalhador com esse id");
    return false;
}

void Jogo::informacaoGlobal(){
    std::ostringstream oss;
    for (int x = 0; x < altura; ++x) {
        for (int y = 0; y < largura; ++y) {
            oss << "[Zona: " << ilha[x][y]->getTipo() << " " << x + 1 << "-" << y + 1 << "]" << std::endl <<  "Deposito da zona - " << ilha[x][y]->getZonaDeposito() << std::endl;
            oss << "Edificio: ";
            if (ilha[x][y]->getTipoEdificio() == "   "){
                oss << "nao existe";
            }
            else{
                oss << ilha[x][y]->getTipoEdificio() << "[" << (ilha[x][y]->getEdificioStatus() ? "ativo" : "inativo") << "]" << "\nArmazenamento: " << ilha[x][y]->getEdificioDeposito() <<  std::endl;
            }
            oss << "\nTrabalhadores:\n";
            if (ilha[x][y]->getNumTrabalhadores() == 0){
                oss << "nao existe\n";
            }
            else{
                for (int index = 0; index < ilha[x][y]->getNumTrabalhadores(); ++index) {
                    oss << "\n" << ilha[x][y]->getTipoTrabalhador(index) << " " << ilha[x][y]->getInfoTrabalhador(
                            index) << std::endl;
                }
            }
            oss << std::endl;
        }
    }
    draw = oss.str();
}

void Jogo::informacaoZona(const int& x, const int& y) {
    std::ostringstream oss;
    oss << "[Zona: " << ilha[x][y]->getTipo() << " " << x + 1 << "-" << y + 1 << "]" << std::endl <<  "Deposito da zona - " << ilha[x][y]->getZonaDeposito() << std::endl;
    oss << "Edificio: ";
    if (ilha[x][y]->getTipoEdificio() == "   "){
        oss << "nao existe";
    }
    else{
        oss << ilha[x][y]->getTipoEdificio() << "[" << (ilha[x][y]->getEdificioStatus() ? "ativo" : "inativo") << "]" << "\nArmazenamento: " << ilha[x][y]->getEdificioDeposito() <<  std::endl;
    }
    oss << "\nTrabalhadores:\n";
    if (ilha[x][y]->getNumTrabalhadores() == 0){
        oss << "nao existe\n";
    }
    else{
        for (int index = 0; index < ilha[x][y]->getNumTrabalhadores(); ++index) {
            oss << "\n" << ilha[x][y]->getTipoTrabalhador(index) << " " << ilha[x][y]->getInfoTrabalhador(
                    index) << std::endl;
        }
    }
    oss << std::endl;
    draw = oss.str();
}

std::string Jogo::desenharJogo() {
    std::ostringstream oss;
    oss << draw;
    oss << "Dia: " << dia << std::endl;
    oss << "Dinheiro: " << dinheiro << std::endl;
    for (int x = 0; x < altura; ++x) {
        for (int y = 0; y < largura; ++y) {
            oss << "----";
        }
        oss << std::endl;
        for (int y = 0; y < largura; ++y) {
            oss << "|" << ilha[x][y]->getTipo() ;
        }
        oss <<  "|" << std::endl;
        for (int y = 0; y < largura; ++y) {
            oss << "|" << ilha[x][y]->getTipoEdificio();
        }
        oss <<  "|" << std::endl;
        for (int y = 0; y < largura; ++y) {
            oss << "|";
            for (int index = 0; index < 3; ++index) {
                if (index < ilha[x][y]->getNumTrabalhadores()){
                    oss << ilha[x][y]->getTipoTrabalhador(index)[0];
                }
                else{
                    oss << " ";
                }
            }
        }
        oss <<  "|" << std::endl;
        for (int y = 0; y < largura; ++y) {
            oss << "|";
            std::ostringstream num_to_string;
            num_to_string << ilha[x][y]->getNumTrabalhadores();
            for (int index = 0; index < 3; ++index) {
                if (index < 3 - num_to_string.str().size()){
                    oss << " ";
                }
            }
            oss << ilha[x][y]->getNumTrabalhadores();
        }
        oss <<  "|" << std::endl;
    }
    oss << std::endl;
    for (auto recurso : inventario) {
        oss << recurso->getDescription() << std::endl;
    }
    draw.clear();
    return oss.str();
}

int & Jogo::IslandHeight() {
    return altura;
}

int & Jogo::IslandWidth() {
    return largura;
}

bool Jogo::verificarTamanhoIlha() {
    if ((altura < 3 || altura > 8) || (largura < 3 || largura > 16)){
        error = "[ERROR: As dimensoes nao sao validas]\n MIN:3x3 , MAX:8x16\n";
        return false;
    }
    return true;
}

int Jogo::verificarCordenadas(int x, int y) {
    if ((x < 0 || y < 0) || (x > largura - 1 || y > altura - 1)){
        setError();
        return false;
    }
    return true;
}

std::string Jogo::getUltimoErro() {
    return error;
}

void Jogo::setError(std::string error_type, std::string aditional_msg) {
    error = "[ERRO: " + error_type + "]\n" + aditional_msg;
}

void Jogo::setError(std::string error_type, std::vector<std::string> vector) {
    std::ostringstream oss;
    oss << "[ERRO: " << "Esse tipo de " <<  error_type << " nao existe]\n";
    for (auto it: vector) {
        oss << "[ " << it << " ]" << std::endl;
    }
    error = oss.str();
}

void Jogo::setError() {
    std::ostringstream oss;
    oss << "[ERRO: " << "As cordenadas devem estar dentro dos limites das ilha]\n" << altura << "x" << largura << "\n";
    error = oss.str();
}

Jogo::~Jogo() {
    deleteZones();
    for (auto recurso : inventario) {
        delete recurso;
    }

    for (auto h : historico) {
        delete h;
    }
}

void Jogo::deleteZones() {
    for (int x = 0; x < altura; ++x) {
        for (int y = 0; y < largura; ++y) {
            delete ilha[x][y];
        }
    }
    for (int x = 0; x < altura; ++x) {
        delete ilha[x];
    }
    delete ilha;
}

Zona *Jogo::getZona(int x, int y) {
    if (verificarCordenadas(this->x + x,this->y + y)){
        return ilha[this->x + x][this->y + y];
    }
    return nullptr;
}

bool Jogo::load(std::string file_name) {
    for (auto h : historico) {
        if (h->getName() == file_name){
            h->loadJogo(*this);
            return true;
        }
    }
    setError("Esse historico nao existe");
    return false;
}

bool Jogo::save(std::string name) {
    for (auto h: historico) {
        if(h->getName() == name){
            setError("Esse nome ja existe");
            return false;
        }
    }
    historico.push_back(new EstadoDoJogo(name,this));
    return true;
}

bool Jogo::apagaHistorico(std::string nome) {
    auto it = historico.begin();
    while(it != historico.end()){
        if ((*it)->getName() == nome){
            delete (*it);
            historico.erase(it);
            return true;
        }
        ++it;
    }
    setError("Esse nome nao existe");
    return false;
}

Jogo &Jogo::operator=(Jogo &outro) {
    if (this == &outro) return *this;

    dinheiro = outro.dinheiro;
    dia = outro.dia;
    largura = outro.largura;
    altura = outro.altura;
    mercado = outro.mercado;

    for(auto recurso : inventario){
        delete recurso;
    }
    inventario.clear();

    for(auto recurso : outro.inventario){
        inventario.push_back(recurso->clone());
    }



    for (int x = 0; x < altura; ++x) {
        for (int y = 0; y < largura; ++y) {
            ilha[x][y] = outro.ilha[x][y]->clone(inventario);
            ilha[x][y]->associarIlha(this);
        }
    }
    return *this;
}

void Jogo::endGame() {
    quit = true;
    error = "\n\n[FIM DO JOGO]\n\n";
}