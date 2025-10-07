#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hof.h"

int score_2(const void *p1, const void *p2){
    
    struct player* player1 = (struct player*)p1;
    struct player* player2 = (struct player*)p2;
    
    if( player1 -> score < player2 -> score ){
        return 1;
    }    
    else if( player1 -> score > player2 -> score ){
        return -1;
    }
    else{
        return 0;
    }    
}



int load(struct player list[]){

    FILE* f_p = fopen( "score", "r" );    
    
    if( f_p == NULL ){
        return -1;
    }
    
    fpos_t place;
    
    fgetpos( f_p, &place );
    
    int how_many = 0;
    int chaR = 0;
    
    chaR = fgetc( f_p );
    
    while( chaR != EOF ){
        
        chaR = fgetc( f_p );
        
        if( chaR == '\n' ){
            how_many++;
        }
    }

    fsetpos( f_p, &place );
    
    size_t x = 0;
    
    for( x = 0; x < how_many; x++ ){
        fscanf( f_p, "%s %d", list[x].name, &list[x].score );    
    }

    fclose( f_p );
    
    qsort( list, (size_t)(how_many), sizeof list[0], score_2);
    
    return how_many;
}


bool save(const struct player list[], const int size){
    
    FILE* f_p = fopen( "score", "w" );
    
    if( f_p == NULL ){
        return false;
    }
    
    size_t x = 0;
    
    for( x = 0; x < size; x++ ){
        
        fprintf( f_p, "%s %d", list[x].name, list[x].score);
        
        if( x+1 != size ){
            fprintf( f_p, "\n" );
        }
    }
    
    fclose(f_p);

    return true;

}
bool add_player(struct player list[], int* size, const struct player player){
    
    struct player update_list[11];    
    int x = 0;

    for( x = 0; x < *size; x++ ){
        update_list[x+1] = list[x];    
    }

    update_list[0] = player;
    
    qsort( update_list,(size_t)(*size+1),sizeof list[0],score_2 );
    
    if( *size < 10 ){
        
        *size = *size+1;
        
        int x = 0;

        for( x = 0; x < *size; x++){
            list[x] = update_list[x];
        }
        
        return true;
    
    }
    else{
        
        int x = 0;

        for ( x = 0; x < *size; x++){
            list[x] = update_list[x];
        }
        
        for ( x = 0; x < *size; x++){           
            if( strcmp( list[x].name, player.name) == 0 && list[x].score == player.score){
                return true;
            }
        }
    }
    return false;
}

