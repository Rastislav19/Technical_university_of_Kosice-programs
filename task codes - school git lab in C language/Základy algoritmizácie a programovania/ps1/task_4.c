#include "superkarel.h"
void go_up_and_down();
void fill_hole();
void turn_right();
void turn_back();

int main(){
    turn_on("task_4.kw");
    set_step_delay(200);
   
    go_up_and_down();
    
    turn_off();
    return 0;
}

void go_up_and_down(){
     while ( not_facing_north() ){
         turn_left();
     }
     while( front_is_clear()){
         if (beepers_present() ){
             fill_hole();    
         }
         step();
         if( beepers_present() ){
            fill_hole();
         }
     }
     turn_back();
     while ( front_is_clear() ){
         step();
     }
     turn_left();
     if ( front_is_blocked() ){ 
        turn_off();
     }
     else{
        step();
     }
     go_up_and_down();
}     
    

void fill_hole(){
    while ( not_facing_south() ){
        turn_left();
    }    
    while ( front_is_clear() ){
        step();
    }
    turn_back();
    if ( no_beepers_present() ){
        put_beeper();
    }
    while ( front_is_clear() ){
        step();
        if ( no_beepers_present() ){
            put_beeper();
        }
    }
    go_up_and_down();
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

void turn_back(){
    turn_left();
    turn_left();
}


