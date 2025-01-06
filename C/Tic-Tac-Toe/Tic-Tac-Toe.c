/* C program by Arsalan Kataneh for CS1310 ,Oct 2023
 * This program will play Tic Tac Toe 
 *
 *
 *
 *                                                            @@@@@@@@@   @@@@@@@@     
 *                                                           @         @ @        @     
 *                                                          @           @          @    
 *                                                           @         @ @        @     
 *                                                            @@@@@@@@@  @@@@@@@@@   
 */ 
 #include <stdio.h> 
 
 
 
 
 char ttt[3][3];  // The Tic-Tac-Toe board
char player = 'X';  // Starting player
int row, col;  // Indexes for the user's move
int moves = 0;  // Number of moves made
int result = 0; // if result is 0 means draw, if result 1 its a win  
int choice = 10; // initialized to 10 so that it runs in while loop 




void checkWin(void) /* checks for a win for either player */ 
{
	if ( (ttt[0][0] == player && ttt[0][1] == player && ttt[0][2] == player)	||  /* checks Row top */
	(ttt[1][0] ==player && ttt[1][1] ==player && ttt[1][2] == player)  ||    /* checks row mid */
	(ttt[2][0] ==player && ttt[2][1] ==player && ttt[2][2] == player)  ||    /* checks row bottom */ 
	(ttt[0][0] ==player && ttt[1][0] == player && ttt[2][0] == player) ||    /* checks column left */
	(ttt[0][1] ==player && ttt[1][1] == player && ttt[1][2] == player) ||     /* checks column mid */
	(ttt[0][2] ==player && ttt[1][2] == player && ttt[2][2] == player) ||    /* checks column right */
	(ttt[0][0] ==player && ttt[1][1] == player && ttt[2][2] == player) ||    /* checks diagonal 1 */
	(ttt[2][0] ==player && ttt[1][1] == player && ttt[0][2] == player) )     /* checks diagonal 2 */
	result = 1; /* makes the result one which means its a win  */ 
}



// Function to print the Tic-Tac-Toe board
void printttt(void)
 {
 
     printf("\nKey:\n");
    printf(" 1 | 2 | 3 \n");
    printf("---|---|---\n");
    printf(" 4 | 5 | 6 \n");
    printf("---|---|---\n");
    printf(" 7 | 8 | 9 \n");
    
    	printf("Tic Tac Toe play board:\n\n"); 
    printf(" %c  | %c  | %c \n", ttt[0][0], ttt[0][1], ttt[0][2]);
    printf("----|----|----\n");
    printf(" %c  | %c  | %c \n", ttt[1][0], ttt[1][1], ttt[1][2]);
    printf("----|----|----\n");
    printf(" %c  | %c  | %c \n", ttt[2][0], ttt[2][1], ttt[2][2]);
    
}



 
void Choice (void)  /* allows a player to make a choice and initialize a place in ttt with 'X' or 'O'*/
{
	do {
			 do { /* runs a do-while to scan in a number within the range from the player */
					printf("Type in the number (1-9) where you want to place your marker: ");
					scanf("%d", &choice);
				} while ((choice < 1) || (choice > 9)); /* runs the loop until a number from 1-9 is put in */
				
			switch (choice) /* switch statement to initialize hrz & vrt based on player choice */
				{
					case 1:
						row = 0;
						col = 0;
						break;
					case 2:
						row = 0;
						col = 1;
						break;
					case 3:
						row = 0;
						col = 2;
						break;
					case 4:
						row = 1;
						col = 0;
						break;
					case 5:
						row = 1;
						col = 1;
						break;
					case 6:
						row = 1;
						col = 2;
						break;
					case 7:
						row = 2;
						col = 0;
						break;
					case 8:
						row = 2;
						col = 1;
						break;
					case 9:
						row = 2;
						col = 2;
						break;
					default:
						printf("Not a correct input.");
				}
		} while (ttt[row][col] != ' '); /* makes sure that the same place is chosen  */ 
}
 
 
 
 void main (void)
 {
     for (row = 0; row <= 2; row++) /* these 2 for loops are for filling the spaces */
		for (col = 0; col <= 2; col++)
			ttt[row][col] = ' '; /* initializing all number to empty space */
	
 	
 	printf(" You will choose a number between 1-9 that corresponds with the board shown below\n " 
	 "Get 3 X or O to align horizontally , vertically or diagonally  to win!! \n\n");

 	
 	while ((result == 0) && (moves < 9))  /* loop while there is no winner or tie */
		{
			printttt();  /* shows the p=board with inputs */
			Choice();  /* lets the player make their choice */
			printf("\n");
			ttt[row][col] = player; /* stores either an 'X' or an 'O' in the space chosen */
			moves = moves + 1; /* increments moveCounter by 1 */
			checkWin(); /* checks is the game is finished */
			
			if (player == 'X')  /* checks what's in player to see if the letter needs to be changed */
				player = 'O';
			else
				player = 'X';
		}
		if (result == 1) /* displays  the win */ 
		{
		
			if (player == 'X')  /* checks what's in player to see if the letter needs to be changed */
				player = 'O';
			else
				player = 'X';
				
				printttt();
				printf("Finally, a win !!!");
        }
        else /* display board and announce a draw */ 
        {
        	printttt(); /* prints the board */ 
        	
        	printf("It is a tie , better luck nect time !!"); 
		}
		
 }
