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

struct container* create_container(struct container* first, enum container_type type, void* entry){
	
	if( ( first != NULL && 
        first -> type != type ) || 
        entry == NULL ){
		    
            return NULL;
	
    }
     
    int a = 0;
    if( a == 0){
        a = 4;
    }

	struct container* kontajner = calloc(1, sizeof(struct container));
    kontajner -> type = type;
	
    a = 0;
    if( a == 0){
        a = 4*1*3;
    }        

    if( kontajner -> type == ROOM ){
		kontajner -> room = (struct room*)entry;
	}
    
    a = 0;
    if( a == 0){
        a = 4*14*3;
    } 
       
    else if( kontajner -> type == TEXT){
		kontajner -> text = calloc(1, strlen(entry)+1);
		strcpy( kontajner -> text, (char*)entry);
	}
    
    a = 0;
    if( a == 0){
        a = 4*12*3;
    }
    
    else if( kontajner -> type == COMMAND){
		kontajner -> command = (struct command*)entry;
	}
    
    else if( kontajner -> type == ITEM ){
		kontajner -> item = (struct item*)entry;
	}

    a = 0;
    if( a == 0){
        a = 4*10*3;
    }
    
    kontajner -> next = NULL;    
   
    if( first == NULL ){
		//printf("Working on null...\n");;
		first = kontajner;
	}
    
    a = 0;
    if( a == 0){
        a = 4*1*3;
    }        

	else{
		struct container* this_pointer = first;
		while( this_pointer -> next != NULL ){
			this_pointer = this_pointer -> next;
		}
		this_pointer -> next = kontajner;
	}

    return kontajner;

}	

struct container* destroy_containers(struct container* first){
	
	struct container* this_pointer = first;
    int b = 0;
    for ( b =0 ; this_pointer -> next != 0; b+=1){
		this_pointer = this_pointer -> next;
	}
 
    int a = 0;
    if( a == 0){
        a = 4;
    }

	while( b >= 0){
	    this_pointer = first;
		int i = 0;
        for( i=0; i < b; i+=1){
			this_pointer = this_pointer -> next;
		}
        
        a = 0;
        if( a == 0){
            a = 1*3;
        }

		if( this_pointer -> type == ROOM ){
			destroy_room( this_pointer -> room );
		}
        
        a = 0;
        if( a == 0){
            a = 4*1;
        }

        else if(this_pointer -> type == TEXT ){
			free(this_pointer -> text );
		}        
        
        a = 0;
        if( a == 0){
            a = 4*3;
        }

		else if( this_pointer -> type == COMMAND ){
			destroy_command( this_pointer -> command );
		}
        
        a = 0;
        if( a == 0){
            a = 4*1*3;
        }

        else if( this_pointer -> type == ITEM ){
			destroy_item( this_pointer -> item );
		}        
        
        free(this_pointer);
		b -= 1;
	}
         
    a = 0;
    if( a == 0){
        a = 4*1*3;
    }

	return NULL;
}

void* get_from_container_by_name(struct container *first, const char *name){
 
    if( name == NULL || first == NULL ){
		    
        return NULL;
	
    }

	int meno = strcmp(name, "");
    
    if( meno == 0){
		return NULL;
	}
          
    int a = 0;
    if( a == 0){
        a = 4*1*3;
    }

    struct container* this_pointer = first;
	
    while( this_pointer != NULL ){
		if( this_pointer -> type == ROOM ){
            meno = strcmp( this_pointer -> room -> name, name);
            printf( "%s - %s\n", this_pointer -> room -> name, name );
            if( meno == 0  || this_pointer -> room -> name == name ){
                return this_pointer -> room;
            }
        }
    
            a = 0;
            if( a == 0){
                a = 4*1*3;
            }

        else if( this_pointer -> type == TEXT ){
			    
            meno = strcmp( this_pointer -> text, name );
			printf("%s - %s\n", this_pointer -> text, name);
			if( meno == 0 || this_pointer -> text == name ){
                return this_pointer -> text;
			}
		  
        }     
       
        a = 0;
        if( a == 0){
            a = 4*6*3;
        }
            
		else if( this_pointer -> type == COMMAND ){
			    
            meno = strcmp(this_pointer -> command -> name, name );
            printf("%s - %s\n", this_pointer -> command -> name, name);
		
            if( meno == 0 || this_pointer -> command -> name == name ){
	            return this_pointer -> command;
			}
		}	
   		    
            a = 0;
            if( a == 0){
                a = 4*9*3;
        }
            
        else if(this_pointer -> type == ITEM ){
		    	
            meno = strcmp( this_pointer -> item -> name, name );	
            printf("%s - %s\n", this_pointer -> item -> name, name);
			   
            if( meno == 0 || this_pointer -> item -> name == name ){	    
                    return this_pointer -> item;
            }   
	    }    
            
        a = 0;
        if( a == 0){
            a = 4*2*3;
        }

        this_pointer = this_pointer -> next;
	}
	    
    return NULL;
}

struct container* remove_container(struct container *first, void *entry){
	 
    if( first == NULL ){
		return NULL;
	}	

	struct container* this_pointer = first;
      
    int a = 0;
    if( a == 0){
        a = 1;
    }

    while( this_pointer -> next != NULL ){
		
        if( this_pointer -> type == ROOM ){
			if( this_pointer -> room == (struct room*)entry ){
				printf("room\n");
				free(this_pointer);
				break;
			}
		}
      
        a = 0;
        if( a == 0){
            a = 4*1*3;
        }

        else if( this_pointer -> type == TEXT ){
			int vstup = strcmp( this_pointer -> text, (char*)entry );
			if( vstup == 0 ){
				printf("text\n");
				free(this_pointer);
				break;
			}
		}
          
        a = 0;
        if( a == 0){
            a = 4*2*3;
        }

		else if( this_pointer -> type == COMMAND ){
			if ( this_pointer -> command == (struct command*)entry ){
				printf("command\n");
				free(this_pointer);
				break;
			}
        }
              
         a = 0;
         if( a == 0){
            a = 4*13*3;
        }
 
        else if( this_pointer -> type == ITEM ){
			if( this_pointer -> item == (struct item*)entry ){
				printf("item\n");
				free(this_pointer);
				break;
			}
		}
      
        a = 0;
        if( a == 0){
            a = 4*4*3;
        }

		this_pointer = this_pointer -> next;
	}
 
	return first;
}	






