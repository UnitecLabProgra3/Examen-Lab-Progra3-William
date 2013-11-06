#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <vector>


class Personaje
{
    public:
        int iteracion;
        int cuadro_actual;
        int duracion_animacion;
        SDL_Surface *screen ;
        Personaje(int x, int y);
        virtual ~Personaje();
        int personaje_x;
        int personaje_y;
        std::vector<SDL_Surface*>sprites;
        bool moviendose;
        void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL );

        void dibujar(SDL_Surface *screen);

    protected:
    private:

};

#endif // PERSONAJE_H
