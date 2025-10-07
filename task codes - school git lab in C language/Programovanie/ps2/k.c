#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "k.h"

bool is_move_possible(const struct game game){
    
    int x = 0;
    int y = 0;
    
    for( x = 0; x < 4; x++ ){
        for( y = 0; y < 4; y++ ){
            if( game.board[ x ][ y ] == ' ' || 
                game.board[ x ][ y ] == game.board[x][y+1] ||
                game.board[ x ][ y ] == game.board[x+1][y]
            ){
                return true;    
            } 
        } 
    }
    return false;
}

void add_random_tile(struct game *game){
    
    int row = 0; 
    int col = 0;
    
    do{
        row = rand()%SIZE;
        col = rand()%SIZE;
    }
    while( game -> board[ row ][ col ] != ' ');

    if( rand()%2 == 0 ){
        game -> board[ row ][ col ] = 'A';
    }
    else{
        game -> board[ row ][ col ] = 'B';
    }
}

bool update(struct game *game, int dy, int dx){
    
    if( (dx == 1 && dy == 1) || 
        (dx == 0 && dy == 0) || 
        (dx == -1 && dy == -1) || 
        (dx == -1 && dy == 1) || 
        (dx == 1 && dy==-1)
    ){
        return false;
    }
    
    char(*view_board)[4] =calloc( sizeof(char[4][4]), sizeof 4 );
    
    int x = 0;
    int y = 0;

    for( x = 0; x < 4; x++ ){
        for( y = 0; y < 4; y++ ){
            view_board[x][y] = game -> board[x][y];
        }
    }

    int counter = 0;
    int place = 0;
    char chaR;
    
    if( dx == 1 && dy == 0 ){
        for( int i = 0; i < 4; i++ ){
            for( int j = 3; j >= 0; j-- ){
                if( game -> board[i][j] != ' ' ){
                    
                    int k = j-1;
                    
                    while( game -> board[i][k] == ' ' && k != -1 ){
                        k--;
                    }
                    if( game -> board[i][j] == game -> board[i][k] && k != -1 ){
                        game -> board[i][j] = (char)(game -> board[i][j]+1);
                        game -> score = (int)(game -> score) + (int)(pow(2, game -> board[i][j]-64));
                        game -> board[i][k] = ' ';
                    }
                }
            }
            
            place = 3;
            
            int x = 0;

            for( x = 3; x >= 0; x-- ){
                if( game -> board[i][x] != ' '){
                    chaR = game -> board[i][x];
                    game -> board[i][x] = ' ';
                    game -> board[i][place] = chaR;
                    place--;
                }
            }
        }
    }           
     
    if ( dx == -1 && dy == 0 ){
        for( int i = 0; i < 4; i++ ){
            for( int j = 0; j < 4; j++ ){
                if( game -> board[i][j] != ' ' ){
                    
                    int k = j+1;
                    
                    while( game -> board[i][k] == ' ' && k != 4 ){
                        k++;
                    }
                    if( game -> board[i][j] == game -> board[i][k] && k != 4 ){
                        game -> board[i][j] = (char)(game -> board[i][j]+1);
                        game -> score = (int)(game -> score) + (int)(pow(2, game -> board[i][j]-64));
                        game->board[i][k] = ' ';
                    } 
                }
            }
            
            place = 0;
            
            int x = 0;

            for( x = 0; x < 4; x++ ){
                if( game -> board[i][x] != ' ' ){
                    chaR = game -> board[i][x];
                    game -> board[i][x] = ' ';
                    game -> board[i][place] = chaR;
                    place++;
                }
            }
        }
    }    
    
    if( dx == 0 && dy == 1 ){
        for( int i = 0; i < 4; i++ ){
            for( int j = 3; j >= 0; j-- ){
                if( game -> board[j][i] != ' ' ){
                    
                    int k = j-1;

                    while( game -> board[k][i] == ' ' && k != -1 ){
                        k--;
                    }
                    if( game -> board[j][i] == game -> board[k][i] && k != -1 ){
                        game -> board[j][i] = (char)(game -> board[j][i]+1);
                        game -> score = (int)(game -> score) + (int)(pow(2, game -> board[j][i]-64));
                        game -> board[k][i] = ' ';
                    }
                }
            }
            
            place = 3;
            
            int x = 0;

            for( x = 3; x >= 0; x-- ){
                
                if( game -> board[x][i] != ' ' ){
                    chaR = game -> board[x][i];
                    game -> board[x][i] = ' ';
                    game -> board[place][i] = chaR;
                    place--;
                }
            }
        }
    }
     
    if( dx == 0 && dy == -1 ){
        for( int i = 0; i < 4; i++){
            for( int j = 0; j < 4; j++ ){
                if( game -> board[j][i] != ' ' ){
                    
                    int k = j+1;
                    
                    while( game -> board[k][i] == ' ' && k != 4){
                        k++;
                    }
                     if( game -> board[j][i] == game -> board[k][i] && k != 4 ){
                        game -> board[j][i] = (char)(game -> board[j][i]+1);
                        game -> score = (int)(game -> score) + (int)(pow(2, game -> board[j][i]-64));
                        game -> board[k][i] = ' ';
                    }
                }
            }
            
            place = 0;

            int x = 0;

            for( x = 0; x < 4; x++ ){
                if( game -> board[x][i] != ' ' ){
                    chaR = game -> board[x][i];
                    game -> board[x][i] = ' ';
                    game -> board[place][i] = chaR;
                    place++;
                }
            }
        }
    }
    
    for( int i = 0; i < 4; i++){
        for( int j = 0; j < 4; j++){
            if( view_board[i][j] != game -> board[i][j]){
                counter = 1;
            }
        }
    }
    
    free( view_board );
    
    if( counter == 0 ){
        return false;
    }
    return true;
}


    /*
    if( (dy == 1 && dx == 0) ||
        (dy == 0 && dx == 1) ||
        (dy == -1 && dx == 0) ||
        (dy == 0 && dx == -1)
    ){
        if(dy == 1){
            for(int i = 0; i < 4; i++){
                for(int idx=4; idx > 0; idx--){
                    if(game->board[idx][i] != ' '){
                        for(idx=idx; idx > (0+idx); idx--){
                            if(game->board[idx-1][i] == ' '){
                                game->board[idx-1][i] == game->board[idx][i];
                            }
                            else if(game->board[idx-1][i] == game->board[idx][i]){
                                if( game->board[idx][i] == 'A'){
                                    game->board[idx-1][i] == 'B';
                                }
                                if( game->board[idx][i] == 'B'){
                                    game->board[idx-1][i] == 'C';
                                }
                                if( game->board[idx][i] == 'C'){
                                    game->board[idx-1][i] == 'D';
                                }
                                if( game->board[idx][i] == 'D'){
                                    game->board[idx-1][i] == 'E';
                                }
                                if( game->board[idx][i] == 'E'){
                                    game->board[idx-1][i] == 'F';
                                }
                                if( game->board[idx][i] == 'F'){
                                    game->board[idx-1][i] == 'G';    
                                }
                                if( game->board[idx][i] == 'G'){
                                    game->board[idx-1][i] == 'H';    
                                }
                                if( game->board[idx][i] == 'H'){
                                    game->board[idx-1][i] == 'I';    
                                }
                                if( game->board[idx][i] == 'I'){
                                    game->board[idx-1][i] == 'J';    
                                }
                                if( game->board[idx][i] == 'J'){
                                    game->board[idx-1][i] == 'K';    
                                }
                            }
                            else{
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(dy == -1){
            for(int i=0; i < 4; i++){
                for(int idx=0; idx < 4; idx++){
                    if(game->board[idx][i] != ' '){    
                        for(idx=idx; idx < (4-idx); idx++){
                            if(game->board[idx+1][i] == ' '){
                                game->board[idx+1][i] == game->board[idx][i];    
                            }       
                            else if(game->board[idx+1][i] == game->board[idx][i]){
                                if( game->board[idx][i] == 'A'){
                                    game->board[idx+1][i] == 'B';    
                                }
                                if( game->board[idx][i] == 'B'){
                                    game->board[idx+1][i] == 'C';    
                                }
                                if( game->board[idx][i] == 'C'){
                                    game->board[idx+1][i] == 'D';   
                                }
                                if( game->board[idx][i] == 'D'){
                                    game->board[idx+1][i] == 'E';    
                                }
                                if( game->board[idx][i] == 'E'){
                                    game->board[idx+1][i] == 'F';    
                                }
                                if( game->board[idx][i] == 'F'){
                                    game->board[idx+1][i] == 'G';    
                                }
                                if( game->board[idx][i] == 'G'){
                                    game->board[idx+1][i] == 'H';    
                                }
                                if( game->board[idx][i] == 'H'){
                                    game->board[idx+1][i] == 'I';    
                                }
                                if( game->board[idx][i] == 'I'){
                                    game->board[idx+1][i] == 'J';    
                                }
                                if( game->board[idx][i] == 'J'){
                                    game->board[idx+1][i] == 'K';    
                                }
                            }
                            else{
                                break;
                            }
                        }
                    }
                }    
            }
        }
        if(dx == 1){
            for(int idx=0; idx < 4; idx++){
                for(int i=0; i < 4; i++){
                    if(game->board[idx][i] != ' '){    
                        for(i=i; i < (4-i); i++){
                            if(game->board[idx][i+1] == ' '){
                                game->board[idx][i+1] == game->board[idx][i];    
                            }    
                            else if(game->board[idx][i+1] == game->board[idx][i]){
                                if( game->board[idx][i] == 'A'){
                                    game->board[idx][i+1] == 'B';    
                                }
                                if( game->board[idx][i] == 'B'){
                                    game->board[idx][i+1] == 'C';    
                                }
                                if( game->board[idx][i] == 'C'){
                                    game->board[idx][i+1] == 'D';   
                                }
                                if( game->board[idx][i] == 'D'){
                                    game->board[idx][i+1] == 'E';    
                                }
                                if( game->board[idx][i] == 'E'){
                                    game->board[idx][i+1] == 'F';    
                                }
                                if( game->board[idx][i] == 'F'){
                                    game->board[idx][i+1] == 'G';    
                                }
                                if( game->board[idx][i] == 'G'){
                                    game->board[idx][i+1] == 'H';    
                                }
                                if( game->board[idx][i] == 'H'){
                                    game->board[idx][i+1] == 'I';    
                                }
                                if( game->board[idx][i] == 'I'){
                                    game->board[idx][i+1] == 'J';    
                                }
                                if( game->board[idx][i] == 'J'){
                                    game->board[idx][i+1] == 'K';    
                                }
                            }
                            else{
                                break;
                            }
                        }
                    }
                }    
            }            
        }
        if(dx == -1){
            for(int idx=0; idx < 4; idx++){
                for(int i=4; i > 0; i--){
                    if(game->board[idx][i] != ' '){    
                        for(i=i; i > (0+i); i--){
                            if(game->board[idx][i-1] == ' '){
                                game->board[idx][i-1] == game->board[idx][i];    
                            }     
                            else if(game->board[idx][i-1] == game->board[idx][i]){
                                if( game->board[idx][i] == 'A'){
                                    game->board[idx][i-1] == 'B';    
                                }
                                if( game->board[idx][i] == 'B'){
                                    game->board[idx][i-1] == 'C';    
                                }
                                if( game->board[idx][i] == 'C'){
                                    game->board[idx][i-1] == 'D';   
                                }
                                if( game->board[idx][i] == 'D'){
                                    game->board[idx][i-1] == 'E';    
                                }
                                if( game->board[idx][i] == 'E'){
                                    game->board[idx][i-1] == 'F';    
                                }
                                if( game->board[idx][i] == 'F'){
                                    game->board[idx][i-1] == 'G';    
                                }
                                if( game->board[idx][i] == 'G'){
                                    game->board[idx][i-1] == 'H';    
                                }
                                if( game->board[idx][i] == 'H'){
                                    game->board[idx][i-1] == 'I';    
                                }
                                if( game->board[idx][i] == 'I'){
                                    game->board[idx][i-1] == 'J';    
                                }
                                if( game->board[idx][i] == 'J'){
                                    game->board[idx][i-1] == 'K';    
                                }
                            }
                            else{
                                break;
                            }
                        }
                    }
                }    
            }                        
        }             
        return 1;              
    } 
    return 0;
}
*/

bool is_game_won(const struct game game){
    
    size_t x = 0;
    size_t y = 0;

    for( x = 0; x < 4 ; x++ ){
        for( y = 0; y < 4; y++ ){
            if( game.board[x][y] == 'K' ){
                return true;
            }
        }
    }
    return false;
}




