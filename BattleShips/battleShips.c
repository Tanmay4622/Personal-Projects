#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void initializeGrid(char grid[][10]);
void printgrid(char grid1[][10] ,char grid2[][10], int playerHP, int compHP);
void fixInput(char input[5]);
int placeShip(char input[5], char grid[][10], int shipSize);
void genCompShips(char grid[][10]);

int main(){

    char compBack[10][10];
    char compFront[10][10];
    char playerGrid[10][10];
    char input[5] = "";
    int  playerHP = 17;
    int  compHP = 17;
    initializeGrid(compBack);
    initializeGrid(compFront);
    initializeGrid(playerGrid); 
    
    srand(time(NULL));
    genCompShips(compBack);

        //Pront user for ship locations and place ships
        if(1){
        int i=2, j=0, checker=0;

        printgrid(playerGrid, compBack, playerHP, compHP);

        while(i < 3){
            printf("Place your %d* ship: ", i);
            fgets(input, 5, stdin);
            fflush(stdin);
            fixInput(input);
            checker = placeShip(input, playerGrid, i);
            //resets loop if error is detected
            if(checker == 1){
                printf("Please Enter valid cordinates \n");
                continue;
            }
            if(sizeof(input)/sizeof(input[0]) != 5){
                printf("Please Enter valid cordinates \n");
                continue;
            }
            printgrid(playerGrid, compFront, playerHP, compHP);

            // runs the loop for values 2,3,3,4,5
            j += i;
            if(j == 5){continue;}
            i++;
        }
        }

        do{
        //player attacks
            char choice[3];
            printf("Select a cell to attack: ");
            fgets(choice, 3, stdin);
            fflush(stdin);
            int column = (choice[0]-97);
            int row = (choice[1]-48);
            if(compBack[column][row] == 'S'){
                compHP--;
                compFront[column][row] = 'X';
            } 
            else{
                compFront[column][row] = 'O';
            }
        //computer attacks
            while(1){
                column = rand()%10;
                row = rand()%10;
                if(playerGrid[column][row] == '_' || playerGrid[column][row] == 'S'){
                    if(playerGrid[column][row] == 'S'){
                        playerHP--;
                        playerGrid[column][row] = 'X';
                    }
                    else{ 
                    playerGrid[column][row] = 'O';
                    }
                    break;
                }
            }
        printgrid(playerGrid, compFront, playerHP, compHP);

        }while(playerHP != 0 && compHP != 0);
    
    if(playerHP==0){
        printf("YOU LOSE!");
    }
    if(compHP==0){
        printf("YOU WIN!");
    }
    return 0;
}

void initializeGrid(char grid[][10]){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            grid[i][j] = 95;
        }
    }
}

void printgrid(char grid1[][10] ,char grid2[][10], int playerHP, int compHP){
    printf("%02d   A  B  C  D  E  F  G  H  I  J  |  %02d   A  B  C  D  E  F  G  H  I  J \n",playerHP, compHP);
    for(int i=0; i<10; i++){
        printf("%d    ", i);
        for(int j=0; j<10; j++){
            printf("%c  ",grid1[j][i]);
        }
        printf("|  %d    ", i);
        for(int j=0; j<10; j++){
            printf("%c  ",grid2[j][i]);
        }
        printf("\n");
    }
}

//genralizes inputed cordinates such that they are readable by print function if needed
void fixInput(char input[5]){
    int temp = 0;
    if(input[0] > input[2]){
                temp = input [2];
                input[2] = input[0];
                input[0] = temp;
    }
        if(input[1] > input[3]){
                temp = input [3];
                input[3] = input[1];
                input[1] = temp;
    }
}

//fill all the spots between the 2 given cordinates inclusively
int placeShip(char input[5], char grid[][10], int shipSize){
    int column = 0, row = 0, size = 0;

        if(input[0] == input[2]){
            size = 1+input[3]-input[1];

            //exits if incorrect size size is detected
            if(size != shipSize){
                return 1;
            }

            column = (input[0]-97);
            row = (input[1]-48);

            //exits if overlap is happening
            for(int j=0; j < size; j++){
                if(grid[column][row + j] == 'S'){
                    return 1;
                }
            }
            for(int i=0; i < size; i++){
                grid[column][row + i] = 'S';
            }
        }

        //same but for vertical
        if(input[1] == input[3]){
            size = 1+input[2]-input[0];
            if(size != shipSize){
                return 1;
            }

            column = (input[0]-97);
            row = (input[1]-48);

            for(int j=0; j < size; j++){
                if(grid[column + j][row] == 'S'){
                    return 1;
                }
            }
            for(int i=0; i < size; i++){
                grid[column + i][row] = 'S';
            }
        }
    return 0;
}

void genCompShips(char grid[][10]){
    int temp3 = 0, i = 2;
    while(i<6){
        char cord[4] = {0};
        char compShips[5][4];
        int temp = 0, temp2 =0,row =0, column=0, breaker=0;

        if(rand()%2){
            //generation of cordinates
            temp =  97 + (rand() % 10);
            cord[0] = temp;
            cord[2] = temp;
            temp2 = 48 + (rand() % (11-i));
            cord[1] = temp2;
            cord[3] = temp2 + i-1;

            //generalizes cordinates
            fixInput(cord);

            column = (cord[0]-97);
            row = (cord[1]-48);
            
            //checks if the the location generated overlaps with previous ship locations
            for(int j=0; j < i; j++){
                if(grid[column][row + j] == 'S'){
                    breaker++;
                }
            }
            if(breaker){
                continue;
            }

            //fill all the spots between the 2 given cordinates inclusively 
            for(int j=0; j < i; j++){
                grid[column][row + j] = 'S';
            }
        } 
        //same thing but for vertical placement
        else{
            temp2 = 97 + (rand() % (11-i));
            cord[0] = temp2;
            cord[2] = temp2 + i-1;
            temp =  48 + (rand() % 10);
            cord[1] = temp;
            cord[3] = temp;

            fixInput(cord);

            column = (cord[0]-97);
            row = (cord[1]-48);

            for(int j=0; j < i; j++){
                if(grid[column + j][row] == 'S')
                    breaker++;
            }
            if(breaker){
                continue;
            }
            for(int j=0; j < i; j++){
                grid[column + j][row] = 'S';
            }
        }

        //makes the loop run twice with i = 3 (ships are of length 2,3,3,4,5)
        temp3 += i;
        if(temp3 == 5){
            continue;
        }
        i++;
    }
}
