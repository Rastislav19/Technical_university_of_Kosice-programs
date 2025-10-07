#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "ballsortpuzzle.h"

void generator(const int rows, const int columns, char field[rows][columns]){
    srand(time(0));
    // vyber volnych stlpcou
    int free1 = (rand() % (0 - (columns)));
    int free2;
    do{
        free2 = (rand() % (0 - (columns)));
    }while (free1==free2);
    
    // mozne pozicie pre symbol
    for (int y=0; y<rows; y++){
        for (int x=0; x<columns; x++){
            if(x==free1 || x==free2){
                field[y][x]=' ';
            }else{
                field[y][x]='C';
            }
    }}

    char symbol[]="!@>#$&*<+?>";
    int rand_pos_x;
    int rand_pos_y;

    //doplnenie do stlpcou
    for (int y=0; y<columns-2; y++){
        for (int x=0; x<rows; x++){
            do{
                rand_pos_x=(rand() % (0 - columns));
                rand_pos_y=(rand() % (0 - rows));
            }while (field[rand_pos_y][rand_pos_x]!='C' || field[rand_pos_y][rand_pos_x]==' ');
            field[rand_pos_y][rand_pos_x]=symbol[y];
    }}
}

void down_possible(const int rows, const int columns, char field[rows][columns], int pick, int get){
    pick--;
    get--;
    // x=y
    if (pick==get){
        printf("Thats not posible! Nothing will change.\n");
        return;
    }

    // najdenie prazdneho miesta v stlpcoch
    int ypick=0;
    int yget=0;
    while (field[ypick][pick]==' ' && ypick!=rows-1){
        ypick++;
    }
    while (field[yget][get]==' ' && yget!=rows-1){
        yget++;
    }

    // ak x stlpec je prazdny
    if (field[ypick][pick]==' '){
        printf("Thats not posible! You try to move the gap.\n");
        return;
    }
    // ak y slpec je plny
    if (field[yget][get]!=' ' && yget==0){
        printf("Thats not posible! %d column is full.\n", get+1);
        return;
    }

    //posun
    if (field[yget][get]==' '){
        field[yget][get]=field[ypick][pick];
        field[ypick][pick]=' ';
    }else{
        yget--;
        if (field[ypick][pick]!=field[yget+1][get]){
            printf("Thats not posible! A symbol can only go to the same symbol.\n");
            return;
        }
        field[yget][get]=field[ypick][pick];
        field[ypick][pick]=' ';
    }
}

bool check(const int rows, const int columns, char field[rows][columns]){
    for (int x=0; x<columns; x++){
        for (int y=0; y<rows-1; y++){
            if (field[y][x]!=field[y+1][x]){
                return false;
            }
        }
    }
    return true;
}

void game_field(const int rows, const int columns, char field[rows][columns]){
    printf("\n1 |");
    int next=0;
    for (int y=0; y<rows; y++){
        for (int x=0; x<columns; x++){
            if (y!=next){
                printf("|\n%d |",y+1);
            }
            next=y;
            printf(" (%c) ",field[y][x]);         
        }
    }
    printf("|\n   ");
    for (int i=0; i<columns; i++){
        printf("=====");
    }
    printf("\n     ");
    for (int i=0; i<columns; i++){
        if (i>8){
            printf("%d   ",i+1);
        }else{
            printf("%d    ",i+1);
        }
    }
    printf("\n");
}

void ball_sort_puzzle(){
    char level[1];
    char answer[0];
    int rows=4;
    int columns=6;

    printf("Welcome to game Ball sort puzzle!\n");
    printf("Have you ever play this game? (y/n) ");
    scanf("%s", level);
    
    do{

        if (level[0]!='y'){
            printf("The most important rule of the game is that the symbol must be moved from one column to another only to the same symbol. \n");
            do{
                if (rows<3 || rows>5 || columns<4 || columns>7){
                    printf("\nPlease enter a number from the range!\n\n");
                }
                printf("Enter the number of rows(3-5): ");
                scanf("%d", &rows);
                printf("Enter the number of columns(4-7): ");
                scanf("%d", &columns);
            }while(rows<3 || rows>5 || columns<4 || columns>7);
        }
        
        else{
            rows=8;
            columns=10;
            do{
                if (rows<5 || rows>9 || columns<8 || columns>12){
                    printf("\nPlease enter a number from the range!\n\n");
                }
                printf("Enter the number of rows(5-9): ");
                scanf("%d", &rows);
                printf("Enter the number of columns(8-12): ");
                scanf("%d", &columns);
            }while(rows<5 || rows>9 || columns<8 || columns>12);
        }

        char field[rows][columns];
        generator(rows, columns, field);
        game_field(rows, columns, field);
        
        int x;
        int y;
        while (check(rows, columns, field)==0){
            printf("Move symbol from: ");
            scanf("%d", &x);
            printf("Move symbol to: ");
            scanf("%d", &y);
            down_possible(rows, columns, field, x, y);
            game_field(rows, columns, field);
        }

        if (level[0]!='y'){
            printf("Congratulation, you won! For begginer it was very good.\n");
        }else{
            printf("Congratulation, you won! \n");
        }

        printf("Do you want to play again? (y/n) ");
        scanf("%s", answer);
        level[0]='y';
    }while (answer[0]=='y');

    printf("Okej, see you next time!\n");
}