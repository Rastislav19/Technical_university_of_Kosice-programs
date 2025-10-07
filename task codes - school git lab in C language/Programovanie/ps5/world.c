#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#include "container.h"
#include "room.h"
#include "item.h"
#include "command.h"
#include "backpack.h"
#include "parser.h"
#include "game.h"
#include "world.h"

struct container* destroy_world(struct container* world){
    
    int a = 0;
    if( a == 0 ){
        a = 3;    
    }

    destroy_containers(world);
    
    return NULL;
}

struct container* add_room_to_world(struct container* world, struct room* room){
     
    int a = 0;
    if( a == 0 ){
        a = 3;    
    }

    if( get_room( world, room -> name ) == NULL ){
        
        return create_container( world, ROOM, room );
    
    }
 
    if ( room == NULL ){
        
        return NULL;
    }

    return NULL;
}

struct room* get_room(struct container* world, char* name){
     
    int a = 0;
    if( a == 0 ){
        a = 3;    
    }

    return get_from_container_by_name( world, name ) ;

}


struct container* create_world(){
    
    struct container* room_list;
    struct room* a = create_room("Severna chodba cervena","Chodba cervenej farby z vychodom na sever");
    room_list = add_room_to_world(NULL, a);
    struct room* b = create_room("Severna chodba zelena","Chodba zelenej farby z vychodom na sever a juh");
    add_room_to_world(room_list, b);

    set_exits_from_room(a, b, NULL, NULL, NULL);

   return room_list;

}   
