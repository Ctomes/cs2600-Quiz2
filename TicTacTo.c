//Tic Tac To between 2 players or player vs computer
//Tomes, Christopher
//revision v1 10/05/2022
#include <stdio.h>

char board[9] = "";
int win_con[8] = {0};
int winner = 0; //player 1 = 1, player = 2
/*
win condition arrays:
--------
Horizontal
0: 0 1 2
1: 3 4 5
2: 6 7 8
Vertical
3: 0 3 6
4: 1 4 7
5: 2 5 8
Diagnal
6: 0 4 8
7: 2 4 6
--------
//X++ O-- winner occurs if any become 3/-3
*/

int tryMove(int x, int y, char in)
{
    int board_spot = ((y-1) + (3*(x-1)));

    if(board[board_spot] == 0)
    {
        board[board_spot] = in;

        switch (board_spot)
        {// ++/-- win conditions. When we reach 3 OR -3 we terminate.
        case 0: //0,3,6
            if(in == 'X')
            {
                ++win_con[0];
                ++win_con[3];
                ++win_con[6];
            }else
            {
                --win_con[0]; 
                --win_con[3];
                --win_con[6];
            }
            break;
        case 1: //0,4
            if(in == 'X')
            {
                ++win_con[0];
                ++win_con[4];
            }else{
                --win_con[0]; 
                --win_con[4];
            }
            break;
        case 2://0,5,7
            if(in == 'X')
            {
                ++win_con[0];
                ++win_con[5];
                ++win_con[7];
            }else{
                --win_con[0];
                --win_con[5];
                --win_con[7];
            }
            break;
        case 3://1,3
            if(in == 'X')
            {
                ++win_con[1];
                ++win_con[3]; 
            }else{
                --win_con[1];
                --win_con[3];
            }
            break;
        case 4: //1,4,6,7
            if(in == 'X')
            {
                ++win_con[1];
                ++win_con[4];
                ++win_con[6];
                ++win_con[7];
            }else{
                --win_con[1];
                --win_con[4];
                --win_con[6];
                --win_con[7];
            }
            break;
        case 5://1,5
            if(in == 'X')
            {
                ++win_con[1];
                ++win_con[5]; 
            }else{
                --win_con[1];
                --win_con[5];
            }
            break;
        case 6://2,3,7
            if(in == 'X')
            {
                ++win_con[2];
                ++win_con[3];
                ++win_con[7];
            }else{
                --win_con[2];
                --win_con[3];
                --win_con[7];
            }
            break;
        case 7://2,4
            if(in == 'X')
            {
                ++win_con[2];
                ++win_con[4]; 
            }else{
                --win_con[2];
                --win_con[4];
            }
            break;
        case 8://2,5,6
            if(in == 'X')
            {
                ++win_con[2];
                ++win_con[5];
                ++win_con[6];
            }else{
                --win_con[2];
                --win_con[5];
                --win_con[6];
            }
            break;
                      
        default:
            break;
        }

        return 0;
    }else
    {
        return 1;
    }
}

int isThereAWinner()
{
    for(int i = 0;i<8;++i)
    {
        if(win_con[i]==3)
        {
            printf("PLAYER 1 IS THE WINNER\n");
            return 0;
        }
        if(win_con[i]==-3){
            printf("PLAYER 2 IS THE WINNER\n");
            return 0;
        }
        }
    return 1;
}
void printBoard()
{
    printf("Current status is:\n");
    printf("+----------+\n");
    int k = 0;
    for(int i = 0;i<3;++i)
    {
        for(int j = 0; j<3; ++j)
        {
            printf("| %c |",board[k++]);
        }
        printf("\n+----------+\n");
    }

}


int main(){
    int user_input;
    //prompt user for game version they would like to play
    printf("========================\n");
    printf("Welcome to TIC TAC TOE!\n");
    printf("1 --- person vs. person \n");
    printf("2 --- person vs. random computer \n");
    printf("Enter your choice (1 or 2):\n");


    //read user input from terminal
    int result = scanf("%d", &user_input);
    while(1)
    {//continues to loop until valid input is entered.
        if(result != 0)
        {
            if(user_input == 1 || user_input == 2)
            {
                break;
            }
        }
        printf("INVALID INPUT\n");
        fflush(stdin);
        result = scanf("%d", &user_input);
    }


    

    //initialize ver of game

        //create 2D array rep of board state 3x3 chars with inital value ' '
    
        printBoard();
        //avail ops are '  ' , ' X ' , ' O  '

    //begin loop
    while(1){

        int x;
        int y;
        // user input (2,3) array_pos = (x-1) + 3(y-1);

        //check win/tie condition:
            //win condition consists of same chars !' ' in a row. ie: (1,1): 'X', (2,2): 'X', (3,3):'X'
            //tie condition is if there are no more free locations
            //if win/tie condition met EXIT LOOP and print result.
        if(isThereAWinner() == 0)
        {
            break;
        }

        //prompt user for location (x,y)
        printf("Player1: make your move\n");
        while(scanf("%d %d", &x, &y)!= 0)
        {
            if((x < 4 && x > 0)&& (y < 4 && y > 0))
            {
                if(tryMove(x,y, 'X') == 0){
                    break;
                }else{
                    printf("Spot is taken\n");
                }
                printBoard(); 
                
            fflush(stdin);
            printf("IN\n");
            }else
            {
               printf("Invalid Input\n");
               fflush(stdin);
               break;
            }
        }
        printBoard(); 

        
        //store a X in that location in 2D array
        //print BOARD

        //if user-mode:
            //prompt second user for location.
            //store a O in that location in 2D array
            //print BOARD
        if(user_input == 1)
        {
            printf("Player2: make your move\n");
            while(scanf("%d %d", &x, &y)!= 0)
            {
                if((x < 4 && x > 0)&& (y < 4 && y > 0))
                {
                    if(tryMove(x,y, 'O') == 0){
                        break;
                }else{
                    printf("Spot is taken\n");
                }
                printBoard(); 
                
            fflush(stdin);
            printf("IN\n");
            }else
            {
               printf("Invalid Input\n");
               fflush(stdin);
               break;
            }
        }
        printBoard(); 
        }
        //if pve-mode:
            //generate a randomvalue mod 0-9.
            //store a O in that location in 2D array if DNE else regenerate.
            //print BOARD

    }
    //end loop
    
    return 0;
}
