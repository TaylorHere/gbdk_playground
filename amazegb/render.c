#include "gb/gb.h"
#include "gb/drawing.h"
#include "board.c"

void render_intime(Board *const board){
    int x, y;
    for (x = board->init_x; x < board->grid.cols * board->grid.size; x += board->grid.size)
    {
        for (y = board->init_y; y < board->grid.rows * board->grid.size; y += board->grid.size)
        {
            box(x, y, x + board->grid.size, y + board->grid.size, M_NOFILL);
        }
    }
    circle(Board_get_ball_real_x(board), Board_get_ball_real_x(board), Board_get_ball_radius(board), M_FILL);
}
