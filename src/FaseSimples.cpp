#include "FaseSimples.hpp"
#include "../ASCII_Engine/input/Keyboard.hpp"
#include "BombaHandler.hpp"
#include "ExplosaoHandler.hpp"
#include <algorithm>

void FaseSimples::init()
{
    // INICIALIZAR OBJETOS
    Keyboard::setMode(Keyboard::BLOCKING);
    
    // INICIALIZANDO BombaHandler
    b_handler = new BombaHandler();
    e_handler = new ExplosaoHandler();
    //objs.push_back(b_handler);
    //e_handler = new ExplosaoHandler();
    //objs.push_back(e_handler);
    //p_handler = new PowerUpHandler();
    //objs.push_back(p_handler);

    // INICIALIZANDO BOMBERMAN

    bomberman = new Bomberman("bomberman",8,7,Sprite("rsc/bomberman.img"));
    objs.push_back(bomberman);
    // INICIALIZANDO INIMIGO

    //inimigo = new Inimigo("inimigo",0,0,Sprite("rsc/inimigo.img"));
    //objs.push_back(inimigo);

    // INICIALIZANDO BLOCOS
    for(int linha = 0; linha < 10; linha++)
	{
		for(int coluna = 0; coluna < 25; coluna++)
		{
			if(matriz_blocos[linha][coluna] == 1)
			{
				int new_linha = 5 + (linha * 3);
				int new_coluna = 7 + (coluna * 7);
				blocos.push_back(new Bloco("Bloco", Sprite("rsc/bloco.img",COR::AZUL),new_linha,new_coluna));
			}
		}
	}

	for(auto bloco : blocos){
		objs.push_back(bloco);
	}

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
        if (tecla != -1) {  // Se foi lido algum caractere
                bomberman->decisao(tecla, blocos, b_handler);
                if (tecla == 'q') break;
        }

        //inimigo.decisao();

        // CONSEQUENCIAS DIRETAS
        
        // CONSEQUENCIAS INDIRETAS
        // QUEIMAR PAVIOS
        b_handler->diminuirPavios();

        // APAGAR EXPLOSOES DO FRAME ANTERIOR
        for (auto fogo : e_handler->getFogos()) 
        {
            fogo->desativarObj();
            auto it = std::find(objs.begin(), objs.end(), fogo);
            if (it != objs.end()) {
                objs.erase(it); // Remove a primeira ocorrência
            }
        }

        b_handler->checarExplosoes(e_handler);
        

        for (auto fogo : e_handler->getFogos()){
            objs.push_back(fogo);
        }

        // SÓ DEPOIS QUE AS BOMBAS JA TIVEREM SIDO EXPLODIDAS
        for (auto bomba : b_handler->getBombas()){
            objs.push_back(bomba);
        }

        // ESTADO GERAL DO JOGO
		update();
		draw(screen);
		system("clear");
		show(screen);

        usleep(50000);
        for (auto bomba : b_handler->getBombas()){
            std::cout << bomba->getPavio() << " " << bomba->getPavio() << std::endl;
        }
	}
    return 0;
}
