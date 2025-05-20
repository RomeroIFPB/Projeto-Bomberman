#pragma once

#include <list>
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "Bomba.hpp"

class BombaHandler : public ObjetoDeJogo 
{
    private:
    std::list<Bomba*> bombas;

    public:
    BombaHandler() : ObjetoDeJogo("BombaHandler",Sprite("rsc/SpriteHandler.img"),0,0) {};
    ~BombaHandler(){};

    void posicionarBomba(int posL, int posC, const Personagem *dono){
        Bomba *bomba = new Bomba("Bomba",posL, posC, dono, Sprite("rsc/bomba.img",COR::VERMELHA));
        bombas.push_back(bomba);
    };
    void diminuirPavios(){
        for(auto bomba : bombas){
            bomba->queimarPavio();
        }
    };

    void checarExplosoes(ExplosaoHandler *handler){
        for (auto bomba : bombas) {
            if (bomba->getPavio() <= 0) {
                bomba->explodir(handler);
            }
                
        }
    };
    std::list<Bomba*> getBombas() const { return bombas; };

};