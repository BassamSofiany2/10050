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
 
    //the number of players
    int numPlayers =0;
 
    //creates the players
    numPlayers = initialize_players(players);
 
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
