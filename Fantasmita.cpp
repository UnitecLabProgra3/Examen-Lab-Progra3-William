#include "Fantasmita.h"
#include "SDL/SDL_mixer.h"
Fantasmita::Fantasmita(Personaje *personaje)
{
    this->x=100;
    this->y=100;
    //w =45 * h=38

   this->sprites.push_back(IMG_Load("characters/Enemies/enemy/enemy01.png"));
     this->sprites.push_back(IMG_Load("characters/Enemies/enemy/enemy02.png"));
    this->sprites.push_back(IMG_Load("characters/Enemies/enemy/enemy03.png"));

//this->sprites.push_back(IMG_Load("image1.png"));

    this->personaje=personaje;
    this->moviendose=true;
    //ctor
}

Fantasmita::~Fantasmita()
{
    //dtor
}



void Fantasmita ::patron_Mov(){
     if(va_para_la_derecha)
        this->x++;
    else
        this->x--;

    if(x>400)

            va_para_la_derecha=false;
    if(x<50)

        va_para_la_derecha=true;


}



