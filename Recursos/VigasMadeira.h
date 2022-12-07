#ifndef PROJECT_POO_VIGASMADEIRA_H
#define PROJECT_POO_VIGASMADEIRA_H

#include "Recurso.h"

class VigasMadeira : public Recurso{
public:
    std::string getTipo() override;
    std::string getDescription() override;
    Recurso * clone() override;
private:
};


#endif //PROJECT_POO_VIGASMADEIRA_H
