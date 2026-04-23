#ifndef HEADERS_H
#define HEADERS_H
#include <iostream>
#include <fstream>
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
        SDL_Renderer* getrenderer(){return renderer;}
        

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
    SDL_RenderClear(renderer);
}
void SDLinit::present(){
    SDL_RenderPresent(renderer);
}
class uinter{
    private:
        std::string  state;
        SDLinit& sdl;
    public:
        uinter(SDLinit &sdl);
        void update();
        void color();
};
uinter::uinter(SDLinit &osdl) : sdl(osdl){
    

}
void uinter::update(){
    std::ifstream file("state.txt");
    std::string line;
    std::getline(file,line);
    state=line[0];
    file.close();
    int k;
    if (state=="0" || state=="1"){
        k= std::stoi(state);
    }
    
    switch (k){
        case 0 :
            SDL_SetRenderDrawColor(sdl.getrenderer(),110,30,165,255);
            SDL_RenderFillRect(sdl.getrenderer(), NULL);
            break;
        case 1 :
            SDL_SetRenderDrawColor(sdl.getrenderer(),180,130,65,255);
            SDL_RenderFillRect(sdl.getrenderer(), NULL);
            break;
        
}
}

#endif