#include <Wire.h>
#include <Arduino.h>

#include "mastermind.h"

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 4, 20);

#include "lcd_wrapper.h"


void lcd_init(){

    lcd.init();
    lcd.backlight();// vypne podsvietenie
 
    return;
}

void lcd_clear(){

    lcd.clear();
    
    return;
}


void lcd_set_cursor(int y, int x){
    
    lcd.setCursor(y, x);

    return;
}


void lcd_print(char* text){
    
    lcd.print(text);
   
    return;
}


void lcd_print_at(int y, int x, char* text){
    
    lcd_set_cursor(y, x);
    lcd_print(text);

    return;
}


//doplnene
void lcd_print_number(int text){
   
   lcd.print(text);

}

void print_tip(const char* tip, const int strlen_secret){
    
    int i = 0;
    for( i = 0; strlen_secret > i; i++){
        
        lcd.setCursor(i+i+1,2);
        lcd.print(tip[i]);
        lcd.setCursor(i+i+1,3);
        
        lcd.print(" ");
    }
}
