#pragma once

#include <list>
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "Fogo.hpp"

class ExplosaoHandler : public ObjetoDeJogo 
{
    public:
    ExplosaoHandler() : ObjetoDeJogo("ExplosaoHandler",0,0,Sprite("rsc/SpriteHandler.img")) {};
    ~ExplosaoHandler(){};

    void posicionarFogo();
    void posicionarExplosao();
    void apagarExplosoes();
    
    private:
    std::list<*Fogo> fogos;
};