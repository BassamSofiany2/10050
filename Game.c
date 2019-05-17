/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdlib.h>
 
#define NUM_ROWS  6
#define NUM_COLUMNS  9
#define MAX  4
 
enum stype{
    NORMAL, OBSTACLE };
 
//colors of tokens
enum color {
    RED, BLU, GREEN, YELLOW, PINK, ORANGE
};
 
//defines a token.
//Note each token can be associated with a color
typedef struct token{
   enum color col;
}token;
 
//Defines a square of the board.
typedef struct square{
    //A square can be a NORMAL or an OBSTACLE square
     enum stype type;
     int  topOfStack;
     //the stack of tokens that can be placed on the board square
     token * squaretokens;
     enum color tokensColor[MAX];
}square;
 
 
 
/*
 * You need to fill this data structure
 * with the information about the player
 * such as a name and a color.
 */
typedef struct player{
    char name[20];
    enum color col;
 
}player;
 
 
 
int main(void) {
 
    //the board is defined as a 2-Dimensional array of squares
    square board[NUM_ROWS][NUM_COLUMNS];
 
    //an array containing the players (MAX 6 players)
    player players[6];
 }
