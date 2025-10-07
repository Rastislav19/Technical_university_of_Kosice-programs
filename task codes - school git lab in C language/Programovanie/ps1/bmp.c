#include <stdio.h>
#include "bmp.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

/*
char* reverse(const char* text){
    if (text == NULL){
        return NULL;
    }
    for( int i = 0; i < strlen(text); i++){
        reverse_text[strlen(text)]=toupper(text[i]);
    }
    return reverse_text;
}  
*/

//my fuction for NULL
int is_null(const char* key, const char* text){
    
    if( key == NULL || text == NULL){
        return 1;
    }
    for (int i = 0; i < strlen(key); i++){
        if ( (key[i] < 65 || key[i] > 90) && (key[i] < 97 || key[i] > 122)){
            return 1;
        }
    }
    return 0;
}

//first function
char *reverse(const char *text){  

    //NULL string
    if (text == NULL){
        return NULL;
    }
    
    //declaration
    char* reversed_text = calloc(strlen(text) + 1, sizeof *text);
    int j = 0;
    int i = 0;   
    
    //first while
    //while(i < strlen(text)){
        //input[i] += toupper(text[j]);
        //i++;
        //j--;
    //}
     
    //while to for     
    for( j = 0, i = strlen(text) -1; j < strlen(text); j++, i-- ){
       
        reversed_text[j] = toupper(text[i]);   
        reversed_text[j+1] = '\0';

    }
    
    //return
    return reversed_text;    
}

//second function
char* vigenere_encrypt(const char *key, const char *text){
    
    //empty or NULL string
    if( is_null(key, text) == 1 ){
        return NULL;
    }

    //if(text == NULL || key == NULL || key[0] == '\0'){
      //  return NULL;
    //}    
    
    //declaration
    char alphabet[52]= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char upper_letters[26]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    int a_counter= 0;
    int b_counter= 0;
    int i= 0;
    int j= 0;
    
    char* encrypt_text = calloc( strlen(text), sizeof *text );
    char password[ strlen(text) ];
      
    int end = 0;
    
    //first while 
    // while( i < strlen(key) ){
       // if( !strchr( alphabet, key[i]) ){
           // return NULL;
        //}
        //i++;
    //}   
    
    //while to for
    for( i = 0; i < strlen(key); i++  ){
        
        if( !strchr( alphabet, key[i] ) ){
            return NULL;
        }
    }
 
    //second while
    while( a_counter < strlen(text) ){
        
        if( b_counter == strlen(key) ){
            b_counter = 0;
        }
        password[ a_counter ] = toupper( key[b_counter] );
        a_counter++;
        b_counter++;
    }
    
    //add terminator on the end
    password[ strlen(text) ] = '\0';

    //first for
    for( i = 0, j = 0; i < strlen(text); i++, j++ ){
        
        end = 0;
        
        if( text[i] == ' ' || password[i] == ' ' ){
            encrypt_text[i] = ' ';
            j--;
        }
        else if (text[i] == '!'){
            encrypt_text[i] = '!';
            j--;
            continue;
        }
        else{
            end = (((toupper(text[i]) + password[j])) - 130) % 26;
            encrypt_text[i] = upper_letters[end];
        }
    }
    //return
    return encrypt_text;
}

//third function
char *vigenere_decrypt(const char *key, const char *text){
    
    //empty or NULL string
    if( is_null(key, text) == 1 ){
        return NULL;
    }

    //if (text == NULL || key == NULL || key[0] == '\0'){
      //  return NULL;
    //}
    
    //declaration
    char alphabet[52] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char upper_letters[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *decrypt_text = calloc(strlen(text), sizeof(text));
    char password[ strlen(text) ];
    int a_counter = 0;
  
    int i = 0;
    int j = 0;
    
    int end = 0;
        
    //first while
    //while(a_counter < strlen(key)){
        //if (!strchr(alphabet, key[a_counter])){
          //  return NULL;
        //}
        //a_counter++;
    //}
    
    //while to for
    for( a_counter = 0; a_counter < strlen(key); a_counter++ ){
        if( !strchr(alphabet, key[a_counter]) ){
            return NULL;
        }
    }

    //second while
    while( i < strlen(text) ){
        if( j == strlen(key) ){
            j = 0;
        }
        j++;
        i++;
        password[i] = toupper(key[j]);
    } 
    
    //add terminator on the end
    password[strlen(text)] = '\0';
    
    //forth for
    for( i = 0, j = 0; i < strlen(text); i++, j++ ){
        
        end = 0;
        
        if( text[i] == ' ' || password[i] == ' ' ){
            decrypt_text[i] = ' ';
            j--;
        }
        else if( text[i] == '!' ){
            decrypt_text[i] = '!';
            j--;
            continue;
        }
        else{
            end = (toupper(text[i] - 65) - (password[j] - 65) + 26) % 26;
            decrypt_text[i] = upper_letters[end];
        }
    }
    //return
    return decrypt_text;
}

//my function
int enc_bits(const char* text, const int i){
    
    int letter = text[i];
    int byte[] = {0,0,0,0,0,0,0,0};
    int position = 7;
    
    while( letter != 0 ) {
        if( letter%2 == 1 ){
            byte[position] = 1;
        }
        letter = letter/2;
        position--;
    }
    
    int x = byte[0];
    
    byte[0] = byte[1];
    byte[1] = x;
    x = byte[2];
    byte[2] = byte[3];
    byte[3] = x;

    
    for(int i = 0; i < 4; i++){
        if(byte[i] == byte[i+4]){
            byte[i+4] = 0;
        }
        else{
            byte[i+4] = 1;
        }
    }
    
    position=0;
    letter=0;
    
    for (int i = 7; i >= 0; i--){
        letter = letter+byte[position]*pow(2, i);
        position++;
    }
    return letter;
}

//forth function
unsigned char* bit_encrypt(const char* text){
    
    //empty or NULL string
    if( text == NULL ){
        return NULL;
    }
    
    //declaration
    unsigned char *encrypt_text = calloc(strlen(text)+1, sizeof *text);
    
    for( int i = 0; i < strlen(text); i++){
        encrypt_text[i] = enc_bits(text, i);
    }
    return encrypt_text;
}

/*
unsigned char *bit_encrypt(const char *text){
    
    //NULL string
    if( text == NULL || text[0] == '\0' ){
        return NULL;
    }
    
    //declaration
    int bits[strlen(text)][8];
    unsigned char end[strlen(text)];
    unsigned char *end2 = calloc(strlen(text) + 1, sizeof(text));
    
    int a_counter = 0;
    int b_counter = 0;
    int c_counter = 0;
    int d_counter = 0;
    
    int offset = 0;
    
    int sum=0;

    //first while
    while( a_counter < strlen(text) ){
            
        c_counter = text[a_counter];
        
        for( int i = 0, j = 128; i < 8; i++ ){
            if(c_counter < j){
                bits[a_counter][i] = 0;
                j = j / 2;
            }
            else{
                bits[a_counter][i] = 1;
                c_counter = c_counter - j;
                j = j / 2;
            }
        }
        a_counter++;
    }
    
    //second while
    while( b_counter < strlen(text) ){
        
        for( int i = 0; i < 4; i = i + 2 ){
            
            offset = bits[b_counter][i];
            
            bits[b_counter][i] = bits[b_counter][i + 1];
            bits[b_counter][i + 1] = offset;
        }
        b_counter++;
    }
    
    //third while
    while( c_counter < (strlen(text)) ){
        for( int i = 0, j = 4; i < 4; i++, j++ ){
            bits[c_counter][j] = bits[c_counter][i] != bits[c_counter][j];
        }
        c_counter++;
    }
    
    //forth while
    while( d_counter < strlen(text) ){
        
        sum = 0;
        
        for( int j = 0, y = 128; j < 8; j++ ){
            if( bits[d_counter][j] == 1 ){
                sum = sum + y;
                y = y / 2;
            }
            else{
                y = y / 2;
            }
        }
        end[d_counter] = sum;
        end2[d_counter] = end[d_counter];
        d_counter++;
    }
    
    //return
    return end2;
}
*/

int dec_bits(const unsigned char* text, const int i){
    
    int letter=text[i];
    int byte[]={0,0,0,0,0,0,0,0};
    int position=7;
    while (letter!=0) {
        if (letter%2==1){
            byte[position] = 1;
        }
        letter=letter/2;
        position--;
    }
    // changing bits 2
    for (int i = 0; i < 4; i++){
        if (byte[i] == byte[i+4]){
            byte[i+4] = 0;
        }
        else{
            byte[i+4] = 1;
        }
    }
    // changing bits 1
    int x = byte[0];

    byte[0] = byte[1];
    byte[1] = x;
    x = byte[2];
    byte[2] = byte[3];
    byte[3] = x;
    
    position=0;
    letter=0;

    for(int i = 7; i >= 0; i--){
        letter = letter+byte[position]*pow(2, i);
        position++;
    }
    return letter;
}

//fifth function
char* bit_decrypt(const unsigned char* text){
    
    if(text == NULL){
        return NULL;
    }

    char *decrypt_text = calloc(500, sizeof *text);
    int i=0;
    while (text[i] != '\0'){
        decrypt_text[i] = dec_bits(text, i);
        i++;
    }
    return decrypt_text;
}


/*
char *bit_decrypt(const unsigned char *text){
    
    //declaration
    int bits[strlen((char *)text)][8];
    char end[strlen((char *)text)];
    char *end1 = calloc(strlen((char *)text) + 1, sizeof((char *)text));
    
    int i = 0;
    int k = 0;
    int l = 0;
    int a_counter = 0;
    int b_counter = 0;
    int c_counter = 0;
    int j = 0;   

    int offset= 0;
       
    
    int sum = 0;

    //NULL string
    //if(text == NULL || text[0] == '\0' ){
      //   return NULL;
    //}
    
    //first while
    while(i < strlen((char *)text)){
        
        c_counter = text[i];
        
        for ( k = 0, j = 128; k < 8; k++){
            if (c_counter < j){
                bits[i][k] = 0;
                j = j / 2;
            }
            else{
                bits[i][k] = 1;
                c_counter = c_counter - j;
                j = j / 2;
            }
        }
        i++;
    }
    
    //second while
    while (k < (strlen((char *)text))){
        for ( i = 0, j = 4; i < 4; i++, j++){
            bits[k][j] = bits[k][i] != bits[k][j];
        }
        k++;
    } 
    
    //third while
    while (a_counter < strlen((char *)text)){
        for( j = 0; j < 4; j = j + 2){
            offset = bits[a_counter][j];
            bits[a_counter][j] = bits[a_counter][j + 1];
            bits[a_counter][j + 1] = offset;
        }
        a_counter++;
    } 
    
    //forth while
    while (b_counter < strlen((char *)text)){
        
        sum = 0;
        
        for ( j = 0, l = 128; j < 8; j++){
            if (bits[b_counter][j] == 1){
                sum = sum + l;
                l = l / 2;
            }
            else{
                l = l / 2;
            }
        }
        end[b_counter] = sum;
        end1[b_counter] = end[b_counter];
        b_counter++;
    }
    
    //return
    return end1;
}*/


//sixth function
unsigned char *bmp_encrypt(const char *key, const char *text){
        
    //empty or NULL string
    if ( text == NULL || key == NULL){
        return NULL;
    }
    
    //declaration
    char *reversed;
    unsigned char *bit_encrypted;
    char *vigenere;

    reversed = reverse(text);
    vigenere = vigenere_encrypt(key, reversed);
    bit_encrypted = bit_encrypt(vigenere);
    
    free(reversed);
    free(vigenere);
    
    //return
    return bit_encrypted;
}

//seventh function
char *bmp_decrypt(const char *key, const unsigned char *text){
        
    //empty or NULL string
    if ( text == NULL || key == NULL){
        return NULL;
    }
     
    //declarration
    char *reversed;
    char *bit_decrypted;
    char *vigenere;
    
    bit_decrypted = bit_decrypt(text);
    vigenere = vigenere_decrypt(key, bit_decrypted);
    reversed = reverse(vigenere);
    
    free(bit_decrypted);
    free(vigenere);
    
    //return
    return reversed;
}

