#pragma once

#include <iostream>
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "ExplosaoHandler.hpp"

class Personagem;

class Bomba : public ObjetoDeJogo 
{
    public:
    Bomba(std::string nome, int posL, int posC, const Personagem *d, const SpriteBase &s) : ObjetoDeJogo(nome,s,posL,posC) , pavio(3), dono(d){};
    ~Bomba(){};

    void explodir(ExplosaoHandler *handler){
        handler->posicionarExplosao(this->getPosL(), this->getPosC());
        this->desativarObj();
    };
    void queimarPavio(){
        pavio--;
    };

    int getPavio() const {
        return pavio;
    };

    private:
    
    int pavio;
    const Personagem* dono;

};