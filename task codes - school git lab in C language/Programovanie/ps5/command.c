#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "command.h"

struct command* destroy_command(struct command* command){
    
    free( command -> name );
    free( command -> description );
    free( command );
    
    return NULL;
}
