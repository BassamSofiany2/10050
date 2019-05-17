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
int isCorrectToken(square board[NUM_ROWS][NUM_COLUMNS], player players[], int playerNumber, int rowCord, int colCord);
 
 
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
 
    //creates the players
    numPlayers = initialize_players(players);
 
    //asks each player to place their tokens
    //on the first column of the board
    place_tokens(board, players, numPlayers);
 
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
 
 
void place_tokens(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers){
  printf("Starting the Game.........\n\n");
	printf("We require to place all our tokens on first column of the board\n");
	printf("RULE:\n");
	printf("A token should be placed first on top of one of the smallest stacks.\n");
	printf("A player cannot stack a token on top of his/her token.\n\n\n");
 
	int totalMoves = numPlayers * 4;
    int move;
    int row=0;
	for (move=0; move < totalMoves; ++move) {
		int rowSelected = 0;
		printf("Player turn: %s ",players[(move%numPlayers)].name,"\n");
		while(!rowSelected) {
			printf("Enter the row (0-5) you want to place your token\n");
			printf("%d", row);
		//	scanf("%d",&row);
 
			player player = players[move%numPlayers];
 
            /* while(smallestTokenInColoumOne(board) < board[row][0].topOfStack){
                printf("\nERROR:Place your token on smaller stack\n");
                printf("Player %s Enter the row 0-5) you want to place your token\n ", players[(move%numPlayers)].name);
                scanf("%d", &row);
            }*/
 
            if(board[row][0].topOfStack>-1){
			    while(board[row][0].squaretokens->col==player.col){
			        printf("You can not put your token on sameColor");
			        printf("Enter the row (0-5) you want to place your token\n");
			        scanf("%d",&row);
			    }
            }
           token *newToken =(struct token*) malloc(sizeof(token));
            newToken->col = player.col;
            board[row][0].squaretokens=newToken;
            board[row][0].topOfStack ++;
            board[row][0].tokensColor[board[row][0].topOfStack]=player.col;
            print_board(board);
			rowSelected = 1;
			row++;
		}
	}
}
 //check smallest token for placing the it initialy
int smallestTokenInColoumOne(square board[NUM_ROWS][NUM_COLUMNS])
{
    int tokenCount[6];
   int smallestTokenRowInColoumOne=board[0][0].topOfStack;
   int i;
    for(i = 0; i < NUM_ROWS; ++i){
        tokenCount[i] = board[i][0].topOfStack;
        if(smallestTokenRowInColoumOne>tokenCount[i]){
            smallestTokenRowInColoumOne=tokenCount[i];
        }
    }
 
    return  smallestTokenRowInColoumOne;
}
int initialize_players(player players[]){
   int numPlayers=2;
 
    do {
        printf("Number of players");
        scanf("%d",&numPlayers);
    } while (numPlayers < 2 || numPlayers > 6);
 
    int count=0;
    int p;
    int choosenColor[numPlayers];
    int favorite_color=0;
	for (p=0; p< numPlayers; p++) {
 
		int numberColor;
		int colorSelectedByPlayer = 0;
        int sameColor=0;
		while (!colorSelectedByPlayer) {
        	numberColor = 1;
         printf("Enter a name of player: ");
         scanf("%s", players[p].name);
         while(!sameColor){
            sameColor=1;
            printf("Player %s choose your favorite color which is not taken by other players: (0:RED, 1:BLU, 2:GREEN, 3:YELLOW, 4:PINK, 5:ORANGE):  ",players[p].name);
 
        		scanf("%d", &favorite_color);
 
        		int p1;
                for(p1=0; p1< numPlayers; p1++){
                   /*     if((favorite_color)==choosenColor[p1]){
                            printf("\n color is already selected by other player please select any other color \n");
                            sameColor=0;
                        }*/
                }
                choosenColor[p] =favorite_color;
        }
            /* print out the result */
            switch (favorite_color)
            {
            case RED:
                printf("your favorite color is Red\n");
                break;
            case BLU:
                printf("your favorite color is BLU\n");
                break;
            case GREEN:
                printf("your favorite color is GREEN\n");
                break;
            case YELLOW:
                printf("your favorite color is YELLOW\n");
                break;
            case PINK:
                printf("your favorite color is PINK\n");
                break;
            case ORANGE:
                printf("your favorite color is ORANGE");
                break;
            default:
                printf("you did not choose any color");
            }
 
                players[p].col=favorite_color;
				colorSelectedByPlayer = 1;
 
			}
			favorite_color++;
		}
 
    return numPlayers;
}
 
 
/*CHECKS IF PLAYER CHOOSING THEIR TOKEN IN SIDEWAYS MOVE*/
int isCorrectToken(square board[NUM_ROWS][NUM_COLUMNS], player players[], int playerNumber, int row, int col){
    while(board[row][col].topOfStack == -1 || players[playerNumber].col != board[row][col].squaretokens->col){
            if(board[row][col].squaretokens == NULL){
                                  printf("\nERROR: Empty Square\n");
            }
          printf("\n Choose the row and column of already placed token");
            printf("\nEnter row number: ");
            scanf("%d", &row);
 
            printf("\nEnter column number: ");
            scanf("%d", &col);
 
    }
    return 1;
}
