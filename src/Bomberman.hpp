#pragma once

#include "Personagem.hpp"
#include <vector>
class Bomberman : public Personagem 
{
    public:
    Bomberman(std::string nome, int posL, int posC, const SpriteBase &s) : Personagem(nome,posL,posC,s), vidas(3){};
    ~Bomberman(){};

    void diminuirVida();
    void aumentarVida();

    void decisao(char entrada, std::vector<Bloco*> blocos, BombaHandler *handler) override;

    private:
    int vidas;
};