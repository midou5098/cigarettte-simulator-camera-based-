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


int ROWS=6,COLS=6;
double fps=12.0f;






class SDLinit{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        TTF_Font* font;
        TTF_Font* font2;
    public:
        SDLinit(std::string title,int w,int h);
        ~SDLinit();
        void clear();
        void present();
        void drawtext(int x,int y,const std::string &text,bool ch);
        void drawbut(int x,int y,int w,int h,int r,int g,int b,const std::string &text);
        SDL_Renderer* getrenderer(){return renderer;}
        

};



SDLinit::SDLinit(std::string title,int w,int h){
    SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    font=TTF_OpenFont("font.ttf",25);
    font2=TTF_OpenFont("font2.ttf",40);
    window=SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w,h,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
}
SDLinit::~SDLinit(){
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}
void SDLinit::clear(){
    SDL_SetRenderDrawColor(renderer,156,90,60,255);
    SDL_RenderClear(renderer);
}
void SDLinit::present(){
    SDL_RenderPresent(renderer);
}
void SDLinit::drawtext(int x,int y,const std::string &text,bool ch){
    SDL_Color textColor;
    switch(ch){
        case true:
            textColor = {240, 160, 125, 255};
            break;
        case false:
            textColor = {130, 60, 25, 255};

    }
    SDL_Surface* surf=TTF_RenderText_Solid(font,text.c_str(),textColor);
    int tw = surf->w;
    int th = surf->h;
    SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
    
    SDL_Rect rect={x,y,tw,th};
    SDL_RenderCopy(renderer,tex,NULL,&rect);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(tex);
}
void SDLinit::drawbut(int x,int y,int w,int h,int r,int g,int b,const std::string &text){
    SDL_SetRenderDrawColor(renderer,r,g,b,255);
    SDL_Rect rect6={x,y,w,h};
    SDL_RenderFillRect(renderer,&rect6);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderDrawRect(renderer,&rect6);
    SDL_Color textColor = {140, 60, 105, 255};
    SDL_Surface* surf=TTF_RenderText_Solid(font2,text.c_str(),textColor);
    SDL_Texture* tex=SDL_CreateTextureFromSurface(renderer,surf);
    SDL_Rect rect5={x+27,y+10,w-50,h-30};
    SDL_RenderCopy(renderer,tex,NULL,&rect5);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(tex);
    
}


































class uinter{
    private:
        std::string  state;
        SDLinit& sdl;
        SDL_Texture* marlboro;
        SDL_Texture* oris;
        SDL_Texture* cuba;
        int chooice;
    public:
        uinter(SDLinit &sdl);
        void update();
        void color();
        bool mouse(int x,int y,int w,int h,int mx,int my);
        void handle(SDL_Event event,int* mode);
        void layout(int mode);
};
uinter::uinter(SDLinit &osdl) : sdl(osdl){
    SDL_Surface* marl=IMG_Load("assets/marl_show.png");
    marlboro=SDL_CreateTextureFromSurface(sdl.getrenderer(),marl);
    SDL_FreeSurface(marl);
    SDL_Surface* ori=IMG_Load("assets/oris_show.png");
    oris=SDL_CreateTextureFromSurface(sdl.getrenderer(),ori);
    SDL_FreeSurface(ori);
    SDL_Surface* cub=IMG_Load("assets/cuba_show.png");
    cuba=SDL_CreateTextureFromSurface(sdl.getrenderer(),cub);
    SDL_FreeSurface(cub);






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
void uinter::handle(SDL_Event event,int* mode){
    if(event.type==SDL_KEYDOWN){
        SDL_Keycode key=event.key.keysym.sym;
        if(key==SDLK_ESCAPE && mode!=0){
            *mode=0;
        }
    

    }else if (event.type==SDL_MOUSEBUTTONDOWN){
        int mx=event.button.x;
        int my=event.button.y;
        if(mouse(875,70,370,50,mx,my)){
            chooice=1;
        }else if(mouse(890,200,370,50,mx,my)){
            chooice=2;
        }else if(mouse(845,280,400,70,mx,my)){
            chooice=3;
        }
       
    }

}
bool uinter::mouse(int x,int y,int w,int h,int mx,int my){
    if(mx>x && mx<x+w && my>y && my<y+h){
        return true;
    }
    return false;

}



void uinter::layout(int mode){
    switch(mode){
        case 0 :
            SDL_Rect mar={830,-50,500,300};
            SDL_RenderCopy(sdl.getrenderer(),marlboro,NULL,&mar);
            sdl.drawtext(700,90,"marlboro red",chooice==1);


            SDL_Rect ories={810,70,530,300};
            SDL_RenderCopy(sdl.getrenderer(),oris,NULL,&ories);
            sdl.drawtext(700,205,"oris(for bitches) ",chooice==2);

            SDL_Rect cubas={810,190,480,250};
            SDL_RenderCopy(sdl.getrenderer(),cuba,NULL,&cubas);
            sdl.drawtext(700,310,"cuban cigars ",chooice==3);


            sdl.drawbut(540,500,200,100,245, 230, 211,"smoke !");


    }
}
#endif