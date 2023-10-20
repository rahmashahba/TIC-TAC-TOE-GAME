#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "tic_tac_toe.h"


 char board[3][3];
                   

void resetBoard()
{
	
	 
	 for(int i=0 ; i<3;i++)
	{
		for(int j=0 ; j<3;j++)
	    {
		   board[i][j] = i*3 + j + 1 + '0'; // convert to ascii and set
			
		}
		
	}
	

}

void printBoard()
{
	
	 printf("\033[1;33m\n\n    Press (Q|q) to Quit....\033[0m");
	 printf("\n");
	 printf("\033[1;35m\n\n\tTic Tac Toe  \033[0m\n\n");
     printf(" \t%c  | %c | %c\n", board[0][0], board[0][1], board[0][2]);
     printf(" \t---|---|---\n");
     printf(" \t%c  | %c | %c\n", board[1][0], board[1][1], board[1][2]);
     printf(" \t---|---|---\n");
     printf(" \t%c  | %c | %c ", board[2][0], board[2][1], board[2][2]);
     printf("\n"); 
   
   
  
 
}
int checkFreeSpaces()
{
	 int freeSpaces = 9;
	for(int row=0 ; row<3;row++)
	{
		for(int col=0 ; col<3;col++)
	    {
			if((board[row][col] =='X')||(board[row][col] =='O'))
			{
				freeSpaces--;
			}
			
		
		}
		
	}
	return freeSpaces;
	
}

void player_1Move()
{
	// Change the background color 
    printf("\033[32m");
	 int move;
	 int row ;
	 int col ;
	 char input[10];
	
	do
	{
		
		
		printf("\n\t%s your Turn : ",name_1);
		scanf(" %[^\n]s",&input);
		if(input[0]== 'q'||input[0]== 'Q')
		{
			
			printf("\033[1;31m\n\tBye Bye\033[0m");
		    printf("\033[1;31m\n\tExit..\n\033[0m\n");
		    exit(0);
		  
		}
		if(input[0] >= '0' && input[0] <= '9' && input[1] == '\0')
		{
		move = input[0] - '0';
		
		if (move >= 1 && move <= 9)
		{
            //move = input[0] - '0';
			row = ((int)move - 1) / 3;
            col = ((int)move - 1) % 3;
		          
		    if((board[row][col] =='X')||(board[row][col] =='O'))
			  {	
				 //printf("\nInvalid input. Please enter a valid move (1-9).\n");
		  
       			 printf("\n      Invalid move. Try again\n");
		          			
		      }
		    else	
		    {
		    	board[row][col]=player_1;	
			break;
			}
		}
		
		}
		else
		{
							 printf("\nInvalid input. Please enter a valid move (1-9).\n");
		}

		
	}while((!(input[0] >= '0' && input[0] <= '9' && input[1] == '\0'))||(board[row][col] =='X')||(board[row][col] =='O'));
		
}

void player_2Move()
{
	// Change the background color to blue
	 printf("\033[34m");
     int move;
	 int row ;
	 int col ;
	 char input[10];
	
	do
	{
		
		
		
		printf("\n\t%s your Turn : " ,name_2);
		scanf(" %[^\n]s",&input);
		if(input[0]=='q'||input[0]=='Q')
		{
			printf("\n\033[1;31m\n\tBye Bye\033[0m");
		    printf("\n\033[1;31m\n\tExit..\n\033[0m\n");
		    exit(0);
		    //break;
		}
		    
		
            
			
		if(input[0] >= '0' && input[0] <= '9' && input[1] == '\0')
		{	
			move = input[0] - '0' ;
			if (move >= 1 && move <= 9)
		{
            //move = input[0] - '0';
			row = ((int)move - 1) / 3;
            col = ((int)move - 1) % 3;
		          
		    if((board[row][col] =='X')||(board[row][col] =='O'))
			  {	
				// printf("\nInvalid input. Please enter a valid move (1-9).\n");
		        
       	      		 printf("\n      Invalid move. Try again\n");
		                			
		       }
		       else	
		       {
		          	board[row][col]=player_2;	
		      	   break;
		      }
		}
		
		}
		else
		{
							 printf("\nInvalid input. Please enter a valid move (1-9).\n");
		}
		
	}while((!(input[0] >= '0' && input[0] <= '9' && input[1] == '\0'))||(board[row][col] =='X')||(board[row][col] =='O'));
		
}
void computerMove()
{
	
	//creates a seed based on current time
   srand(time(NULL));
   int x;
   int y;

    if(checkFreeSpaces() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      } 
	  while ((board[x][y] =='X')||(board[x][y] =='O'));
      
      board[x][y] = computer;
   }
   else
   {
      printWinner_singleMode(' ');
	  
   }
}
	

	
	


char checkWinner()
{
	//check row
	for(int i=0 ; i<3;i++)
	{
		
	if((board[i][0] ==board[i][1])&&(board[i][0] ==board[i][2]))
	{
				return board[i][0];
				
	}
		
	}
	//check col
	for(int i=0 ; i<3;i++)
	{
		
	if((board[0][i] ==board[1][i])&&(board[0][i] ==board[2][i]))
	{
				return board[0][i];
				
	}
		
	}
	//check diagonal
	
	if((board[0][0] ==board[1][1])&&(board[0][0] ==board[2][2]))
	{
				return board[0][0];
				
	}
	if((board[0][2] ==board[1][1])&&(board[0][2] ==board[2][0]))
	{
				return board[0][2];
				
	}
	return ' ';
		
	
}
void printWinner_singleMode(char winner)
{
	
	
    if(winner == player_1)
   {
	   printf("\033[1;35m\n \tGame Over   \033[0m\n");
	    printf("\033[1;36m\tCongratulations ..\033[1;36m\n");
       printf("\033[1;36m\tYOU WIN!\033[1;36m");
	   printf(".\n");
	   printf("\n");
   }
    else if(winner == computer)
   {
    printf("\033[1;35m\n \tGame Over   \033[0m\n");
	  printf("\033[1;36m\tYOU LOSE!\n\033[1;36m");
	  printf("\033[1;36m\tComputer WIN!\033[1;36m");
	   printf("\n");
   }
   else if(winner == ' ')
   {
	printf("\033[1;35m\n \tGame Over   \033[0m\n");
      printf("\033[1;36m\tIT'S A TIE!\033[1;36m");
	   printf("\n");
   }
  
}
void printWinner_MultiplayerMode(char winner)
{
	
	
    if(winner == player_1)
   {
      printf("\033[1;35m\n \tGame Over   \033[0m\n");
   	  printf("\033[1;36m\tCongratulations %s ..\033[1;36m", name_1);
	  printf("\033[1;36m\n\t%s WIN!\033[0m\n",name_1);
	  printf("\n");
   }
  
   else if(winner == player_2)
   {
	  printf("\033[1;35m\n \tGame Over   \033[0m\n");
	  printf("\033[1;36m\tCongratulations %s ..\033[1;36m",name_2);
      printf("\033[1;36m\n\t%s WIN!\033[0m\n",name_2);
	  printf("\t%s LOSE!\n \n ",name_1);
	  printf("\n");
   }
 
   else if(winner == ' ')
   {
	  
	 printf("\033[1;35m\n \tGame Over   \033[0m\n");
     printf("\033[1;36m\tIT'S A TIE!\033[1;36m");
	 printf("\n");
   }
}





// void player_turn(char player) {
    // int move;
    // char mark;

    // if (player == player1)
        // mark = 'X';
    // else
        // mark = 'O';

    // printf("Player %c, enter your move (1-9): ", mark);
    // scanf("%d", &move);

// int row = (move - 1) / 3;
    // int col = (move - 1) % 3;

    // if (board[row][col] != '1' + row * 3 + col && board[row][col] != '4' + row * 3 + col && board[row][col] != '7' + row * 3 + col) 
	// {
        // printf("Invalid move. Try again.\n");
        // player_turn(player);
    // } else {
        // board[row][col] = mark;
    // }
// }
