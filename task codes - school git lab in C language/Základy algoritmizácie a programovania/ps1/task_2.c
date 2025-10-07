#include "superkarel.h"
void movement();
void movement_back();
void turn_back();
void turn_right();

int main(){
    turn_on("task_2.kw");
    set_step_delay(200);
    
    while( no_beepers_present() ){
        movement();
    }
    pick_beeper();
    turn_back();
    while (1){
        if ( front_is_blocked() && right_is_blocked() && left_is_blocked() ){
            turn_off(); 
        }
        else{
            movement_back();
        }
    }    
    return 0;
}

void movement(){ 
    if  ( front_is_clear() ){
        step();
    }
    else {
        turn_left();
    }
}

void movement_back(){
    if ( front_is_clear() ){
        step();    
    }
    else {
        turn_right();
    }
}

void turn_back(){
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(200);
}

void turn_right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    turn_left();
    set_step_delay(200);
}
