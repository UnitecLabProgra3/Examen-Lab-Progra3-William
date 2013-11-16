#include "Bomba.h"
#include "SDL/SDL_mixer.h"
Bomba::Bomba(Personaje *personaje)
{
    this->x=200;
    this->y=200;
  this->sprites.push_back(IMG_Load("characters/Enemies/spike/spike01.png"));
  this->sprites.push_back(IMG_Load("characters/Enemies/spike/spike02.png"));
  this->sprites.push_back(IMG_Load("characters/Enemies/spike/spike03.png"));
    this->personaje=personaje;
    this->moviendose=true;
    //ctor

}

Bomba::~Bomba()
{
    //dtor
}



        void Bomba::patron_Mov(){

         if(va_para_la_derecha){
                this->y--;
            this->x++;
            }else{
                this->y++;
            this->x--;

            }
            if(this->x>400)
                    va_para_la_derecha=false;


            if(x<150)

                    va_para_la_derecha=true;






        }


