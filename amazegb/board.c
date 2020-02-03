#include "gb/gb.h"
#include "grid.c"
#include "ball.c"

typedef struct
{
    Grid *grid;
    Ball *ball;

} Board;

void Board_new(Board *const me, Grid *const grid, Ball *const ball){
    me->grid = grid;
    me->ball = ball;
}

void Board_ball_goes_left(Board *const me){}
void Board_ball_goes_up(Board *const me){}
void Board_ball_goes_down(Board *const me){}
void Board_ball_goes_right(Board *const me){}

void Board_del(Board *const me){
    Grid_del(me->grid);
    Ball_del(me->ball);

}
