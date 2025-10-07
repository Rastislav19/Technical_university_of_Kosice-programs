#include <stdio.h>

int main (int argc, char* argv[]){
    
    FILE *fp = fopen(argv[1], "r");
    
    char ch= fgetc(fp);
    int size=-1;

    while( ch != EOF){
        size++;
        ch= fgetc(fp);
    }      
    char input[size];
    for(int idx=0; idx < size; idx++){
        input[idx]= ' ';    
    }
     
    fclose(fp);
    fp=fopen(argv[1], "r");

    ch=fgetc(fp); 
    for(int idx=0; idx < size; idx++){ 
        if( (int)ch < 90 && (int)ch >65){
            ch = ch+32;    
        }
        input[idx]= (char)ch;
        ch=fgetc(fp);
    } 

    fclose(fp);        
     
    char ananas[]="ananas";
    int how_many=0;
    int i=0;
    for(int idx=0; idx < size; idx++){
        if(input[idx] == ananas[i] && input[idx+1] == ananas[i+1] && input[idx+2] == ananas[i+2] && 
           input[idx+3] == ananas[i+3] && input[idx+4] == ananas[i+4] && input[idx+5] == ananas[i+5]){
            how_many++;                           
        }
    }             

    fp=fopen(argv[1],"w");
    ch= fgetc(fp);
    while(ch != EOF){
        fputc(' ', fp); 
        ch=fgetc(fp);
    }
    
    printf("%d", how_many);
    if(how_many < 10){
        how_many= how_many + 48;
        fputc(how_many,fp);
    }
    
    else if(how_many < 20) {
        how_many= how_many-10;
        how_many= how_many+48 ;
        fputc(49,fp);
        fputc(how_many, fp);
    }
    else{
        how_many= how_many-20;
        how_many= how_many+48;
        fputc(50,fp);
        fputc(how_many, fp);
    }
    
    return 0;
}


