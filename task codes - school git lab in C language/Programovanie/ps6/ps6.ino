#include <Arduino.h>
#include "mastermind.h"
#include "lcd_wrapper.h"

int main(){
  
    //set up
    init(); 
   
    lcd_init();//akceptuje ledky 

    int repeat = random(0,1); 
  
    while(1){
        
        //uvodna obrazovka
        while( digitalRead(A0) == 0 ){

            lcd_set_cursor(6,1); //dopisal som
            lcd_print("THIIS IS");
            lcd_set_cursor(2,2);//dopisal som
            lcd_print("MASTERMIND GAAME");
            lcd_set_cursor(13,3);
            lcd_print( "by me..");
        }
        
        lcd_clear();
        delay(300);
        //ak stlaci enter zanina sa hra
        char* code = generate_code( repeat, 4);
        lcd_set_cursor(0,1);
        lcd_print("YOU HAVE 10 GUESSES. GOOD LUCK!!!"); 
        delay(3000);
        lcd_clear();
        play_game(code);
        
        lcd_clear();
        free(code);
        
        delay(4000);
    }
  
   return 0;
}
