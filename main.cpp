#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character1, *character2;
SDL_Rect rect_background,rect_character;

int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Este es mi mensaje", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;

    character1 = IMG_LoadTexture(renderer, "derecha1.png");
    character2 = IMG_LoadTexture(renderer, "derecha2.png");
    SDL_QueryTexture(character1, NULL, NULL, &w, &h);
    rect_character.x = 0;
    rect_character.y = 0;
    rect_character.w = w;
    rect_character.h = h;

    //Main Loop
    int cont = 0;
    int aux = 0;

    int frame = 0;
    int animacion_personaje = 0;
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_w)
                {
                    rect_character.y--;
                }
                if(Event.key.keysym.sym == SDLK_a)
                {
                    rect_character.x--;
                }
                if(Event.key.keysym.sym == SDLK_s)
                {
                    rect_character.y++;
                }
                if(Event.key.keysym.sym == SDLK_d)
                {
                    rect_character.x++;
                }
            }
        }

        SDL_RenderCopy(renderer, background, NULL, &rect_background);

        if(animacion_personaje%2 == 0)
            SDL_RenderCopy(renderer, character1, NULL, &rect_character);
        else
            SDL_RenderCopy(renderer, character2, NULL, &rect_character);

        if(frame%200==0)
        {
            animacion_personaje++;
        }

        SDL_RenderPresent(renderer);
        frame++;
    }

	return 0;
}
