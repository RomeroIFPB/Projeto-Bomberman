#pragma once

#include <string>
#include "../ASCII_Engine/Fase.hpp"
#include "Bomberman.hpp"
#include "Inimigo.hpp"

class FaseSimples : public Fase
{
    public:
        FaseSimples(std::string nome, const SpriteBase &bkg) : Fase(nome, bkg) {};
        ~FaseSimples(){};

        void init() override;
        unsigned run(SpriteBuffer &screen) override;

    private:
        Bomberman *bomberman;
        Inimigo *inimigo;
};