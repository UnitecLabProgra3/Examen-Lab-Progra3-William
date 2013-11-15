#include "LLama.h"
#include "SDL/SDL_mixer.h"


LLama::LLama(Personaje *personaje)
{
    this->duracion_animacion=5;
     this->x=200;
    this->y=200;
   this->sprites.push_back(IMG_Load("Enemies/fish01.png"));
   this->sprites.push_back(IMG_Load("Enemies/fish02.png"));

     this->personaje=personaje;
    //ctor
}

LLama::~LLama()
{
    //dtor
}



void LLama :: patron_Mov()
{

    if(va_para_la_derecha)
        this->y++;
    else
        this->y--;

    if(y>300)

            va_para_la_derecha=false;
    if(y<100)

        va_para_la_derecha=true;




}
