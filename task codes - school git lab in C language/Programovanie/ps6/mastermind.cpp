#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <Arduino.h>

#include "lcd_wrapper.h"
#include "mastermind.h"

void turn_off_leds(){
    
    digitalWrite( 6, LOW);
    digitalWrite( 7, LOW);
    digitalWrite( 8, LOW);
    digitalWrite( 9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
   
}

char* generate_code( bool repeat, int length ){
    
    if( length > 10 && repeat == false ){
        return NULL;
    }

    if( 1 > length ){ 
    
        return NULL;
    
    }
     
    char* generated_code = (char *) calloc( 1 + length, sizeof (char) );
    
    randomSeed(analogRead(A1));
    
    int i = 0; 
    for( i = 0; length > i; i++ ){
        
        generated_code[i] = random(10) + 48; 
        
        if(repeat == false){
            
            int j = 0;
            for( j = 0; i > j; j++){
                if( generated_code[i] == generated_code[j] ){
            
                    while(generated_code[i] == generated_code[j]){
                        
                        generated_code[i] = random(10) + 48;
                        
                    }
                    
                    j = 0; 
                   
                }    
            }
        } 
    }
    lcd_set_cursor(0,1);
    if(repeat == true){
      lcd_print("Numbers can repeat!!");
      delay(2000);
    }
    else{
      lcd_print("Numbers cant repeat!");  
      delay(2000);
    }
    lcd_clear();
    lcd_print(generated_code);
    delay(1000);
    
    return generated_code;

}

void get_score(const char* secret, const char* tip, int* peg_a, int* peg_b){
    
    int x = 0;
    while(strlen(secret) > x ){
     
      if(tip[x] == secret[x]){ 
        
        *peg_a = *peg_a + 1;
        
      }
      x++;
    }
   
    x = 0;
    while( strlen(secret) > x ){
        int y = 0;
        while( strlen(secret) > y){
          if( tip[y] == secret[x]) {
            
            *peg_b = *peg_b + 1;
                  
          }
          y++;
        } 
        x++;
    }
}

void render_leds(const int peg_a, const int peg_b){
    
    int x = 7;
     
    while( ((peg_a*2)+ 6) > x ) {

      digitalWrite(x, HIGH);

      x = x + 2;
    }
  
    int y = x+1;
    while( ( (peg_b*2) + x ) > y){
        digitalWrite( y, HIGH );
        y = y + 2;
    }
}

void render_history(char* secret, char** history, const int how_many ,int* copyed_guess){
    
    int length = strlen(secret);
    
    lcd_set_cursor(1,0);
    lcd_print("history:");
    
    lcd_set_cursor(13, 3);
    
    bool in_history = true;
    int kurzor = how_many-1;
    *copyed_guess = kurzor;

    while( true == in_history){
        
        lcd_set_cursor(1,1);
    
        if( 0 != kurzor){
        
            lcd_print( history[kurzor-1] );
    
        }
        else{
        
            lcd_print("      ");
        }

        lcd_set_cursor(1,2);
        lcd_print( history[kurzor] );
        lcd_print("<");
        lcd_set_cursor(1,3);
    
        if( (how_many-1) != kurzor){
        
            lcd_print( history[kurzor+1] );
    
        }
        else{
        
            lcd_print("      ");
    
        }
        
        int red_leds=0;
        int blue_leds=0;
        
        get_score(secret, history[kurzor], &red_leds, &blue_leds);
        
        render_leds(red_leds, blue_leds);
        
        //pohyb
        if( digitalRead(3) == HIGH && kurzor != how_many-1){
            kurzor++;
            turn_off_leds();
            delay(300);
        }
        if(digitalRead(2) == HIGH && kurzor != 0){
            kurzor--;
            turn_off_leds();
            delay(300);
        }
        if(digitalRead(A0) == 1){
          
          in_history = false;
          
        }
    }
  //return;
}

char* hadaj(char** history, int how_many, const int strlen_secret, const int copyed_guess){
   
    lcd_clear();
    lcd_set_cursor(0, 0);
    lcd_print_number(how_many + 1);
    lcd_print(". guess");
  
    bool hadanie = true;
    
    char *tip = (char *) calloc(strlen_secret+1, sizeof (char));
    
    if( how_many == 0 ) {
      for(int i = 0; strlen_secret > i; i++){ 
        
        tip[i] = '0';
    
      }
    }
    else{
        strcpy( tip, history[ copyed_guess]);
    }
    
    //hadanie
    while( hadanie == true ){
         
        //z lcd_wrapper
        print_tip(tip, strlen_secret);
        
        //pridavanie cisel
        if (digitalRead(5) == 1){
          if(tip[0] == '9'){
            tip[0] = '0';
          }
          else{
            tip[0] = tip[0]+ 1;
          }
          delay(300);  
        }
        if(digitalRead(4) == 1){
          if(tip[1] == '9'){
            tip[1] = '0';
          }
          else{
            tip[1] = tip[1]+ 1;    
          }
          delay(300);
        }
        if (digitalRead(2) == 1){
          if(tip[3] == '9'){
            tip[3] = '0';
          }
          else{
            tip[3] = tip[3]+ 1;  
          }
          delay(300);
        }
        if(digitalRead(3) == 1){
          if(tip[2] == '9'){
            tip[2] = '0';
          }
          else{
            tip[2] = tip[2]+1;
          }
          delay(300);
        }
        
        //enter
        if( digitalRead(A0) == 1 ){
      
            delay(1000);
      
            if( digitalRead(A0) == 1 ){ // ak drzis historia
        
                hadanie = false;
                free(tip);
                
                return NULL;
      
            }
            else{
                hadanie = false;
            }
        }
    }
    return tip;
}

void play_game(char* secret){

    //iniciacia premennych
    int red_leds = 0; 
    int blue_leds = 0;
    int strlen_secret = strlen(secret);
    int how_many = 0;
    int copyed_guess = 0;
    
    char **history = (char **) calloc(10, sizeof (char*));
    
    while( strlen_secret != red_leds && ( (strlen_secret*2) + 2 ) > how_many ){
    
        turn_off_leds();

        //zacni s hadanim a vytvor tak historiu
        history[ how_many ] = hadaj( history, how_many, strlen_secret, copyed_guess);

        lcd_clear();
        delay(200);
        
        //ak zada pokus
        if( NULL != history[ how_many ] ){
            
            red_leds = 0;
            blue_leds = 0;
            
            //vyhodnotit tip a zapnut ledky
            get_score( secret, history[ how_many ], &red_leds, &blue_leds);
            render_leds( red_leds, blue_leds);
            
            if( strlen(secret) != red_leds){
                
                turn_off_leds();
                lcd_clear();
                
                how_many++;
                
                render_history( secret, history, how_many, &copyed_guess);
            }
        
        // nahlad do historie
        }
        else if( how_many != 0 ){
             
            lcd_clear();
            delay(200);
            
            render_history(secret, history, how_many, &copyed_guess);
        
        }
        //prve hadanie = ziadna historia..
        else{
            
            lcd_clear();
            delay(200);
            
            lcd_set_cursor(1,1);
            lcd_print("ERROR: ");
            lcd_set_cursor(1,2);
            lcd_print("history is empty");
            
            delay(2000);
       
        }

        lcd_clear();
        delay(250);
    }
    
    // ukoncenie hry
    lcd_print_at(3, 1, "Secret number");
    lcd_set_cursor(5,2);
    lcd_print("was: ");
    
    lcd_print(secret); //vypisanie aky bol kod
    
    delay(2500);
    lcd_clear();
    delay(200);

    //vyhra alebo prehra 
    if( strlen(secret) == red_leds ){
       
        lcd_set_cursor(3,1);
        lcd_print("Amazing");
        
        lcd_set_cursor(5,2);
        lcd_print("U r winner!!!");
    }
    else{
         
        lcd_set_cursor(1,0);
        lcd_print("Shame....");
    
    } 
    
    delay(2500);
    turn_off_leds();
    lcd_clear();
    
    delay(200); 
    
    //free
    int i = 0;
    while( strlen(secret) > i ){ 
        
        free(history[i]);
        i++;
    }
    
    free(history);

}
