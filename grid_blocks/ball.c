#ifndef BALL_C
#define BALL_C
#include <gb/malloc.h>
#include <gb/drawing.h>

typedef struct {
    int x, y, min_x, min_y, max_x, max_y;
} Ball;

void Ball_new(Ball *const me, int x, int y, int min_x, int min_y, int max_x, int max_y) {
    me->y = y;
    me->x = x;
    me->min_x = min_x;
    me->min_y = min_y;
    me->max_x = max_x;
    me->max_y = max_y;
}


int Ball_get_y(Ball *const me){
    if (me->y <= me->min_y){
        me->y = me->min_y;
    } else if (me->y > me->max_y){
        me->y = me->max_y;
    }
    return me->y;
}

int Ball_get_x(Ball *const me){
    if (me->x <= me->min_x){
        me->x = me->min_x;
    } else if (me->x > me->max_x){
        me->x = me->max_x;
    }
    return me->x;
}


void Ball_set_y(Ball *const me, int y){
    if (y <= me->min_y){
        me->y = me->min_y;
    } else if (me->y > me->max_y){
        me->y = me->max_y;
    } else {
        me->y = y;
    }
}

void Ball_set_x(Ball *const me, int x){
    if (x <= me->min_x){
        me->x = me->min_x;
    } else if (me->x > me->max_x){
        me->x = me->max_x;
    } else {
        me->x = x;
    }
}

void Ball_left_move(Ball *const me, int steps){
    me->x -= steps;
    Ball_set_x(me, me->x);
}

void Ball_up_move(Ball *const me, int steps){
    me->y -= steps;
    Ball_set_y(me, me->y);
}

void Ball_right_move(Ball *const me, int steps){
    me->x += steps;
    Ball_set_x(me, me->x);
}

void Ball_down_move(Ball *const me, int steps){
    me->y += steps;
    Ball_set_y(me, me->y);
}


void Ball_del(Ball *const me){
    free(me);
}

#endif
