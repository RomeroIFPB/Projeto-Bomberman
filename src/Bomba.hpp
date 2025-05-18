#pragma once

#include "../ASCII_Engine/ObjetoDeJogo.hpp"

class Personagem;

class Bomba : public ObjetoDeJogo 
{
    public:
    Bomba(std::string nome, int posL, int posC, const Personagem *d, const SpriteBase &s) : ObjetoDeJogo(nome,s,posL,posC) , pavio(3), dono(d){};
    ~Bomba(){};

    void explodir();
    void queimarPavio();

    int getPavio() const;

    private:
    
    int pavio;
    const Personagem* dono;

};