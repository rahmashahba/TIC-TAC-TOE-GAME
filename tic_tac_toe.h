#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H


// #define player 'X'
// #define computer 'O'
// #define player_1 'X'
// #define player_2 'O'

char computer ;
char player_1 ;
char player_2 ;


char name_2[100] ;
char name_1[100];

void resetBoard();
void printBoard();
int checkFreeSpaces();

void player_1Move();
void player_2Move();
void computerMove();

char checkWinner();
void printWinner_MultiplayerMode(char winner);
void printWinner_singleMode(char winner);

#endif