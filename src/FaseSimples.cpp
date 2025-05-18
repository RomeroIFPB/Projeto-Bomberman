#include "FaseSimples.hpp"
#include "../ASCII_Engine/input/Keyboard.hpp"

void FaseSimples::init()
{
    // INICIALIZAR OBJETOS
    Keyboard::setMode(Keyboard::NONBLOCKING);

    // INICIALIZANDO BOMBERMAN

    bomberman = new Bomberman("bomberman",10,0,Sprite("rsc/bomberman.img"));
    objs.push_back(bomberman);
    // INICIALIZANDO INIMIGO

    inimigo = new Inimigo("inimigo",0,0,Sprite("rsc/inimigo.img"));
    objs.push_back(inimigo);
}

unsigned FaseSimples::run(SpriteBuffer &screen)
{
    // COMANDO DE ENTRADA AQUI

	//PADRÃO
	screen.clear();
	draw(screen);
	system("clear");
	show(screen);
    
    while(true)
    {
		// COMANDO DE ENTRADA AQUI
        char tecla = Keyboard::read();

        // DECISOES DE JOGADOR
        if (tecla != '\0') { // É esse o modo de rodar o resto só com a entrada do jogador?
            bomberman.decisao(tecla);
        }

        inimigo.decisao();
        // CONSEQUENCIAS DIRETAS

        // ESTADO GERAL DO JOGO
		update();
		draw(screen);
		system("clear");
		show(screen);

        sleep(500);
	}
    return 0;
}