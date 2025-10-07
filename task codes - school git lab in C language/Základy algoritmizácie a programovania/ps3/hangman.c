#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"
#include "string.h"


int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}

int is_word_guessed(const char secret[], const char letters_guessed[]){
    int check=0;
    int secret_long=strlen(secret);
    int guessletters_long=strlen(letters_guessed);
    for (int i=0; i<secret_long; i++){
        for(int x=0; x<guessletters_long; x++){
            if (secret[i]==letters_guessed[x]){
                check++;
            }     
        }
    }
    if (check==secret_long){
        return 1;
    }
    return 0;
}

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){
    int secret_long=strlen(secret);
    int guessletters_long=strlen(letters_guessed);
    for (int i=0; i<secret_long; i++){
        guessed_word[i]='_';
    }
    guessed_word[secret_long]='\0';
    for (int i=0; i<secret_long; i++){
        for(int x=0; x<guessletters_long; x++){
            if (secret[i]==letters_guessed[x]){
                guessed_word[i]=letters_guessed[x];
            }
        }
    }
}

void get_available_letters(const char letters_guessed[], char available_letters[]){
    int guessletters_long=strlen(letters_guessed);
    int add=0;
    int count=0;
    char check[1];
    for (int i=0; i<27; i++){
        check[0]=i+96;
        for (int x=0; x<guessletters_long; x++){
            if (letters_guessed[x]==check[0]){
                add=0;
            }
        }
        if(add==1){
            available_letters[count]=i+96;
            count++;
        }
        add=1;
    }
    available_letters[count]='\0';
}

void hangman(const char secret[]){  
    char letters_guessed[]="                              ";
    char available_letters[]="abcdefghijklmnopqrstuvwxyz";
    int secret_long=strlen(secret);
    char guessed_word[9];
    char show_word[25];
    int chance=8;
    int position=0;
    char guess[]="         ";
    int good_guess=0;
    int bad_guess=0;
    int guess_long;
    int add=0;

    printf("Welcome to the game, Hangman!\n");
    printf("I am thinking of a word that is %d letters long.\n", secret_long);

    //loop
    while (chance>0 && is_word_guessed(secret, letters_guessed)==0){
        printf("-------------\n");
        printf("You have %d guesses left.\n", chance);
        
        printf("Available letters: %s\n", available_letters);
        printf("Please guess a letter: ");
        
        scanf("%s", guess);
        guess_long=strlen(guess);
        if (strlen(guess)==1){
            if (guess[0]<'a' || guess[0]>'z'){
                if (guess[0]>'A'-1 && guess[0]<'Z'+1){
                    guess[0]=guess[0]+32;
                }else{
                    printf("Oops! '%s' is not a valid letter: ", guess);
                    get_guessed_word(secret, letters_guessed, guessed_word);
                    for (int i=0; i<secret_long*2; i=i+2){
                        show_word[i]=guessed_word[add];
                        if(secret_long*2-2!=i){
                            show_word[i+1]=' ';
                        }
                        add++;
                    }
                    add=0;
                    printf("%s\n", show_word);
                    continue;
                }
                
            }
            add=0;
        }else{
            strcpy(letters_guessed, guess);
            chance=0;
            guess_long=strlen(guess);
            break;
        }
        //letter message
        for (int i=0; i<strlen(letters_guessed); i++){
            if (letters_guessed[i]==guess[0]){
                bad_guess=-1;
            }
        }
        for (int i=0; i<secret_long; i++){
            if (guess[0]==secret[i] && bad_guess!=-1){
                bad_guess=1;
            }
        }
        if (bad_guess==1){
            printf("Good guess: ");
            letters_guessed[position]=guess[0];
            position++;
        }else if (bad_guess==-1){
            printf("Oops! You've already guessed that letter: ");
            good_guess++;
        }else{
            printf("Oops! That letter is not in my word: ");
            letters_guessed[position]=guess[0];
            position++;
        }
        bad_guess=0;

        for (int i=0; i<secret_long; i++){
            if (guess[0]==secret[i]){
                good_guess=1;
            }
        }
        // show word
        get_guessed_word(secret, letters_guessed, guessed_word);
        for (int i=0; i<secret_long*2; i=i+2){
            show_word[i]=guessed_word[add];
            if(secret_long*2-2!=i){
                show_word[i+1]=' ';
            }
            add++;
        }
        add=0;
        printf("%s\n", show_word);

        if (good_guess==0){
            chance--;
        }
        good_guess=0;
        get_available_letters(letters_guessed, available_letters);
    }

    // end
    if (guess_long>1){
        for (int i=0; i<secret_long; i++){
            if (secret[i]!=guess[i] || secret_long!=guess_long){
                good_guess=1;
            }
        }
        if (good_guess==0){
            printf("Congratulations, you won!\n");
        }else{
            printf("-------------\n");
            printf("Sorry, bad guess. The %s was goal..\n", secret);
        }
        
    }else{
        printf("-------------\n");
        if (is_word_guessed(secret, letters_guessed)==1){
            printf("Congratulations, you won!\n");
        }else{
            printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
        }
    }
}
