#ifndef GRID_C
#define GRID_C
#include <gb/malloc.h>
#include "block.c"

typedef struct {
    int rows, cols, size;
    Block ***grids;
} Grid;

void Grid_malloc(Grid *const me, int rows, int cols){
    int i;
    me->grids = (Block ***)malloc(sizeof(Block *) * rows);
    for (i = 0; i < rows; i++){
        me->grids[i] = (Block **)malloc(sizeof(Block) * cols);	
    }
}

void Grid_new(Grid *const me, int rows, int cols, int size){
    Grid_malloc(me, rows, cols);
    me->size = size;
    me->cols = cols;
    me->rows = rows;
}

void Grid_fill(Grid *const me, Block *const block) {
    int i, j;
    for (i = 0; i < me->rows; i++){
        for (j = 0; j < me->cols; j++) {
            me->grids[i][j] = block;
        }
    }
}

void Grid_set_block(Grid *const me, int row, int col, Block *const block){
    me->grids[row][col] = block;
}

Block * Grid_get_block(Grid *const me, int row, int col){
    return me->grids[row][col];
}
void Grid_del(Grid *const me) {
    int i;
    for (i = 0; i < me->rows; ++i)
    {
        free(**(me->grids + i));
    }
    free(me);
}
#endif
