#pragma once

#include <list>
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "Fogo.hpp"

class ExplosaoHandler : public ObjetoDeJogo 
{
    public:
    ExplosaoHandler() : ObjetoDeJogo("ExplosaoHandler",Sprite("rsc/SpriteHandler.img"),0,0) {};
    ~ExplosaoHandler(){};

    void posicionarFogo(int posL, int posC){
        Fogo *fogo = new Fogo("Fogo",posL,posC,Sprite("rsc/fogo.img"));
        fogos.push_back(fogo);
    };

    void posicionarExplosao(int bombaPosL, int bombaPosC)
    {
        int nextPosLN = bombaPosL - 3;
        while(nextPosLN > 2)
        {
            this->posicionarFogo(nextPosLN, bombaPosC);
            nextPosLN -= 3;
        }
        int nextPosLS = bombaPosL + 3;
        while(nextPosLS < 38)
        {
            this->posicionarFogo(nextPosLS, bombaPosC);
            nextPosLS += 3;
        }
        int nextPosCE = bombaPosC - 7;
        while(nextPosCE > 2){
            this->posicionarFogo(bombaPosL, nextPosCE);
            nextPosCE -= 7;
        }

        int nextPosCD = bombaPosC + 7;
        while(nextPosCD < 140){
            this->posicionarFogo(bombaPosL, nextPosCD);
            nextPosCD += 7;
        }
    };
    
    void apagarExplosoes()
    {
        fogos.clear();
    };

    std::list<Fogo*> getFogos() const { return fogos; };
    
    private:
    std::list<Fogo*> fogos;
};