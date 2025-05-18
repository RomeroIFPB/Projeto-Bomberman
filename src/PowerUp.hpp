#pragma once

#include <string>
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
class PowerUp : public ObjetoDeJogo 
{
    public:
    PowerUp(std::string nome, std::string tipo, int posL, int posC, const SpriteBase &s) : ObjetoDeJogo(nome,posL,posC,s), tipo(tipo) {};
    ~PowerUp(){};

    void serColetado();
    
    private:
    std::string tipo;
};