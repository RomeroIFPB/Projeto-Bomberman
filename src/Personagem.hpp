#pragma once

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "BombaHandler.hpp"
class Personagem : public ObjetoDeJogo 
{
    public:
    Personagem(std::string nome, int posL, int posC, const SpriteBase &s) : ObjetoDeJogo(nome,s,posL,posC), vivo(true), bombasMax(1), bombasDisponiveis(1) {};
    ~Personagem(){};

    
    bool getVivo() const;
    void adicionarMaxBombas(int maxBombas);
    void recuperarBomba();

    void morrer();
    void mover();
    void soltarBomba(BombaHandler handler);

    virtual void decisao() = 0;
    
    private:

    bool vivo;
    int bombasMax;
    int bombasDisponiveis;

};