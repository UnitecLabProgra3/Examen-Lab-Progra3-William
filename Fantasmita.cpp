#include "Fantasmita.h"

Fantasmita::Fantasmita(Personaje *personaje)
{
    this->x=100;
    this->y=100;

    this->sprites.push_back(IMG_Load("personajes/volador01.png"));
    this->sprites.push_back(IMG_Load("personajes/volador02.png"));
    this->sprites.push_back(IMG_Load("personajes/volador03.png"));
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



}



