#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "../ASCII_Engine/SpriteBuffer.hpp"
#include "FaseSimples.hpp"

class Game
{
    public:
        Game(){};
        ~Game(){};
        static void run()
        {
            SpriteBuffer screen(161,42,' '); // LARGURA , ALTURA

            FaseSimples fasesimples("fasesimples", Sprite("rsc/background.img"));
            fasesimples.init();
            fasesimples.run(screen);
        }
};

#endif // GAME_HPP