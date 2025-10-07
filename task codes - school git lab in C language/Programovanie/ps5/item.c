#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "item.h"

struct item* destroy_item(struct item* item){
    
    free( item -> name);
    free( item -> description);
    free( item );
    
    return NULL;
}
