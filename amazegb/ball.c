#include <gb/malloc.h>

typedef struct Ball{
    int x;
    int y;
} Ball;

void Ball_new(Ball *const me, int x, int y) {
    me->x = x;
    me->y = y;
}

int Ball_get_X(Ball *const me){
    return me->x;
}

int Ball_get_Y(Ball *const me){
    return me->y;
}

void Ball_move_by(Ball *const me, int byX, int byY){
    me->x += byX;
    me->y += byY;
}

void Ball_del(Ball *const me){
    free(me);
}
