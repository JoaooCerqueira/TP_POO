#ifndef PROJECT_POO_RECURSO_H
#define PROJECT_POO_RECURSO_H

#include <string>

class Recurso {
public:
    Recurso() = default;
    Recurso& operator-=(float quantidade);
    Recurso& operator+=(float quantidade);

    virtual std::string getTipo() = 0;
    void update(float quantidade);
    float getQuantidade() const;
    virtual std::string getDescription();
    virtual Recurso* clone() = 0;
    virtual ~Recurso();
private:
    float quantidade = 0;
};


#endif //PROJECT_POO_RECURSO_H
