#include <gb/malloc.h>

typedef enum GridTypeEnum{
    empty = 0x00,
    block,
    ball,
    colored,
    start,
    end
} GridType;

typedef struct Grid {
    int rows, cols, grid_size, **grids;
} Grid;


void Grid_malloc(Grid *const me, int rows, int cols){
    int i;
    me->grids = (int **)malloc(sizeof(int *) * rows);
    for (i = 0; i < rows; i++){
        me->grids[i] = (int *)malloc(sizeof(int) * cols);	
    }
}

void Grid_new(Grid *const me, int rows, int cols, int size){
    Grid_malloc(me, rows, cols);
    me->grid_size = size;
    me->cols = cols;
    me->rows = rows;
}

void Grid_fill(Grid *const me, GridType grid_type) {
    int i, j;
    for (i = 0; i < me->rows; i++){
        for (j = 0; j < me->cols; j++) {
            ((int *)(me->grids[i]))[j] = grid_type;
        }
    }
}

void Grid_set_grid_type(Grid *const me, int row, int col, GridType grid_type){
    ((GridType *)(me->grids[row]))[col] = grid_type;
}

GridType Grid_get_grid_type(Grid *const me, int row, int col){
    return ((GridType *)(me->grids[row]))[col];
}
void Grid_del(Grid *const me) {
    int i;
    for (i = 0; i < me->rows; ++i)
    {
        free(*(me->grids + i));
    }
    free(me);
}
