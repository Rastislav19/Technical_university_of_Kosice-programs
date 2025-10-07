#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bmp.h"
#include "playfair.h"

int main(){


    playfair_encrypt("SeCReT", "Hello world");

    playfair_decrypt("world", "hello");

    reverse("Hello world!");
    
    vigenere_encrypt("CoMPuTeR", "Hello world!");    
    
    vigenere_decrypt("CoMPuTeR", "Hello world!"); 
    
    bit_encrypt("Hello world!");

    bit_decrypt((unsigned char*)"Hello world!");

    bmp_encrypt("CoMPuTeR","Hello world!");

    bmp_decrypt("CoMPuTeR", (unsigned char*)"Hello world!"); 


    return 0;
}


