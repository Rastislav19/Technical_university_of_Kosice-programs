#include <stdio.h>
#include <stdlib.h>
#include "hangman.h"

int main (){
    
    char secret[15];
    get_word(secret);  
    hangman(secret);
    
    return 0;
}
    
