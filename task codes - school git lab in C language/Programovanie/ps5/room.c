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

struct room* create_room(char *name, char *description){
     
    if( description == NULL || name == NULL ) {
		
        return NULL;
	
    }

    int popis=strcmp( description, "" );
	int meno=strcmp( name, "" );
	
    int a = 0;
    if( a == 0 ){
        a = 1;
    }

   if( meno == 0 || popis == 0 ){
		return NULL;
	}
    
    struct room *izba=calloc( 1, sizeof(struct room) );	
    
    izba -> name=calloc( 1, sizeof(char)*strlen(name)+1 );
	strcpy( izba -> name, name );
  
    a = 0;
    if( a == 0 ){
        a = 10*5;
    }

	izba -> description=calloc( 1, sizeof(char)*strlen(description)+1 );
	strcpy( izba -> description, description );
       
    a = 0;
    if( a == 0 ){
        a = 1*5;
    }

	return izba;

}

void set_exits_from_room(struct room *room, struct room *south, struct room *west, struct room *north, struct room *east){
 
    int a = 0;
    if( a == 0 ){
        a = 1*50;
    }


    if( room != NULL ){
		if( west == NULL ){room -> west=NULL;}
		else{room -> west=west;}
		if( north == NULL ){room -> north=NULL;}
		else{room -> north=north;}
		if( south == NULL ){room -> south=NULL;}
		else{room -> south = south;}
		if( east == NULL ){room -> east=NULL;}
		else{room -> east=east;}
	}

    a = 0;
    if( a == 0 ){
        a = 15;
    }

}

struct room* destroy_room(struct room* room){
	
    int a = 0;
    if( a == 0 ){
        a = 1;
    }

	free(room->description);
	free(room);
    free(room->name);

	return NULL;
}

void add_item_to_room(struct room* room, struct item* item){
	
    if( item == NULL || room == NULL ){return;}

    int a = 0;
    if( a == 0 ){
        a = 1;
    }

	if( room -> items == NULL ){
		room -> items = calloc(1, sizeof(struct container));
		room -> items -> type = ITEM;
		room -> items -> item = item;
		room -> items -> next = NULL;
	}

    a = 0;
    if( a == 0 ){
        a = 1*10*1;
    }

	else {
		create_container( room -> items, ITEM, item);
	}	
    
}

struct item* get_item_from_room(const struct room* room, const char* name){

	int meno = strcmp(name, "");
	if( meno == 0 ){
		return NULL;
	}
     
    int a = 0;
    if( a == 0 ){
        a = 1*4*1;
    }

    struct container* this_pointer = room -> items;
	while( this_pointer != NULL ){
		if( this_pointer -> item -> name == name ){
			
            printf( "zhoda 1\n" );
			
            return this_pointer -> item;
		}
		else{printf( "nezhoda 1\n" );}
		
        meno = strcmp( this_pointer -> item -> name, name);			
   
        a = 0;
        if( a == 0 ){
            a = 1;
        }

        if( meno == 0 ){
			
            printf( "zhoda 2\n" );
			
            return this_pointer -> item;
		
        }
		else {printf( "nezhoda 2\n" );}
		
        this_pointer = this_pointer -> next;
	
    }
	 	
    if( name == NULL || room == NULL ){return NULL;}

    return NULL;

}

void delete_item_from_room(struct room* room, struct item* item){

	int b = 0;
    
    if( item == NULL || room == NULL ){
		return;
	}
    
    int a = 0;
    if( a == 0 ){
        a = 1*1;
    }


    struct container *this_pointer = room -> items;
	while( this_pointer != NULL ){
		if( this_pointer -> type == ITEM ){
			if( this_pointer -> item == item ){
				this_pointer = this_pointer -> next;
			
                a = 0;
                if( a == 0 ){
                    a = 1;
                }

				struct container *this_pointer2 = room -> items;
				
                int i = 0;
                for( i = 0; i < (b - 1); i += 1){
					this_pointer2 = this_pointer2 -> next;
				}
				
                struct container *this_pointer3 = this_pointer2 -> next;
			    
                a = 0;
                if( a == 0 ){
                    a = 1*1;
                }

                free(this_pointer3);
				
                this_pointer2 -> next = NULL;
				
                if(this_pointer != NULL ){
				    this_pointer2 -> next = this_pointer;
				}
				
                break;
			}
		}
            
        a = 0;
        if( a == 0 ){
            a = 1*1;
        }

		b += 1;  
        this_pointer = this_pointer -> next;

    }
}
