#include "Fantasmita.h"
#include "SDL/SDL_mixer.h"
Fantasmita::Fantasmita(Personaje *personaje)
{
    this->x=100;
    this->y=100;
    //w =45 * h=38

   this->sprites.push_back(IMG_Load("Enemies/enemy01.png"));
     this->sprites.push_back(IMG_Load("Enemies/enemy02.png"));
    this->sprites.push_back(IMG_Load("Enemies/enemy03.png"));

//this->sprites.push_back(IMG_Load("image1.png"));

    this->personaje=personaje;
    this->moviendose=true;
    //ctor
}

Fantasmita::~Fantasmita()
{
    //dtor
}

void Fantasmita::logica(Personaje *personaje)
{
      if(va_para_la_derecha)
        this->x++;
    else
        this->x--;

    if(x>400)

            va_para_la_derecha=false;
    if(x<50)

        va_para_la_derecha=true;


if(personaje->personaje_x+36>this->x && personaje->personaje_x<this->x+45
            && personaje->personaje_y+40>this->y && personaje->personaje_y<this->y+38)
                {
            Mix_Music *music ;
            Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
            music = Mix_LoadMUS( "beat.wav" );
            Mix_PlayMusic( music, -1 );
            this->colision=true;

                }


}



