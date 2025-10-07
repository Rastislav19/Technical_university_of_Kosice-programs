#include <superkarel.h>
void find_east_south();
void turn_back();
void puttin_beepers();
void turn_right();
void go_and_put();
void go_y_center();
void go_x_center();
void go_back();

int main(){
    turn_on("task_5.kw");
    set_step_delay(100);

    find_east_south();
    puttin_beepers();
    go_y_center();
    turn_right();
    go_x_center();
    turn_left();

    turn_off();
    return 0;
}

void find_east_south(){
    while ( not_facing_east() ){
        turn_left();
    }
    while ( front_is_clear() ){
        step();
    }
    while ( not_facing_south() ){
        turn_left();
    }
    while ( front_is_clear() ){
        step();
    }
    turn_back();
}

void puttin_beepers(){
    go_and_put();
    while ( not_facing_north() ){
        go_and_put();
    }
}

void go_and_put(){
    while ( front_is_clear() ){
        step();
        put_beeper();
    }
    turn_left();
}

void go_y_center(){
     step();
     step();
     if( front_is_clear() ){
        go_y_center();
    }
    while( not_facing_south() ){
        turn_left();
    }
    go_back();
}    

void go_x_center(){
    step();
    step();
    if( front_is_clear() ){
        go_x_center();
    }
    while( not_facing_east() ){
        turn_left();
    }
    go_back();
}

void go_back(){
     step();    
}

void turn_back(){
    turn_left();
    turn_left();
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}
