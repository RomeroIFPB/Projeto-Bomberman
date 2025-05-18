#pragma once

#include <list>
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
class PowerUpHandler : public ObjetoDeJogo 
{
    public:
    PowerUpHandler() : ObjetoDeJogo("PowerUpHandler",0,0,Sprite("rsc/SpriteHandler.img")) {};
    ~PowerUpHandler(){};

    void checaPowerUps();
    void posicionarPowerUp();

    private:
    std::list<PowerUp*> powerUps;
};