#include "superkarel.h"
void movement();
bool beepers_present_up();
void turn_right();
void turn_back();
void return_home();

int main(){
        turn_on("task_3.kw");
    set_step_delay(100);
    
    while( not_facing_east() ){
        turn_left();
    }
    while( right_is_clear() ){
        movement();
    }
    if(front_is_clear() ){
        movement();
        turn_left();
    }
    return_home();

    turn_off();
    return 0;
}

void movement(){
    while (front_is_clear() ){
        if ( beepers_present() ){
            pick_beeper();
        }
        step();
        if ( beepers_present() ){
            pick_beeper();
        }
    }
    turn_back();
    while ( front_is_clear() ){
        if ( right_is_blocked() ||  beepers_present_up() ){
            if( beepers_in_bag() ){
                put_beeper();
            }
            step();
        }
        else{
            step();
        }
    }
    turn_left();
    if(front_is_clear() ){
    step();
    turn_left();
    }
}

bool beepers_present_up(){
    if(beepers_in_bag()){
        if ( right_is_clear() ){
            turn_right();
            step();
            if ( beepers_present() ){
                turn_back();
                step();
                turn_right();
                return true;
            }
            else{
                turn_back();
                step();
                turn_right();
                return false;
            } 
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

void return_home(){
    while( front_is_clear() && no_beepers_present() ){
        step();          
    }
    turn_left();
    step();
    turn_left();
    while (no_beepers_present() ){
            if (front_is_clear() ){
                step();
                }
            else{ 
                if( facing_west() ){ 
                    turn_right();
                    step();
                    turn_right();
                }
                else{
                    turn_left();
                    step();
                    turn_left();
                }
            }
    }
    if (beepers_present() ){
        while ( front_is_clear() ){
            while( not_facing_north() ){
                turn_left();
            }
            step();
        }
        turn_left();
        while ( front_is_clear() ){
             step();
        }
        turn_back();
        turn_off(); 
        }
 }


void turn_back(){
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(100);
}

void turn_right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    turn_left();
    set_step_delay(100);
}
