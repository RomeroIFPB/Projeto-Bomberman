#include "Personagem.hpp"
#include <iostream>

void Personagem::soltarBomba(BombaHandler *handler)
{
    handler->posicionarBomba(this->getPosL(), this->getPosC(), this);
}