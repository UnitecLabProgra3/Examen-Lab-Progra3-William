#include "LLama.h"
#include "SDL/SDL_mixer.h"


LLama::LLama(Personaje *personaje)
{
    this->duracion_animacion=5;
     this->x=200;
    this->y=200;
    this->sprites.push_back(IMG_Load("Llama/llama01.png"));
    this->sprites.push_back(IMG_Load("Llama/llama02.png"));
    this->sprites.push_back(IMG_Load("Llama/llama03.png"));

     this->personaje=personaje;
    //ctor
}

LLama::~LLama()
{
    //dtor
}

void LLama::logica(Personaje *personaje)
{

    if(va_para_la_derecha)
        this->y++;
    else
        this->y--;

    if(y>300)

            va_para_la_derecha=false;
    if(y<100)

        va_para_la_derecha=true;

        if(personaje->personaje_x+128>this->x && personaje->personaje_x<this->x+128
            && personaje->personaje_y+128>this->y && personaje->personaje_y<this->y+128)
                {
            Mix_Music *music ;
            Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
            music = Mix_LoadMUS( "beat.wav" );
            Mix_PlayMusic( music, -1 );
            this->colision=true;

                }

}
