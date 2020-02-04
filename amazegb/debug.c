#include <gb/gb.h>
#include <stdio.h>
#include "board.c"
#include "render.c"

Board board;

int main()
{
    Board_new(&board, 25, 25, 5);
    while(1){render(&board);}
    Board_del(&board);
}
