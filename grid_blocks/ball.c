#ifndef BALL_C
#define BALL_C
#include <gb/malloc.h>
#include <gb/drawing.h>

typedef struct {
    int x, y;
} Ball;

void Ball_new(Ball *const me, int x, int y) {
    me->y = y;
    me->x = x;
}

void Ball_left_move(Ball *const me, int steps){
    me->x -= steps;
}


void Ball_up_move(Ball *const me, int steps){
    me->y -= steps;
}

void Ball_right_move(Ball *const me, int steps){
    me->x += steps;
}

void Ball_down_move(Ball *const me, int steps){
    me->y += steps;
}

void Ball_del(Ball *const me){
    free(me);
}
#endif
