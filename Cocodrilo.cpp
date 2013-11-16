#include "Cocodrilo.h"
#include "SDL/SDL_mixer.h"
Cocodrilo::Cocodrilo(Personaje*personaje)
{
    //ctor
    this->duracion_animacion=5;
     this->x=200;
    this->y=200;
    this->sprites.push_back(IMG_Load("characters/Enemies/enem/enem01.png"));
    this->sprites.push_back(IMG_Load("characters/Enemies/enem/enem02.png"));
    this->sprites.push_back(IMG_Load("characters/Enemies/enem/enem03.png"));
    this->personaje=personaje;
}

Cocodrilo::~Cocodrilo()
{
    //dtor
}



void Cocodrilo :: patron_Mov(){


      if(va_para_la_derecha)
        this->x++;
    else
        this->x--;

    if(x>400)

            va_para_la_derecha=false;
    if(x<50)

        va_para_la_derecha=true;

}
