#include "transformations.h"
#include "bmp.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main( int argc, char const *argv[] ){

    FILE *river=NULL;
    river=fopen( argv[1], "rb" );
    
    FILE *exit=fopen( "img.bmp", "wb" );
    FILE *exit2=fopen( "img2.bmp", "wb" );
    FILE *exit3=fopen( "img3.bmp", "wb");
    struct bmp_image *watch_img=read_bmp( river );
    write_bmp( exit, watch_img );
    struct bmp_image *right_img=rotate_right( watch_img );
    struct bmp_image *exit_img=extract( watch_img, "g" );
    write_bmp( exit2, right_img );
    write_bmp( exit, exit_img );
    struct bmp_image *horizontal_img=flip_horizontally( watch_img );
    struct bmp_image *smaller_img=crop( watch_img, 0, 1, 4, 3 );
    write_bmp( exit2, horizontal_img );
    write_bmp( exit2, smaller_img );
    struct bmp_image *diffrent_img=scale( watch_img, 1 );
    write_bmp( exit3, different_img );           
    free_bmp_image( different_img );
    free_bmp_image( smaller_img );
    free_bmp_image( horizontal_img );
    free_bmp_image( exit_img );
    free_bmp_image( right_img );
    free_bmp_image( watch_img );  
    if( river != NULL ){
        fclose(exit);
        fclose(exit2);
        fclose(exit3);
    }

    return 0;

}

