#include "gb/gb.h"
#include "gb/malloc.h"

typedef enum GridTypeEnum{
    empty = 0,
    block,
    ball,
    color,
    start
} GridType;

typedef struct {
    int rows;
    int cols;
    GridType *grids;
} Grid;

void Grid_new(Grid *const me, int rows, int cols){
    GridType **grids = (GridType **)malloc(sizeof(GridType *) * rows);
    int i;
    for (i = 0; i < rows; i++)
    {
        grids[i] = (GridType *)malloc(sizeof(GridType) * cols);	
    }
    me->rows = rows;
    me->cols = cols;
    me->grids = &grids;
}

void Grid_fill(Grid *const me, GridType grid_type) {
    int i, j;
    for (i = 0; i < me->rows; i++){
        for (j = 0; j < me->cols; j++) {
            ((GridType *)(me->grids[i]))[j] = grid_type;
        }
    }
}

void Grid_set_grid_type(Grid *const me, int row, int col, GridType grid_type){
    ((GridType *)(me->grids[row]))[col] = grid_type;
}

void Grid_del(Grid *const me) {
    int i;
    for (i = 0; i < me->rows; ++i)
    {
        free(*(me->grids + i));
    }
}
