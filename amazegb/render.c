#include "gb/gb.h"
#include "gb/drawing.h"
#include "board.c"

void render(Board *const board){
    int x, y;
    for (x = 0; x < board->grid.cols * board->grid.grid_size; x += board->grid.grid_size)
    {
        for (y = 0; y < board->grid.rows * board->grid.grid_size; y += board->grid.grid_size)
        {
            box(x, y, x + board->grid.grid_size, y + board->grid.grid_size, M_NOFILL);
        }
    }
}
