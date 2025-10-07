#include <superkarel.h>
void movement();
void search();
void turn_back();
void turn_right();
void go_front();
void follow();
void doors();

int main(){
    turn_on("task_7.kw");
    set_step_delay(200);    
    
    doors();
    turn_back();
    step();   
    while (1){
        follow();
    }

    turn_off();
    return 0;
}
void doors(){
    while(no_beepers_present() ){   
        if (front_is_clear() ){
            if (left_is_clear() ){
                turn_left();
                step();
                put_beeper();
                put_beeper();
                turn_back();
                step();
                turn_left();
                step();
            }
            else{
                step();
            }
        }
        else{   
            if (left_is_clear()){
                turn_left();
                step();
                put_beeper();
                put_beeper();
                turn_back();
                step();
                turn_left();
                if ( front_is_clear() ){
                step();
                }
                else{
                    put_beeper();
                }
            }
            else{
                put_beeper();
            }    
        }
    }        
}
void follow(){
    if ( left_is_blocked() ){
        go_front();
    }
    else{
        turn_left();
        step();
    }
}
void go_front(){
    if (front_is_clear() ){
        if ( no_beepers_present() ){
            step();
        }
        else{
            pick_beeper();
            step();
        }
    }
    else if (facing_south() && front_is_blocked() && left_is_blocked() && right_is_clear() && beepers_present() ){
        pick_beeper();
        while (not_facing_east() ){
            turn_left();
        }
        turn_off();
    }
    else{
        turn_right();
    }
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
