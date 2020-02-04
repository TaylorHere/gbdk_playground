#ifndef BOARD_C
#define BOARD_C
#include <stdio.h>
#include <gb/drawing.h>
#include <gb/malloc.h>

#include "grid.c"
#include "ball.c"
#include "block.c"

typedef struct Board{
    Grid grid;
    Ball ball;
} Board;

Block block;
Block colored;

void Board_new(Board *const me, int grid_rows, int grid_cols, int grid_size){
    Grid_new(&me->grid, grid_rows, grid_cols, grid_size);
    Grid_fill(&me->grid, &block);
    Ball_new(&me->ball, 0, 0);
}

void Board_ball_goes_left(Board *const me){
    Ball_move_by(&me->ball, 0, me->grid.grid_size);
    Grid_set_block(&me->grid, Ball_get_X(&me->ball), Ball_get_Y(&me->ball), &colored);
}

void Board_ball_goes_up(Board *const me){
    Ball_move_by(&me->ball, me->grid.grid_size, 0);
    Grid_set_block(&me->grid, Ball_get_X(&me->ball), Ball_get_Y(&me->ball), &colored);
}

void Board_ball_goes_down(Board *const me){
    Ball_move_by(&me->ball, -(me->grid.grid_size), 0);
    Grid_set_block(&me->grid, Ball_get_X(&me->ball), Ball_get_Y(&me->ball), &colored);
}

void Board_ball_goes_right(Board *const me){
    Ball_move_by(&me->ball, 0, -(me->grid.grid_size));
    Grid_set_block(&me->grid, Ball_get_X(&me->ball), Ball_get_Y(&me->ball), &colored);
}

void Board_del(Board *const me){
    Grid_del(&me->grid);
    Ball_del(&me->ball);
    free(me);
}
#endif
