#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "hof.h"
#include "k.h"
#include "ui.h"

int main(){
    
    struct game game = {
        .score=0,
        .board={
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '}
        }
    };
    
    add_random_tile(&game);

    printf("is won: %d\n", is_game_won(game));
    printf("is move possible: %d\n", is_move_possible(game));
    printf("update: %d\n", update(&game, 0, -1));

    struct player list[10];
    int size = load(list);

    printf("\nREAD: %d\n", load(list));
    
    struct player player = {
        .name = "john",
        .score = 400
    };

    printf("\nADD player: %d\n", add_player(list, &size, player));
    printf("\nWRITE: %d\n", save(list, size));

    return 0;
}

