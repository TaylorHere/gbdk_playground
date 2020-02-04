#include <gb/gb.h>
#include <stdio.h>
#include "game.c"
#include "render.c"

Game game;

int main()
{
    Game_new(&game, 7, 5, 28, 30, 5, 0, 0);
    while(1){
        Game_play(&game);
        Game_render_realtime(&game);
        if (!game.playing) {
            break;
        }
    }
    Game_del(&game);
}
