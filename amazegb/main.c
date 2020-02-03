#include <stdio.h>
#include <gb/gb.h>
#include "board.c"


Board * initial_board(){
    Board board;
    Ball ball;
    Grid grid;
    Grid_new(&grid, 10, 10);
    Ball_new(&ball);
    Board_new(&board, &ball, &grid);
    return &board;
}

void frame_loop(Board *const board){
    while(1){
        switch(joypad()) {
            case J_LEFT:
                Board_ball_goes_left(&board);
                break;
            case J_RIGHT:
                Board_ball_goes_right(&board);
                break;
            case J_UP:
                Board_ball_goes_up(&board);
                break;
            case J_DOWN:
                Board_ball_goes_down(&board);
                break;
            case J_START:
                break;
            case J_SELECT:
                break;
            case J_A:
                break;
            case J_B:
                break;
        }
    }
}
void main(){
    frame_loop(initial_board());
}
