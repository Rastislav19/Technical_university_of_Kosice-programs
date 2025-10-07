#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "playfair.h"

//my function for NULL
int is_null2(const char* key, const char* text){
    
    if (text == NULL || key == NULL){
        return 1;
    }
    if (key[0]==' '){
        return 1;
    }
    return 0;
}

//first function
char* playfair_encrypt(const char* key, const char* text){
    
    //if NULL 
    if (is_null2(key, text) == 1){
        return NULL;
    }

    //declaration
    char* final_end = calloc( strlen(text)+1, sizeof *text );
    char* end = calloc( strlen(text)+1, sizeof *text );
    char* final_end2 = calloc( strlen(text)*(1.5), sizeof *text );
    char string[ strlen(key+1) ];
    
    strcpy(string,key);
    
    int i = 0;
    int j = 0;
    
    int a_counter = 0;
    int b_counter = 0;
    int c_counter = 0;

    char cypher[5][5];
    
    int sum = 0;
       
    int final_lenght = 0; 
      
    int col_x = 0; 
    int col_y = 0;
    int row_x = 0; 
    int row_y = 0; 
    int helper = 0;

    for( i = 0; i < strlen(key); i++){
        
        string[i] = toupper(key[i]);
        if( !strchr(ALPHA,string[i]) && !strchr("W",string[i]) ){
            return NULL;
        }  
        if( strchr("W",string[i]) ){
           string[i] = 'V' ;
        }
    }
    
    for( i = 0 ; i < strlen(string); i++){
        for( j = 0 ; j < strlen(string) ; j++){
        if( toupper(string[i]) == toupper(string[j]) && i != j ){
                string[j] = '0';
            }
        }     
    }
    
    a_counter = 0;
    
    for( i = 0 ; i < strlen(string); i++){
        if(string[i] != '0'){
            a_counter++;
        }
    }
    
    char final_string[a_counter];
    
    for( i = 0, j = 0 ; i < strlen(string); i++){
        if(string[i] != '0'){
            final_string[j] = string[i];
            j++;
        }
        final_string[a_counter] = '\0';
    }

    b_counter = 0;
    c_counter = 0;

    for(  i = 0 , c_counter = 0; i < 5 ; i++){
        for( j = 0 ; j < 5 ; j++){
            if(b_counter < a_counter && i > 0){
                cypher[i][j] =  final_string[j+(5*i)];
            }
            else if(b_counter < a_counter){
                cypher[i][j]= final_string[j];
            }
            else if(strchr(final_string,ALPHA[c_counter])== NULL){
                cypher[i][j] = ALPHA[c_counter];
                c_counter++;
            }
            else{
                c_counter++;
                j--;
            }
            b_counter++;
        }
    }
    
    for(int i = 0, j = 0; i < strlen(text) ; i++){
        if(((text[i] != 'X' && text[i] != 'x')&& (text[i] == text[i+1] && i % 2 == 0) && (text[i+1] != 'X'&& text[i+1] != 'x'))){
            end[i+j] = toupper(text[i]);
        }
        else if(text[i] == ' '){
            j--;
        }
        else{
          end[i+j]= toupper(text[i]);
        }
    }

    final_lenght = strlen(end);
    
    sum = 0;
    
    for( i = 0 ; i < final_lenght; i++){
        if(toupper(end[i]) == toupper(end[i+1]) && (toupper(end[i]) != 'X' && toupper(end[i+1]) != 'X')){
            sum++;
            end[i+1] = '0';
            i++;

        }
    
    }    
    
    char string_final[strlen(end)+sum];
    
    for( i =0, j =0  ; i < strlen(end)+sum; i++){
        if(end[i+1] == '0'){
            string_final[i+j] = end[i];
            string_final[i+j+1] ='X';
            j++;
        }
        else{
            string_final[i+j] = end[i];
        }
        
        if(strlen(string_final)%2 != 0){
            string_final[strlen(end)+sum+1]= '\0';
        }
        else{
            string_final[strlen(end)+sum]= '\0';
        }
    }        
    
    for( i = 0 ; i < strlen(end)+sum ; i++){
        if(string_final[i] == '0'){
            string_final[i] = string_final[i-2];
        }
    }
    
    if(strlen(string_final)%2 != 0){
        string_final[strlen(string_final)] = 'X' ;
    }

    for( i = 0; i < strlen(string_final); i = i+2){ 
        for( b_counter = 0 ; b_counter < 5 ; b_counter ++){
            for ( c_counter = 0 ; c_counter < 5 ; c_counter++){
                if(string_final[i] == cypher[b_counter][c_counter]){
                    col_x = b_counter;
                    row_x = c_counter;
                }
                if(string_final[i+1] == cypher[b_counter][c_counter]){
                    col_y = b_counter;
                    row_y = c_counter;
                }
            }
        }

        if(col_x == col_y && row_x == row_y){
            if(col_x == 4){
                col_x = 0;
            }
            else{
                col_x++;
            }
            if(col_y == 4){
                col_y = 0;
            }
            else{
                col_y++;
            }
        }   
        else if(col_x == col_y){
            if(row_x == 4 && row_y == 4){
                row_x = 0;
                row_y = 0;
            }
            else if(row_x == 4){ 
                row_x =0;
                row_y++;
            }  
            else if(row_y == 4){
                row_x++;
                row_y = 0;
            }
            else{
                row_x++;
                row_y++;
            }
        }
        else if(row_x == row_y){
            if(col_x == 4 && col_y == 4){
                col_x = 0;
                col_y = 0;
            }
            else if(col_x == 4){ 
                col_x = 0;
                col_y++;
            }
            else if(col_y == 4){
                col_x++;
                col_y = 0;
            }
            else{
                col_x++;
                col_y++;
            } 
        }   
        else{
            helper = row_x;
            row_x = row_y;
            row_y = helper;
        }
            
        final_end[i] = cypher[col_x][row_x];
        final_end[i+1] = cypher[col_y][row_y];
    }
    
    for ( i = 0 , j = 0; i < strlen(final_end); i++ , j++){
        final_end2[j] += final_end[i];
        if(i % 2 != 0){
            j++;
            final_end2[j] += ' ';
        }
    }

    free(final_end);
    free(end);
    
    if(final_end2[ strlen(final_end2)-1 ] == ' '){
        final_end2[ strlen(final_end2)-1 ] ='\0';
    }
    //return
    return final_end2;
}

char* playfair_decrypt(const char* key, const char* text){
    
    if (is_null2(key, text) == 1){
        return NULL;
    }
    
    for (size_t i=0; i < strlen(text); i++){
        if (text[i] == 'W'){
            return NULL;
        }
    }

    char* final_end = calloc ( strlen(text)-(1/3), sizeof *text );
    char* final_string2 = calloc( strlen(text)+1, sizeof *text );
    char string[ strlen(key) ];
    
    int i = 0;
    int j = 0;
    int s_counter = 0;

    char cypher[5][5];
    int a_counter = 0;
    int b_counter = 0;

    int col_x = 0;
    int col_y = 0;
    int row_x = 0; 
    int row_y = 0; 
    int helper = 0;


    for( i = 0; i< strlen(key); i++){

        string[i]=toupper(key[i]);
        if(!strchr(ALPHA,string[i]) && !strchr("W",string[i])){
            return NULL;
        }  
        if(strchr("W",string[i])){
           string[i] = 'V' ;
        }
    }

    char final_string[s_counter];
    
    for( i = 0 ; i < strlen(string); i++){
        if(string[i] != '0'){
        s_counter++;
        }
    }
    
    for( i = 0;i < strlen(text); i++){
        final_string2[i] = text[i];
    }
    
    for( i = 0 ; i < strlen(string); i++){
        for( j = 0 ; j < strlen(string) ; j++){
        if(toupper(string[i]) == toupper(string[j])&& i != j){
                string[j] = '0';
            }
        }     
    }
    
    for( i = 0, j = 0 ; i < strlen(string); i++){
        if(string[i] != '0'){
            final_string[j] = string[i];
            j++;
        }
        final_string[s_counter] = '\0';
    }

    for( i = 0 , b_counter = 0; i < 5 ; i++){
        for( j = 0 ; j < 5 ; j++){
            if(a_counter < s_counter && i > 0){
            cypher[i][j] =  final_string[j+(5*i)];
            }
            else if(a_counter < s_counter){
                cypher[i][j]= final_string[j];
            }
            else if(strchr(final_string,ALPHA[b_counter])== NULL){
                cypher[i][j] = ALPHA[b_counter];
                b_counter++;
            }
            else{
                b_counter++;
                j--;
            }
            a_counter++;
        }
    }  
    
    for( i = 0,j = 0 ; i < strlen(final_string2); i++){
        if(final_string2[i] != ' '){
            final_end[j] = final_string2[i];
            j++;
        }
    }   
    
    for( i = 0; i < strlen(final_end); i = i+2){
        
        for( a_counter = 0; a_counter < 5; a_counter++){
            for ( b_counter = 0; b_counter < 5; b_counter++){
                if(final_end[i] == cypher[a_counter][b_counter]){
                    col_x = a_counter;
                    row_x = b_counter;
                }
                if(final_end[i+1] == cypher[a_counter][b_counter]){
                    col_y = a_counter;
                    row_y = b_counter;
                }
            }
        }
      
        if(col_x == col_y && row_x == row_y){
            if(col_x == 0){
                col_x = 4;
            }
            else{
                col_x--;
            }
            if(col_y == 0){
                col_y = 4;
            }
            else{
                col_y--;
            }
        }
        else if(col_x == col_y){
            if(row_x == 0 && row_y == 0){
                row_x = 4;
                row_y = 4;
            }
            else if(row_x == 0){ 
                row_x = 4;
                row_y--;
            }
            else if(row_y == 0){
                row_x--;
                row_y = 4;
            }
            else{
                row_x--;
                row_y--;
            }

        }
        else if(row_x == row_y){
            if(col_x == 0 && col_y == 0){
                col_x = 4;
                col_y = 4;
            }
            else if(col_x == 0){ 
                col_x = 4;
                col_y--;
            }
            else if(col_y == 0){
                col_x--;
                col_y = 4;
            }
            else{
                col_x--;
                col_y--;
            }
        }
        else{
            helper = row_x;
            row_x = row_y;
            row_y = helper;     
        } 
        
        final_end[i] = cypher[col_x][row_x];
        final_end[i+1] = cypher[col_y][row_y];
    }
    
    free(final_string2);        
    
    return final_end;
}         





