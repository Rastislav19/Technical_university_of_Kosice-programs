#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "container.h"
#include "room.h"
#include "item.h"
#include "command.h"
#include "backpack.h"
#include "parser.h"
#include "game.h"
#include "world.h"

int main(){
    
    struct container* kontajner = create_container(NULL, 3, "E");
    struct container* kontajner2 = create_container(kontajner, 2, "F");
    printf("%s\n", kontajner2->text);
    remove_container(kontajner, "F");

    struct container* world = create_world();
    get_room(world, "owo");
    add_item_to_room(world->room, NULL);
    delete_item_from_room(world->room, NULL);
    get_item_from_room(world->room, "owo");
    destroy_world(world);

    return 0;
}
