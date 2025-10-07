#define _POSIX_C_SOURCE 200201L
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main( int argc, char *argv[]){
    srand(time(NULL));

    //argument prikazoveho riadka 
    if( argc < 2 ){
        printf("Not enough arguments!\n");
        return 1;
    }
    
    int lvl;
    sscanf(argv[1],"%d", &lvl);
    if(lvl > 4 || lvl < 0){
        printf("Wrong argument! Should be 1-3.\n");    
        return 1;
    }
   //create new screen
    initscr();

    //initialize colors
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    //other libraries
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    
    // my code  
    //generate world
    char world[30][30];
    int i, j, height = 30;
    int width = 30;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == width - 1 || j == 0
                || j == height - 1) {
                world[i][j]='#';
            }
            else {
                world[i][j]=' ';
            }
        }
    }  
    //map    
    if(lvl == 1 ){
           world[7][11]= '@'; world[7][12]= '@';  
         world[8][10]= '@';
         world[9][10]= '@';
        world[10][10]= '@';

         world[3][20]= '@';     
         world[4][20]= '@';
         world[5][20]= '@';
         world[6][20]= '@';
         world[7][20]= '@';
         world[8][20]= '@';
         world[9][20]= '@';
        world[10][20]= '@';
        
        world[13][6]= '@'; world[13][7]= '@'; world[13][8]= '@';                                
        world[14][6]= '@'; world[14][7]= '@'; world[14][8]= '@';
        world[15][6]= '@'; world[15][7]= '@'; world[15][8]= '@';

                                                                    world[17][15]= '@';
                                                                    world[18][15]= '@';
                                                                    world[19][15]= '@';       
        world[20][12]= '@'; world[20][13]= '@'; world[20][14]= '@'; world[20][15]= '@';  world[20][16]= '@'; world[20][17]= '@'; world[20][18]= '@';
                                                                    world[21][15]= '@';
                                                                    world[22][15]= '@';
                                                                    world[23][15]= '@';
        world[24][3]= '@';
        world[25][3]= '@'; world[25][4]= '@';        
    }
    else if(lvl == 2){
        world[5][10]='@'; world[5][11]= '@'; world[5][12]= '@'; world[5][13]= '@'; world[5][14]= '@'; world[5][15]= '@'; world[5][16]= '@'; world[5][17]= '@'; world[5][18]= '@'; world[5][19]= '@'; world[5][20]= '@';
        world[8][5]= '@'; world[8][6]= '@'; world[8][7]= '@'; world[8][8]= '@'; world[8][9]= '@'; world[8][10]= '@'; world[8][11]= '@'; world[8][12]= '@'; world[8][13]= '@'; world[8][14]= '@'; world[8][15]= '@';
        world[11][15]= '@'; world[11][16]= '@'; world[11][17]= '@'; world[11][18]= '@'; world[11][19]= '@'; world[11][20]= '@'; world[11][21]= '@'; world[11][22]= '@'; world[11][23]= '@'; world[11][24]= '@'; world[11][25]= '@';
        world[14][10]= '@'; world[14][11]= '@'; world[14][12]= '@'; world[14][13]= '@'; world[14][14]= '@'; world[14][15]= '@'; world[14][16]= '@'; world[14][17]= '@'; world[14][18]= '@'; world[14][19]= '@'; world[14][20]= '@';
        world[17][5]= '@'; world[17][6]= '@'; world[17][7]= '@'; world[17][8]= '@'; world[17][9]= '@'; world[17][10]= '@'; world[17][11]= '@'; world[17][12]= '@'; world[17][13]= '@'; world[17][14]= '@';  world[17][15]= '@';
        world[20][15]= '@';  world[20][16]= '@';  world[20][17]= '@';  world[20][18]= '@';  world[20][19]= '@';  world[20][20]= '@';  world[20][21]= '@';  world[20][22]= '@';  world[20][23]= '@'; world[20][24]= '@'; world[20][25]= '@';
        world[23][10]= '@'; world[23][11]= '@'; world[23][12]= '@'; world[23][13]= '@'; world[23][14]= '@'; world[23][15]= '@'; world[23][16]= '@'; world[23][17]= '@'; world[23][18]= '@'; world[23][19]= '@'; world[23][20]= '@';  
    }
    else{
        world[3][4]= '@'; world[3][5]= '@'; world[3][6]= '@'; world[3][7]= '@'; 
        world[6][4]= '@'; world[6][5]= '@'; world[6][6]= '@'; world[6][7]= '@'; world[6][8]= '@';  
        world[9][4]= '@'; world[9][5]= '@'; world[9][6]= '@'; world[9][7]= '@'; world[9][8]= '@'; world[9][9]= '@'; 
        world[12][4]= '@'; world[12][5]= '@'; world[12][6]= '@'; world[12][7]= '@'; world[12][8]= '@'; world[12][9]= '@'; world[12][10]= '@'; 

        world[18][19]= '@'; world[18][20]= '@'; world[18][21]= '@'; world[18][22]= '@'; world[18][23]= '@'; world[18][24]= '@'; world[18][25]= '@'; 
        world[21][20]= '@'; world[21][21]= '@'; world[21][22]= '@'; world[21][23]= '@'; world[21][24]= '@'; world[21][25]= '@'; 
        world[24][21]= '@'; world[24][22]= '@'; world[24][23]= '@'; world[24][24]= '@'; world[24][25]= '@'; 
        world[27][22]= '@'; world[27][23]= '@'; world[27][24]= '@'; world[27][25]= '@'; 
   }    
   //generate fruit 
    int fruitx=0;
    int fruity=0;   
    while(1){                    
        fruitx= rand() % 28;    
        fruity= rand() % 28;       
        if(fruity==0 || fruitx==0){
            continue;
        }
         //add fruit
        if(world[fruity][fruitx] != '^' && world[fruity][fruitx] != '>' && world[fruity][fruitx] != 'v' && world[fruity][fruitx] != '<' && world[fruity][fruitx] != '@' && world[fruity][fruitx] !='*'){
            world[fruity][fruitx] = '$';
            break;            
        }
        else{
            continue;    
        }
        
    }
     //draw
    for(int y=0; y < 30; y++){
        move(y,0); 
        for(int x=0; x < 30; x++){
            if(world[y][x] == '$'){
                attron(COLOR_PAIR(1));
            }
            else{
                attron(COLOR_PAIR(2));
            }
            printw("%c", world[y][x]);
            if(world[y][x] == '$'){
                attroff(COLOR_PAIR(1));
            }
            else{
                attroff(COLOR_PAIR(2));
            }
        }
        move(1+y,0); 
    }
    int score=0;
    mvprintw(31,0, "[Q]=quit [KEY]=movement");
    mvprintw(32,0, "SCORE:0");

    //move
    int y=15;
    int x=14;
    char player= '^', previous = '*';
    mvprintw(y,x, "%c", player);
    refresh();
    int c;
    int count=0;

    do{
        c=getch();
        if( c == KEY_LEFT || c == KEY_RIGHT || c == KEY_UP || c == KEY_DOWN){
            mvprintw(y,x, "%c", previous);          
            count++;
            world[y][x]= '*';
        }
        switch(c){
            case KEY_LEFT : player = '<';                             
                            x= ( x > 0) ? x-1 : 30 -1;
                            break;
            case KEY_RIGHT : player = '>';
                             x = (x < 30 - 1 ) ? x + 1 : 0;   
                             break;
            case KEY_UP : player = '^';
                          y = (y>0) ? y -1 : 30 -1;
                          break;
            case KEY_DOWN : player = 'v';
                            y= (y < 30-1) ? y+1 : 0;
                            break;
            default: continue; break;
        }
        //body?
        if(world[y][x] == '*'){    
            score= score +count;
            mvprintw(32,6, "%d", score);
                    
            mvprintw(y,x, "X");
            attron(COLOR_PAIR(3));
            mvprintw(33,0, "GAME OVER!");
            attroff(COLOR_PAIR(3));
            refresh();
            getchar();
            endwin();
            return EXIT_SUCCESS;
        }
        mvprintw(y,x,"%c", player);
        refresh();
        
        //borders
        if (x < 1  || x > 28 || y  < 1 || y > 28){
            score= score + count;
            mvprintw(32,6, "%d", score);

            mvprintw(y,x, "X");
            attron(COLOR_PAIR(3));
            mvprintw(33,0, "GAME OVER!");
            attroff(COLOR_PAIR(3)); 
            refresh();
            getchar();
            endwin();
            return EXIT_SUCCESS;
        }
        //hampers
        for(int idx=0; idx < 30; idx++){
            for(int i =0; i < 30; i++){
                if(world[y][x] == '@'){    
                    score= score +count;
                    mvprintw(32,6, "%d", score);
                    
                    mvprintw(y,x, "X");
                    attron(COLOR_PAIR(3));
                    mvprintw(33,0, "GAME OVER!");
                    attroff(COLOR_PAIR(3));
                    refresh();
                    getchar();
                    endwin();
                    return EXIT_SUCCESS;
                }
            }
        }     
        //if fruit was eaten
        if( x == fruitx && y == fruity){           
            //+score
            score= score + 100;
            mvprintw(32,6,"%d", score); 

            //generate new fruit 
            fruitx=0;
            fruity=0;
            while( 1 ){             
                fruitx= rand() % 28;    
                fruity= rand() % 28;       
                if(fruitx==0 || fruity==0){
                    continue;
                }
                //add new fruit
                if(world[fruity][fruitx] != '^' && world[fruity][fruitx] != '>' && world[fruity][fruitx] != 'v' && world[fruity][fruitx] != '<' && world[fruity][fruitx] != '@' && world[fruity][fruitx] != '*'){
                    world[fruity][fruitx] = '$';
                    break;
                }
                else{
                    continue;    
                }
          
            }
            attron(COLOR_PAIR(1));
            mvprintw(fruity,fruitx, "$");
            attroff(COLOR_PAIR(1));
            refresh();
        }
    }while(c != 'q' && c != 'Q');

      //WIN
    attron(COLOR_PAIR(3));
    mvprintw(33 , 0, "BYE!");
    attroff(COLOR_PAIR(3));
    score= score + count;
    mvprintw(32,6,"%d", score);
    refresh();
    getchar();
    endwin();
    
    return EXIT_SUCCESS;
}
             
