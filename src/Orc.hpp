#pragma once

#include "Personagem.hpp"
class Orc : public Personagem 
{
    public:
    Orc(std::string nome, int posL, int posC, const SpriteBase &s) : Personagem(nome,posL,posC,s) {};
    ~Orc(){};

    void decisao() override;
    
    private:
};