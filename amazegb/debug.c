#include <gb/gb.h>
#include <stdio.h>
#include "board.c"
#include "render.c"
// #include "gb/drawing.h"

Board board;

int main()
{
    Board_new(&board, 30, 30, 4);
    while(1){render(&board);}
    Board_del(&board);
}
