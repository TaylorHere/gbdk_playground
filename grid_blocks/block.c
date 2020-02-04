#ifndef BLOCK_C
#define BLOCK_C
#include <gb/malloc.h>

typedef struct{
    int color;
} Block;


void Block_new(Block *const me, int color){
    me->color = color;
}

void Block_del(Block *const me){
    free(me);
}

#endif
