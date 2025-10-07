#include <superkarel.h>
void go();
void picking();

int main(){
    turn_on("task_6.kw");

    go();
    while(1){
        picking();
    }
  
    turn_off();
    return 0;
}

void picking(){
    if ( beepers_present() ){
        pick_beeper();
        if ( no_beepers_present() ){
            while ( not_facing_north() ){
                turn_left();
            }     
        }
        else{
            pick_beeper();
            if ( no_beepers_present() ){
                while ( not_facing_west() ){
                    turn_left();
                }
            }
            else{
                pick_beeper();
                if ( no_beepers_present() ){
                    while( not_facing_south() ){
                        turn_left();
                    }
                }
                else{
                    pick_beeper();
                    if ( no_beepers_present() ){
                        while ( not_facing_east() ){
                            turn_left();
                        }
                    }
                    else{
                        pick_beeper();
                        turn_off();
                    }
                }
            }
        }
    }
    go();
}
void go(){
    while ( no_beepers_present() ){
        step();    
    }
}
