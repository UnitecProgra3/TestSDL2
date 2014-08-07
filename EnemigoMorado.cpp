#include "EnemigoMorado.h"

EnemigoMorado::EnemigoMorado(SDL_Renderer* renderer)
{
    this->renderer=renderer;
    textura = IMG_LoadTexture(renderer,"enemigo3.png");
    SDL_QueryTexture(textura, NULL, NULL, &rectangulo.w, &rectangulo.h);
    rectangulo.x = 0;
    rectangulo.y = 0;
}

EnemigoMorado::~EnemigoMorado()
{
    //dtor
}

void EnemigoMorado::logica()
{
    rectangulo.x++;
    rectangulo.y++;
}
