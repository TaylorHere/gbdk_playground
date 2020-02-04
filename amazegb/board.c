#ifndef BOARD_C
#define BOARD_C
#include <stdio.h>
#include <gb/drawing.h>
#include <gb/malloc.h>

#include "grid.c"
#include "ball.c"

typedef struct Board{
    Grid grid;
    Ball ball;
    int init_x, init_y;
} Board;

void Board_new(Board *const me, int grid_rows, int grid_cols, int grid_size, int ball_x, int ball_y){
    Grid_new(&me->grid, grid_rows, grid_cols, grid_size);
    Ball_new(&me->ball, ball_x, ball_y);
}

int Board_get_ball_radius(Board *const me){
    return (int)(me->grid.size / 2);
}
int Board_get_ball_real_x(Board *const me){
    return (me->ball.x * me->grid.size) + Board_get_ball_radius(me)+ me->init_x;
}

int Board_get_ball_real_y(Board *const me){
    return (me->ball.y * me->grid.size) + Board_get_ball_radius(me)+ me->init_y;
}

void Board_del(Board *const me){
    Grid_del(&me->grid);
    Ball_del(&me->ball);
    free(me);
}
#endif
