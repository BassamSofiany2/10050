/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
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
 
 
 
 
void initialize_board(square board[NUM_ROWS][NUM_COLUMNS]);
void print_board(square board[NUM_ROWS][NUM_COLUMNS]);
void printLine();
 
int main(int argc, char** argv) {
 
    //the board is defined as a 2-Dimensional array of squares
    square board[NUM_ROWS][NUM_COLUMNS];
 
    //an array containing the players (MAX 6 players)
    player players[6];
 
    //the number of players
    int numPlayers =0;
 
    //creates the squares of the board
    initialize_board(board);
 
    //prints the board
    print_board(board);
 
    return 0;
 
 
 
}
 
void initialize_board(square board[NUM_ROWS][NUM_COLUMNS]){
    int i;
    for (i =0; i< NUM_ROWS; i++){
            int j;
        for(j =0; j < NUM_COLUMNS; j++){
            //creates an obstacle square at positions (0,3), (1,6), (2,4), (3,5), (4,2) and (5,7)
            if((i == 0 && j==3) || (i == 1 && j == 6) || (i ==2 && j ==4)
                    || (i == 3 && j ==5) || (i==4 && j==2) || (i==5 && j==7)){
                board[i][j].type = OBSTACLE;
            } else{
                //creates a normal square otherwise
                board[i][j].type = NORMAL;
            }
            board[i][j].squaretokens = NULL;
            board[i][j].topOfStack = -1;
        }
    }
}
 
char print_token(token *t){
    if((*t).col== PINK) return 'P';
    if((*t).col== RED) return 'R';
    if((*t).col== BLU) return 'B';
    if((*t).col== GREEN) return 'G';
    if((*t).col== ORANGE) return 'O';
    if((*t).col== YELLOW) return 'Y';
    return '\0';
}
 
void print_board(square board[NUM_ROWS][NUM_COLUMNS]){
    printf("                THE BOARD\n");
    int i;
    for(i =0; i < NUM_ROWS; i++){
 
        //prints an horizontal line
        printLine();
        //prints the row number
        printf(" %d ", i);
        char c = '\0' ;
        //if the square (i,j) is occupied,
        //c is assigned the initial of the color of the token that occupies the square
        int j;
        for (j= 0; j < NUM_COLUMNS; j++){
            if(board[i][j].squaretokens != NULL){
                c = print_token(board[i][j].squaretokens);
            }
            //if the square (i,j) is empty
            else{
                //c is assigned 'X' if the square represents an obstacle
                if(board[i][j].type == OBSTACLE)
                    c = 'X';
                //c is assigned an empty space otherwise
                else c = ' ';
            }
            printf("| %c ", c);
        }
        printf ("|\n");
    }
    printLine();
    //prints the number of the columns at the end of the board
    printf("     0   1   2   3   4   5   6   7   8\n");
}
 
void printLine(){
  printf("   -------------------------------------\n");
}
