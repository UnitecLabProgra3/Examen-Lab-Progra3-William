/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <iostream>
#include "Personaje.h"
#include <vector>
#include "Enemigo.h"
#include "Fantasmita.h"
#include "Bomba.h"
#include "Cocodrilo.h"
#include "LLama.h"
#include "SDL/SDL_mixer.h"
#include "Timer.h"
#include <sstream>

//The frames per second
const int FRAMES_PER_SECOND = 60;

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The surfaces
Mix_Music *music ;
Mix_Music *title ;
Mix_Music *soundtrack ;
SDL_Surface *background = NULL;
SDL_Surface *enter = NULL;
//SDL_Surface *up = NULL;
//SDL_Surface *down = NULL;
//SDL_Surface *left = NULL;
//SDL_Surface *right = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

//The font
TTF_Font *font = NULL;

//The color of the font
SDL_Color textColor = { 0, 0, 0 };

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Press an Arrow Key", NULL );

    //If everything initialized fine
    return true;
}

bool load_files()
{
    //Load the background image
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    //Load the background image
    background = IMG_Load( "back.png" );


    //Open the font
    font = TTF_OpenFont( "Orange Juice.ttf", 72 );

    //If there was a problem in loading the background
    if( background == NULL )
    {
        return false;
    }

    //If there was an error in loading the font
    if( font == NULL )
    {
        return false;
    }

     music = Mix_LoadMUS( "beat.wav" );
     title= Mix_LoadMUS( "Title.ogg" );
     soundtrack = Mix_LoadMUS( "04 Palmtree Panic.ogg" );

    //If there was a problem loading the music
    if( music == NULL )
    {
        return false;
    }
    if( soundtrack == NULL )
    {
        return false;
    }

    if( title == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface( background );

  //  SDL_FreeSurface( up );
    //SDL_FreeSurface( down );
    //SDL_FreeSurface( left );
    //SDL_FreeSurface( right );

    //Close the font
    //TTF_CloseFont( font );

    //Quit SDL_ttf
    Mix_FreeMusic( music );
     Mix_FreeMusic( soundtrack );
     Mix_FreeMusic( title );
    TTF_Quit();

    //Quit SDL
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Keep track of the current frame
    int frame = 0;


    //The frame rate regulator
    Timer fps;

    //Timer used to update the caption
    Timer update;

    //Quit flag
    bool quit = false;
    bool quit2 = false;


    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //Load the files
    if( load_files() == false )
    {
        return 1;
    }

    SDL_Surface*meta =IMG_Load("meta1.png");
    SDL_Surface*gameOver =IMG_Load("GameOver.png");
    SDL_Surface*win =IMG_Load("win.png");
    SDL_Surface*menu =IMG_Load("menu002.png");

    Personaje *personaje=new Personaje(0,0);

    std::vector<Enemigo*> enemigos;

    enemigos.push_back(new Fantasmita(personaje));
    enemigos.push_back(new Bomba(personaje));
    enemigos.push_back(new LLama(personaje));
    enemigos.push_back(new Cocodrilo(personaje));



    //SDL_Surface *meta=IMG_Load("meta.png"); //

    //Render the text
   // up = TTF_RenderText_Solid( font, "Up", textColor );

   // down = TTF_RenderText_Solid( font, "Down", textColor );
    //left = TTF_RenderText_Solid( font, "Left", textColor );
   // right = TTF_RenderText_Solid( font, "Right", textColor );

    enter = TTF_RenderText_Solid( font, "Press Enter", textColor );
    Uint8 *keystates1 = SDL_GetKeyState( NULL );
    Mix_PlayMusic( title, -1 );




    while(quit2 ==false){



        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit2= true;
            }
        }


         if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }




        apply_surface( 0, 0, menu, screen );
        apply_surface( 150, 370, enter, screen );
        if(keystates1[SDLK_RETURN]){
            quit2=true;

        }




 }


    Mix_PlayMusic( soundtrack, -1 );



    //Start the update timer
        update.start();

    //Start the frame timer
        fps.start();



    //While the user hasn't quit
    while( quit == false )
    {




        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        //Apply the background

    apply_surface( 0, 0, background, screen );


//    apply_surface(400,300,meta,screen);



        personaje->dibujar(screen);

        apply_surface(550,400,meta ,screen);
        for(int i=0;i<enemigos.size();i++)
          enemigos[i]->dibujar(screen);

        for(int i=0;i<enemigos.size();i++)
          enemigos[i]->logica(personaje);

        for(int i=0;i<enemigos.size();i++)
          enemigos[i]->patron_Mov();

        for(int i=0;i<enemigos.size();i++){
        if(enemigos[i]->colision)
        apply_surface(0,0,gameOver ,screen);
        }



         if(personaje->personaje_x+36>550 && personaje->personaje_x<600
            && personaje->personaje_y+40>400 && personaje->personaje_y<450){

            Mix_PlayMusic( music, -1 );


             apply_surface(0,0,win ,screen);


            }



        //Get the keystates
        Uint8 *keystates = SDL_GetKeyState( NULL );

        //If up is pressed
        if( keystates[ SDLK_UP ] )
        {
          //  apply_surface( ( SCREEN_WIDTH - up->w ) / 2, ( SCREEN_HEIGHT / 2 - up->h ) / 2, up, screen );
            personaje->personaje_y--;
            personaje->moviendose=true;
        }

        //If down is pressed
        if( keystates[ SDLK_DOWN ] )
        {
       //     apply_surface( ( SCREEN_WIDTH - down->w ) / 2, ( SCREEN_HEIGHT / 2 - down->h ) / 2 + ( SCREEN_HEIGHT / 2 ), down, screen );
            personaje->personaje_y++;
            personaje->moviendose=true;
        }


        //If left is pressed
        if( keystates[ SDLK_LEFT ] )
        {
//            apply_surface( ( SCREEN_WIDTH / 2 - left->w ) / 2, ( SCREEN_HEIGHT - left->h ) / 2, left, screen );
             personaje->personaje_x--;
             personaje->moviendose=true;

        }

        //If right is pressed
        if( keystates[ SDLK_RIGHT ] )
        {
//            apply_surface( ( SCREEN_WIDTH / 2 - right->w ) / 2 + ( SCREEN_WIDTH / 2 ), ( SCREEN_HEIGHT - right->h ) / 2, right, screen );
            personaje->personaje_x++;
            personaje->moviendose=true;
        }

        if( keystates[ SDLK_SPACE ] )
        {

        }

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }


         frame++;

        //If we want to cap the frame rate
        if(fps.get_ticks() < (1000 / FRAMES_PER_SECOND ) )
        {
            //Sleep the remaining frame time
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }

        //If a second has passed since the caption was last updated
        if( update.get_ticks() > 1000 )
        {
            //The frame rate as a string
            std::stringstream caption;

            //Calculate the frames per second and create the string
            caption << "Average Frames Per Second: " << frame / ( fps.get_ticks() / 1000.f );

            //Reset the caption
            SDL_WM_SetCaption( caption.str().c_str(), NULL );

            //Restart the update timer
            update.start();
        }


        }

        clean_up();

    return 0;
}
