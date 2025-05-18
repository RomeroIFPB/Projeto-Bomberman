ESTRUTURA DE CLASSES DO PROJETO

Jogador

    Atributos:

        Vidas
        Bombas disponiveis
        Bombas max
        Vivo

    Métodos:

        morto()

        diminuirVida() - Quando acontecer um evento que tira a vida do jogador, chama esse método.
        aumentarvida() - Quando acontecer um evento que aumenta a vida do jogador, chama esse método.

        adicionarMaxBomba()
        
        soltarBomba( handler ) - Checa se há bombas disponíveis e chama o posicionarBomba do handler pra aquela posição
        recuperarBomba() - Quando acontecer um evento que vai fazer recuperar a bomba, chama isso

Bomba
    Atributos:
        pavio
        dono
    Métodos:
        explodir( handler de explosao ) - Se desativa, chama o posicionarexplosao e restitui uma bomba do dono
        queimarPavio() - Diminui o pavio

PowerUp

Bloco

Explosao

BombaHandler
    atributos:
        Lista de bombas

    métodos:
        diminuirPavios()
        PosicionarBomba
        ChecarExplosoes - Para cada explosao encontrada chama o bomba.explodir() e retira da lista de bombas. O desativarobj faz isso automaticamente?

ExplosaoHandler
    atributos:

    métodos:
        posicionarFogo()
        PosicionarExplosao() - Chama várias vezes o posicionarFogo com base nas coordenadas dadas, checa todas as direções até chegar numa parede, num bloco ou um personagem. faz a ação correspondente para cada um.

        ApagarFogo()
        ApagarExplosoes() - Chama apagar fogo varias vezes para desativar os fogos do mapa

PowerUp
    atributos:
        string tipo;
    métodos:
        serColetado()

PowerUpHandler
    atributos:
        Lista de powerups
    métodos:
        checaPowerUps()
        posicionarPowerUp()

Loop:

    Entrada
    Decisões
        jogador.decisao(entrada) - chama mover() ou soltarBomba()
        inimigo.decisao() - chama mover() ou soltarBomba()
        orc.decisao() - chama mover()

    Consequências diretas das decisões
        Foram chamadas pelos comandos de decisão

    Consequências indiretas das decisões
        explosaoHandler.apagaExplosoes()
        bombahandler.diminuirPavios()
        Handler.ChecarExplosoes() -> se o pavio das bombas tiver chegado a 0, chama o método explodir() -> o método explodir() chama o posicionarExplosao() -> posicionarExplosao() chama o posicionarFogo() -> posicionarFogo pode chamar a quebraDeBloco() ou a diminuirVida() -> A quebrarBloco() pode chamar a posicionarPowerUp()
        
        Se o jogador estiver na mesma posição de algum powerup, chama a powerUp.serColetado() e o powerUp chama o efeito correspondente


    Decisão sobre o estado geral do jogo
        jogador.morto()
        para cada inimigo
            inimigo.morto()
    Aplicar mudanças e renderizar
