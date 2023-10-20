//#include <..\STD_TYPES.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tic_tac_toe.h"
#include <unistd.h>

int main()
{
	
	system("cls");
	
	char mode;
	char win;
	char x;
	int y;
	printf("\033[37m");
	
	printf("*******************************************\n\n\n");
	printf("\033[1;35m\tWelcome in TIC TAC TOE GAME \033[0m\n");
	printf("\033[1;35m\t     BY RAHMA SHAHBA \033[0m\n\n\n");
	printf("*******************************************\n");
	
	
	do
	{
		
	  do
	  {
		  
        
		printf("\n\n\033[1;35m\tTIC-TAC-TOE GAME Modes: \033[0m\n");
		printf("\t1. Multiplayer mode...Press 1.\n\t2. Single player mode...Press 2.");
		printf("\n\tEnter your mode: ");
		scanf(" %c",&mode);
		system("cls");
		
	  }while(!(mode=='1' || mode =='2' ));
	   system("cls");
	   printf("\n\n");
	   char winner = ' ';
	   checkFreeSpaces();
	   resetBoard();
	   
	   if(mode == '2')
	   	
	   {

		     do
	        {
	        system("cls");
		    	 printf("\033[1;35m\t\n\n \t Player, choose 'X' or 'O':\033[0m ");
                 scanf(" %c", &player_1);
	        }while(!(player_1=='o' || player_1 =='x' || player_1=='X' || player_1 =='O'));
                if (player_1 == 'X' || player_1 == 'x') {
                    player_1 = 'X';
                    computer = 'O';
		    		printf("\t\n\n \t Player (X) \033[1;35m VS \033[0m Computer (O)\n\n\n");
                } else {
                    player_1 = 'O';
                    computer = 'X';
		    		printf("\t\n\n \t Computer (X) \033[1;35m VS \033[0m Player (O)\n\n\n");
                }
		    	//printf("\t\n\n \t %s (X) \033[1;35m VS \033[0m %s (O)\n\n\n",name_1,name_2);
		    	sleep(3);
		   
		
        	while(winner==' ' && checkFreeSpaces()!=0)
	        {	
				system("cls");
				//resetBoard();
	        	printBoard();
	        	player_1Move();
	        	winner = checkWinner();
				
	        	if((winner != ' ' )|| (checkFreeSpaces()==0))
	        	{
	        		break;
					
	        		
	        	}
	        	computerMove();
	        	winner = checkWinner();
				
	        
	        	if((winner != ' ') ||(checkFreeSpaces()==0) )
	        	{
	        		break;
					
	        	}
				
	        }
	        printBoard();
			system("cls");
			printBoard();
	   printWinner_singleMode(winner);
	   sleep(4);
	   system("cls");
	   
	}
	else if(mode == '1')
	{ 
			 int equal = 1;
           
           do
		   {
			   
			printf("\033[1;35m\n\n \t1st player name :  \033[0m");
	        scanf(" %[^\n]s",name_1);   
			
			
			printf("\033[1;35m\n\n \t2st player name :  \033[0m");
	        scanf(" %[^\n]s",name_2);
			int i = 0;
           
			while (name_1[i] != '\0' && name_2[i] != '\0')
			{
            if (name_1[i] != name_2[i])
				{
              equal = 0;
			  
              break;
            }
			system("cls");
			printf("\t\n\n \t Please enter Different name. ");
            i++;
            }
		   }while(equal);
		   
		   
            do
	    {
	    system("cls");
			 printf("\033[1;35m\t\n\n \t %s, choose 'X' or 'O':\033[0m ",name_1);
             scanf(" %c", &player_1);
	    }while(!(player_1=='o' || player_1 =='x' || player_1=='X' || player_1 =='O'));
            if (player_1 == 'X' || player_1 == 'x') {
                player_1 = 'X';
                player_2 = 'O';
				printf("\t\n\n \t %s (X) \033[1;35m VS \033[0m %s (O)\n\n\n",name_1,name_2);
            } else {
                player_1 = 'O';
                player_2 = 'X';
				printf("\t\n\n \t %s (X) \033[1;35m VS \033[0m %s (O)\n\n\n",name_2,name_1);
            }
			//printf("\t\n\n \t %s (X) \033[1;35m VS \033[0m %s (O)\n\n\n",name_1,name_2);
			sleep(3);
			

            while(winner==' ' && checkFreeSpaces()!=0)
	        {
				
				system("cls");
				
             	printBoard();
	        	player_1Move();
	        	winner = checkWinner();
				
			
				
	        	if((winner != ' ' )|| (checkFreeSpaces()==0))
	        	{
	        		break;
	        		
	        	}
				
				system("cls");
				
				printBoard();
	        	player_2Move();
	        	winner = checkWinner();
			
	        	if((winner != ' ') ||(checkFreeSpaces()==0))
	        	{
	        		break;
	        		
	        	}
	        }
	        printBoard();
			system("cls");
			printBoard();
	   printWinner_MultiplayerMode(winner);
	   
	   
	   sleep(4);
	   system("cls");
	}
	
	printf("\033[37m");
	
	   
	    do
	    {
	    	
	    	printf("\033[1;35m\n\n Do you want to play another round?(Y/N)\033[0m"); 
	    	scanf(" %c",&win);
	    //	system("cls");
	    }while(!(win=='y' || win =='Y' || win=='n' || win =='N'));
		
	    if(win=='y' || win =='Y' )
	    {
	    	y = 1;
			system("cls");
	    }
	    else 
	    {
	    	y = 2;
	    }
		
	
	
	
	}while(y==1);
	if(y==2)
	{
		
		printf("\033[1;31m\n\t Bye Bye\033[0m\n");
		printf("\033[1;31m\n\t Exit...\n\033[0m\n");
		 exit(0);
	}
	
	
	
	return 0;
}
