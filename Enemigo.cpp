#include "Enemigo.h"
#include <iostream>

Enemigo::Enemigo()
{
   va_para_la_derecha=true;
   this->iteracion=0;
    this->duracion_animacion=10;
    this->cuadro_actual=0;
    this->moviendose=true;
    this->colision=false;

    //ctor
}

Enemigo::~Enemigo()
{
    //dtor
}


 void Enemigo :: dibujar(SDL_Surface *screen)
 {
      if(this->moviendose){
                this->apply_surface(this->x,this->y,this->sprites[this->cuadro_actual],screen);

            }else{
                this->apply_surface(this->x,this->y,this->sprites[0],screen);
            }

        this->iteracion++;
       if(this->iteracion==this->duracion_animacion)
        {
            this->cuadro_actual++;
            if(this->cuadro_actual>=sprites.size()){
                this->cuadro_actual=0;
            }

                this->iteracion=0;
                this->moviendose=true;
        }
 }


void Enemigo::logica(Personaje *personaje)
{



     if(personaje->personaje_x+128>this->x && personaje->personaje_x<this->x+128
            && personaje->personaje_y+128>this->y && personaje->personaje_y<this->y+128)
                exit(0);



}

void Enemigo ::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

