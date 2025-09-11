#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void initializeGrid(char grid[][10]);
void printgrid(char grid1[][10] ,char grid2[][10]);
void placeShip(char input[5], char grid[][10], int shipSize);

int main(){

    char compGrid[10][10];
    char playerGrid[10][10];
    char input[5] = "";
    initializeGrid(compGrid);
    initializeGrid(playerGrid); 
    
    printgrid(playerGrid ,compGrid);

    //Pront user for ship locations
        int i=2;
        int j=0;
        while(i < 3){
            printf("Place your %d* ship: ", i);
            fgets(input, 5, stdin);
            fflush(stdin);
            placeShip(input, playerGrid, i);
            printgrid(playerGrid ,compGrid);
            j += i;
            if(j == 5){continue;}
            i++;
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

void printgrid(char grid1[][10] ,char grid2[][10]){
    printf("P   A  B  C  D  E  F  G  H  I  J  |  C   A  B  C  D  E  F  G  H  I  J \n");
    for(int i=0; i<10; i++){
        printf("%d   ", i);
        for(int j=0; j<10; j++){
            printf("%c  ",grid1[j][i]);
        }
        printf("|  %d   ", i);
        for(int j=0; j<10; j++){
            printf("%c  ",grid2[j][i]);
        }
        printf("\n");
    }
}

void placeShip(char input[5], char grid[][10], int shipSize){
    int column = 0, row = 0, size = 0, temp = 0;

    //makes sure the input is readable
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
    
    //fill all the spots between the 2 given cordinates inclusively
        if(input[0] == input[2]){
            size = 1+input[3]-input[1];
            if(size != shipSize){
                return;
            }

            column = (input[0]-97);
            row = (input[1]-48);
            
            for(int i=0; i < size; i++){
                grid[column][row + i] = 'S';
            }
        }

        if(input[1] == input[3]){
            size = 1+input[2]-input[0];
            if(size != shipSize){
                return;
            }

            column = (input[0]-97);
            row = (input[1]-48);

            for(int i=0; i < size; i++){
                grid[column + i][row] = 'S';
            }
        }
}
