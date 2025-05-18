#pragma once

#include <list>
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "Bomba.hpp"

class BombaHandler : public ObjetoDeJogo 
{
    private:
    Sprite s = Sprite("../rsc/SpriteHandler.img");
    std::list<Bomba*> bombas;

    public:
    BombaHandler() : ObjetoDeJogo("BombaHandler",s,0,0) {};
    ~BombaHandler(){};

    void posicionarBomba();
    void diminuirPavios();
    void checarExplosoes();

};