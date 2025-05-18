#pragma once

#include "Personagem.hpp"
class Inimigo : public Personagem
{
    public:
    Inimigo(std::string nome, int posL, int posC, const SpriteBase &s) : Personagem(nome,posL,posC,s) {};
    ~Inimigo(){};

    void decisao() override;
    private:
};