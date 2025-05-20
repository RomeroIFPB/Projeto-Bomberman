#include "Bomberman.hpp"
#include <iostream>

void Bomberman::decisao(char entrada, std::vector<Bloco*> blocos, BombaHandler *handler)
{
        int posL = this->getPosL(), posC = this->getPosC();

        if (entrada == 'w'){
            bool podeAndar = true;
            for(auto bloco : blocos){
                if((this->getPosL() - 3 == bloco->getPosL()) && this->getPosC() == bloco->getPosC()){
                    podeAndar = false;
                    break;
                }
            }
            if(podeAndar == true && this->getPosL() - 3 != 2){
                this->moveUp(3);
            }
        }
        else if (entrada == 's'){
            bool podeAndar = true;
            for(auto bloco : blocos){
                if((this->getPosL() + 3 == bloco->getPosL()) && this->getPosC() == bloco->getPosC()){
                    podeAndar = false;
                    break;
                }
            }
            if(podeAndar == true && this->getPosL() + 3 != 38){
                this->moveDown(3);
            }
            
        }
        else if (entrada == 'a'){
            bool podeAndar = true;
            for(auto bloco : blocos){
                if(this->getPosC() - 7 == bloco->getPosC() && this->getPosL() == bloco->getPosL()){
                    podeAndar = false;
                    break;
                }
            }
            if(podeAndar == true && this->getPosC() - 7 != 0){
                this->moveLeft(7);
            }
        }
        else if (entrada == 'd'){
            bool podeAndar = true;
            for(auto bloco : blocos){
                if(this->getPosC() + 7 == bloco->getPosC() && this->getPosL() == bloco->getPosL()){
                    podeAndar = false;
                    break;
                }
            }
            if(podeAndar == true && this->getPosC() + 7 != 140){
                this->moveRight(7);
            }
        }
        else if (entrada == 'l'){
            this->soltarBomba(handler);
        }
}