#ifndef HEADERS_H
#define HEADERS_H
#include <iostream>
#include <vector>
#include <string>
#include <stdbool.h>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfxPrimitives.h>









class SDLinit{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        TTF_Font* font;
    public:
        SDLinit(std::string title,int w,int h);
        ~SDLinit();
        void clear();
        void present();
        

};



SDLinit::SDLinit(std::string title,int w,int h){
    SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    font=TTF_OpenFont("font.ttf",25);
    window=SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w,h,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
}
SDLinit::~SDLinit(){
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}
void SDLinit::clear(){
    SDL_SetRenderDrawColor(renderer,90,150,40,255);
    SDL_RenderClear(renderer);
}
void SDLinit::present(){
    SDL_RenderPresent(renderer);
}


#endif