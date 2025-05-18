#pragma once

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
class Fogo : public ObjetoDeJogo 
{
    public:
    Fogo(std::string nome, int posL, int posC, const SpriteBase &s) : ObjetoDeJogo(nome,posL,posC,s) {};
    ~Fogo(){};

    void apagarFogo();
    
    private:
};