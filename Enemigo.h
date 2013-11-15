#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <vector>
#include "Personaje.h"

class Enemigo
{
    public:
        Personaje *personaje;
        int x,y;
        bool colision;
        int iteracion;
        int cuadro_actual;
        int duracion_animacion;
        bool va_para_la_derecha;
        bool moviendose;
        std::vector <SDL_Surface*> sprites;
        SDL_Surface *screen;
        virtual void dibujar(SDL_Surface *screen);
        virtual void logica(Personaje *personaje);
        virtual void patron_Mov();
        virtual void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL );

        Enemigo();
        virtual ~Enemigo();
    protected:
    private:
};

#endif // ENEMIGO_H
