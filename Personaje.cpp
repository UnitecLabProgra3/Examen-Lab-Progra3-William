#include "Personaje.h"



Personaje::Personaje(int x,int y)
{
    this->personaje_x=x;
    this->personaje_y=y;
    this->iteracion=0;
    this->duracion_animacion=10;
    this->cuadro_actual=0;
    this->moviendose=false;
    sprites.push_back(IMG_Load("personajes/run01.png"));
    sprites.push_back(IMG_Load("personajes/run02.png"));
    sprites.push_back(IMG_Load("personajes/run03.png"));
    sprites.push_back(IMG_Load("personajes/run04.png"));
    //ctor
}

Personaje::~Personaje()
{
    //dtor
}
 void Personaje :: dibujar(SDL_Surface *screen)
 {
      if(this->moviendose){
                this->apply_surface(this->personaje_x,this->personaje_y,this->sprites[cuadro_actual],screen);

            }else{
                this->apply_surface(this->personaje_x,this->personaje_y,this->sprites[0],screen);
            }

        this->iteracion++;
       if(this->iteracion==this->duracion_animacion)
        {
            this->cuadro_actual++;
            if(this->cuadro_actual>=sprites.size())
                this->cuadro_actual=0;
                this->iteracion=0;
                this->moviendose=false;
        }
 }

 void Personaje ::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}
