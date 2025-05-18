#pragma once

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
class Bloco : public ObjetoDeJogo 
{
    public:
    // Construtores
    Bloco(std::string nome, const SpriteBase &s, int posL, int posC) :  ObjetoDeJogo(nome, s, posL, posC){};
    ~Bloco(){};

    void quebrarBloco();
    
    private:
};