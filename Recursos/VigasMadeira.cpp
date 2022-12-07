#include "VigasMadeira.h"

std::string VigasMadeira::getTipo() {
    return "vigasmadeira";
}

std::string VigasMadeira::getDescription() {
    return "Vigas de Madeira: " + Recurso::getDescription();
}

Recurso *VigasMadeira::clone() {
    return new VigasMadeira(*this);
}
