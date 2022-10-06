//Tic Tac To between 2 players or player vs computer
//Tomes, Christopher
//revision v1 10/05/2022
#include <stdio.h>
int main(){
    int user_input;
    //prompt user for game version they would like to play
    printf("========================\n");
    printf("Welcome to TIC TAC TOE!\n");
    printf("1 --- person vs. person \n");
    printf("2 --- person vs. random computer \n");
    printf("Enter your choice (1 or 2):\n");
    scanf("%d", &user_input);
    printf("%d\n", user_input);

    //read user input from terminal

    

    //initialize ver of game

        //create 2D array rep of board state 3x3 chars with inital value ' '
        //avail ops are '  ' , ' X ' , ' O  '

    //begin loop

        //check win/tie condition:
            //win condition consists of same chars !' ' in a row. ie: (1,1): 'X', (2,2): 'X', (3,3):'X'
            //tie condition is if there are no more free locations

            //if win/tie condition met EXIT LOOP and print result.

        //prompt user for location (x,y)
        //store a X in that location in 2D array
        //print BOARD

        //if user-mode:
            //prompt second user for location.
            //store a O in that location in 2D array
            //print BOARD

        //if pve-mode:
            //generate a randomvalue mod 0-9.
            //store a O in that location in 2D array if DNE else regenerate.
            //print BOARD

    //end loop
    
    return 0;
}
