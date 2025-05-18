#pragma once

#include "Personagem.hpp"
class Bomberman : public Personagem 
{
    public:
    Bomberman(std::string nome, int posL, int posC, const SpriteBase &s) : Personagem(nome,posL,posC,s), vidas(3){};
    ~Bomberman(){};

    void diminuirVida();
    void aumentarVida();
    void decisao(char entrada) override;

    private:
    int vidas;
};