#include <stdio.h>
#include <stdlib.h>  
#include <stdbool.h>
#include <math.h>
#include <string.h>

void encode_char(const char character, bool bits[8]);
char decode_byte(const bool bits[8]);
void encode_string(const char string[], bool bytes[strlen(string)+1][8]);
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]);
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);


int main(){

  
    return 0;
}

void encode_char(const char character, bool bits[8]){
    
    int dec = (int)character;
    
    for(int idx=7; idx >= 0 ; idx--){
        bits[idx]= dec%2;
        dec = dec/2; 
    }   
}

char decode_byte(const bool bits[8]){
    
    int exponent=0;
    int dec=0;

    for(int idx=7; idx >= 0; idx--, exponent++ ){
        dec= dec + ( bits[idx] * pow(2,exponent) );
    }
    return dec;
}

void encode_string(const char string[], bool bytes[strlen(string)+1][8]){
    
    bool bits[8];

    for(int idx=0, len= strlen(string); idx < len; idx++ ){
        encode_char( string[idx], bits);
        for(int i=0; i < 8; i++){
            bytes[idx][i]=bits[i];
        }
    }
    for(int i=0; i < 8; i++){
        bytes[strlen(string)][i]= 0;
    }
}

void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]){
    
    bool bits[8];
    
    for(int idx=0; idx < rows; idx++){
        for(int i=0; i < 8 ; i++){
            bits[i]= bytes[idx][i];
        }
        string[idx]= decode_byte ( bits );             
    } 
}

void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
    
    int move=0;
    int move2=0;
    int how=1;

    for(int j=0; j < offset; j++){
        for(int idx=(0+move2) ; idx < cols*how ; idx++){
            if( idx < rows ){
                for(int i=0; i < 8; i++){
                    blocks[i+move][idx-move2]= bytes[idx][i];
                }
            }
            else{
                for(int i=0; i < 8; i++){
                    blocks[i+move][2]= 0 ;
                }
            }
        }
        move= move + 8;
        move2= move2 + cols;
        how++;
    }
}

void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
    
    int how=1;
    int move=0;
    int move2=0;
      
    for(int j; j < offset; j++){
        for(int idx=0+move ; idx < how*8 ; idx++){ 
            for(int i=0; i < cols; i++){
                if(i+move2 < rows){
                    bytes[i+move2][idx-move]= blocks[idx][i];
                }
            }    
        }
    move= move + 8;
    move2= move2 + cols;
    how++;
    }
}

