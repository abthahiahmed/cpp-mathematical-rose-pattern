// Hi, I am Abthahi Ahmed, This code will generate mathematical rose pettern.
// This code is depended on some equation according to https://en.wikipedia.org/wiki/Rose_(mathematics)

#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
using namespace std;
void print(string str){ // Function to make python print :D
    cout<<str;
}
void println(string str){
    cout<<str<<endl;
}
int main(int argc, char **argv){
    // SDL Window Create    
    SDL_Window *win = SDL_CreateWindow("Mathematical Rose Pettern", 100,100, 640, 320, SDL_WINDOW_SHOWN);
    if(!win){
        cout<<"Error in creating Window"<<endl;
        exit(1);
    }
    // SDL Renderer Create  
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, 0);
    if(!ren){
        cout<<"Error in creating Renderer"<<endl;
        exit(1);
    }
    // Variables     
    SDL_Event event;
    SDL_Point point;
    float x = 320, y = 160, r= 100;
    float d = 3, n = 5; // Required D and N value
    float k = n/d; // Value of k
    float TWO_PI = 2*3.1416;
    bool running = true;
    // For Loop    
    for(float i = 0; i < TWO_PI * 10; i += 0.02){
        SDL_SetRenderDrawColor(ren, 255, 255, 255, i);
        r = 100 * cos(k * i); // Mathmatical Rose Pettern Equation for r(radius)
        float cx = r * cos(i);
        float cy = r * sin(i);
        SDL_RenderDrawPoint(ren, x+cx, y+cy);
    }
    while(running){
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT){
            running = false;
        }
        SDL_RenderPresent(ren);
    }
    if(running == false){
        print("Program Terminated.");
    }
    return 0;
}
