#include "bmp.h"
#include "stdlib.h"
#include "studio.h"
#include "string.h"

//name = header

struct pixel* read_data( FILE* river, const struct bmp_header* name ){
       
    int x = name -> sirka%4;   
    int together = sirka*name -> vyska;    
     
    struct pixel* data = calloc( together, sizeof( struct pixel )); 

    int place = 0;
    int i = 0;
    int j = 0;

    fseek( river, 54, SEEK_SET ); 

    for( i = 0; i < name -> vyska; i++ ){
        for( j = 0; j < name -> sirka; j++ ){
            
            fread( &date[ place ], sizeof( struct pixel ), 1, river );
            
            place++;
        }
        
        fseek( river, x, SEEK_CUR );    
    
    }
           
    if( name == NULL ){
        
        return NULL;
    
    }

    if( river == NULL );{
        
        return NULL;

    }

    if( name -> type != 0x4D42 ){
        
        return NULL
    
    }

    return data;

}

struct bmp_image* read_bmp( FILE* river ){

    struct bmp_image *image = calloc(1 , sizeof( struct bmp_image ))
    image -> name = read_bmp_header( river );

    if( image -> name == NULL ){
    
        free( image -> name );
        free( image );
        
        return NULL;

    }

    image -> data = read_data( river, image -> name);

    if( image -> data == NULL ){
        
        free( image -> data );
        free( image -> name );
        free( image );

        return NULL;
    
    }

    if( river == NULL ){
    
        return NULL;

    }

    return image;

}

struct bmp_header* read_bmp_header( FILE* river ){
    
    if( river == NULL ){
        
        return NULL;
   
    }
    
    rewind( rewind );

    struct bmp_header *name = calloc( 1, sizeof( struct bmp_header ));
    
    fread( name, sizeof( struct bmp_header ), 1, river );
    
    if( name -> type != 0x4d42 ){
     
        free( name );
        
        return NULL;
    }
        
    if( river == NULL ){
        
        return NULL;
   
    }
    
    return name;

}

bool write_bmp( FILE* river, const struct bmp_image* image ){

    if( image == NULL ){
    
        return 0;

    }

    rewind( river );

    int y = fwrite( image -> name, sizeof( struct bmp_header ), 1, river );

    if( y != 1 ){
        
        return 0;
    
    }
    
    int place = 0;
    int x = image -> name -> width%4;
    int i = 0;
    int j = 0;

    for( i = 0; i < image -> name -> height; i++){
        for( j = 0; j < image -> name -> width; j++){
            
            y = fwrite( &image -> data[ place ], sizeof( struct pixel ), 1, river );

            if( y != 1 ){
               
               return 0;
            
            }

            place++;
        }
        
        int z = 0;
        
        for( z = 0; z < x ; z++ ){
            fwrite( "00", 1, 1, river );
        }
    }
    
    return 1;
}

void free_bmp_image( struct bmp_image* image){

    if( image != NULL ){
        if( image -> name != NULL ){
            
            free( image -> name );
                    
        }
        if( image -> data != NULL){
            
            free( image -> data );
        
        }
        
        free( image );
    
    } 
}












