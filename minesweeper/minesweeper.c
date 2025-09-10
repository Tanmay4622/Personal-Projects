#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void printGrid(char grid[], int size);
void plantMines(char grid[], int mines);
void number(char grid[]);
int checkTile(char choice[]);

int main(){
    int mines=10;
    char frontEnd[64];
    int size = (sizeof(frontEnd)/sizeof(frontEnd[0]));
    for(int i=0; i<size; i++){
        frontEnd[i]='#';
    }

    char backEnd[64];
    for(int i=0; i<size; i++){
        backEnd[i]='O';
    }

    srand(time(NULL));
    plantMines(backEnd, mines);
    number(backEnd);

    char choice[3];
    int win=0;
    printGrid(backEnd, size);
    do{
        printf("**************************\n");
        printGrid(frontEnd, size);
        printf("Enter cell: ");
        scanf("%s",&choice);

        if(choice[2] == 'f'){
            if(frontEnd[checkTile(choice)] != 'F'){
                frontEnd[checkTile(choice)] = 'F';
            }
            else{
                frontEnd[checkTile(choice)] = '#';
            }
        }
        else{
            frontEnd[checkTile(choice)] = backEnd[checkTile(choice)];
        }
        win++;
        if(win == 64-mines){
            printf("You Win!");
            return 0;
        }

    }while(frontEnd[checkTile(choice)] != 'M');



        for(int i=0; i<size; i++){
            if(backEnd[i] == 'M'){frontEnd[i]=backEnd[i];}
        }
        printf("**************************\n");
        printGrid(frontEnd,size);
        printf("*********You Lose!*********\n");
    
    return 0;
}

void printGrid(char grid[], int size){
    printf("   A  B  C  D  E  F  G  H \n");
    for(int j=0; j<size; j){
        printf("%d  ",(j/8)+1);
        for(int i=j; i<j+pow(size, 0.5); i++){
            printf("%c  ", grid[i]);
        }
        printf("\n");
        j += 8;
    }
    printf("\n");
}

void plantMines(char grid[], int mines){
    int i=0;
    while(i<mines){
        int random=(rand()%64);
        if(grid[random] != 'M'){
            grid[random] = 'M';
            i++;
        }
    }
}

void number(char grid[]){
    int temp[64];
    for(int i=0; i<64; i++){
        int num=0;
        if(i!=7 && i!=15 && i!=23 && i!=31 && i!=39 && i!=47 && i!=55 && i!=63){
            if(grid[i+1]=='M'){num++;}
        }

        if(i!=0 && i!=8 && i!=16 && i!=24 && i!=32 && i!=40 && i!=48 && i!=56){
            if(grid[i-1]=='M'){num++;}
        }

        if(grid[i+8]=='M'){num++;}

        if(grid[i-8]=='M'){num++;}

        if(i!=7 && i!=15 && i!=23 && i!=31 && i!=39 && i!=47 && i!=55 && i!=63){
            if(grid[i+9]=='M'){num++;}
        }

        if(i!=0 && i!=8 && i!=16 && i!=24 && i!=32 && i!=40 && i!=48 && i!=56){
            if(grid[i+7]=='M'){num++;}
        }

        if(i!=0 && i!=8 && i!=16 && i!=24 && i!=32 && i!=40 && i!=48 && i!=56){
            if(grid[i-9]=='M'){num++;}
        }

        if(i!=7 && i!=15 && i!=23 && i!=31 && i!=39 && i!=47 && i!=55 && i!=63){
            if(grid[i-7]=='M'){num++;}
        }
        temp[i]=num;
    }

    for(int i=0; i<64; i++){
        if(grid[i]=='O'){
            switch (temp[i])
            {
            case 1: grid[i]= '1';
            break;
            case 2: grid[i]= '2';
            break;
            case 3: grid[i]= '3';
            break;
            case 4: grid[i]= '4';
            break;
            case 5: grid[i]= '5';
            break;
            case 6: grid[i]= '6';
            break;
            case 7: grid[i]= '7';
            break;
            case 8: grid[i]= '8';
            break;
            }
        }
    }
}

int checkTile(char choice[]){
    int column=0, row=0, cell=0;
    switch (choice[0])
    {
        case 'a': column=0;break;
        case 'b': column=1;break;
        case 'c': column=2;break;
        case 'd': column=3;break;
        case 'e': column=4;break;
        case 'f': column=5;break;
        case 'g': column=6;break;
        case 'h': column=7;break;
    }
    switch (choice[1])
    {
        case '1': row=0;break;
        case '2': row=1;break;
        case '3': row=2;break;
        case '4': row=3;break;
        case '5': row=4;break;
        case '6': row=5;break;
        case '7': row=6;break;
        case '8': row=7;break;
    }
    cell = column + (row*8);
    return cell;
}    
