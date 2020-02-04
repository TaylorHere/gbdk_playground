#include <stdio.h>
#include <gb/gb.h>
#include "game.c"
#include <gb/drawing.h>

Game game;

int main(){
    Game_new(&game, 7, 5, 28, 30, 5, 0, 0);
    while(1){
        Game_play(&game);
        Game_render_realtime(&game);
    }
    Game_del(&game);
}
