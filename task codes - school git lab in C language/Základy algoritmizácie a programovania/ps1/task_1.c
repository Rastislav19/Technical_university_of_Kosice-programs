#include "superkarel.h"
void go_front();
void turn_right();
void movement();
void movement_back();

int main(){
    turn_on("task_1.kw");
    set_step_delay(300);
    
    put_beeper();
    if ( front_is_clear() ){
        step();
    }
    else{
        turn_left();
        step();
    }
    while ( no_beepers_present() ){
        movement();
    }
    pick_beeper();
    while ( no_beepers_present() ){   
        movement();
    }
    pick_beeper();
    while ( not_facing_west() ){
        turn_left();
    }
    turn_off();
    return 0;
}

void movement(){
    if ( right_is_blocked() ){
        go_front();
    }
    else{
        turn_right();
        step();
    }
}    

void go_front(){
   if ( front_is_clear() ){ 
        step();
   } 
   else{ 
        turn_left();
   }
}

void  turn_right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    turn_left();
    set_step_delay(300);
}


