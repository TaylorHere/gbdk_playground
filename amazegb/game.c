#include "gb/gb.h"
#include "gb/drawing.h"
#include <gb/malloc.h>
#include "board.c"

typedef struct {
    Board board;
    int playing;
} Game;

void Game_new(Game *const me, int board_init_x, int board_init_y, int grid_rows, int grid_cols, int grid_size, int ball_x, int ball_y){
    me->board.init_y = board_init_y;
    me->board.init_x = board_init_x;
    Board_new(&me->board, grid_rows, grid_cols, grid_size, ball_x, ball_y);
}

void Game_play(Game *const me){

}

void Game_render_realtime(Game *const me){
    int x, y;
    for (x = me->board.init_x; x < me->board.grid.cols * me->board.grid.size; x += me->board.grid.size)
    {
        for (y = me->board.init_y; y < me->board.grid.rows * me->board.grid.size; y += me->board.grid.size)
        {
            box(x, y, x + me->board.grid.size, y + me->board.grid.size, M_NOFILL);
        }
    }
    circle(
        Board_get_ball_real_x(&me->board),
        Board_get_ball_real_y(&me->board),
        Board_get_ball_radius(&me->board),
        M_FILL);
}

void Game_del(Game *const me){
    Board_del(&me->board);
    free(me);
}
