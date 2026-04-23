#include "headers.h"



int main(void){
    SDLinit sdl("fuckass cigarette",1280,720);
    uinter uic(sdl);

    bool running =true;
    SDL_Event event;
    while(running){
        while(SDL_PollEvent(&event)){
            if (event.type==SDL_QUIT){
                running =false;
            }
        }
        sdl.clear();
        uic.update();
        sdl.present();


    }
    sdl.~SDLinit();
    return 0;

}
 