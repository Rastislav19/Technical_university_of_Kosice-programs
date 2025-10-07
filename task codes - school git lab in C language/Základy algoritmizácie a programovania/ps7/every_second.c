#include <stdio.h>

int main(int argc, char* argv[]){
        
    FILE *fp = fopen(argv[1], "r");
    FILE *op = fopen(argv[2], "w");         
    
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
        input[idx]=ch;
        ch=fgetc(fp);
    } 

    fclose(fp);       
    fp=fopen(argv[1], "r");
    
    ch=fgetc(fp);
    for(int i=0; i < size; i++ ){
        if(input[i] == 'S' && input[i+1] == 'T'  && input[i+2] == 'A'  && input[i+3] == 'R'  && input[i+4] == 'T'){
            i=i+6;
            if(input[i] == 'S' && input[i+1] == 'T' && input[i+2] == 'O' && input[i+3] == 'P'){ 
                fclose(op);
                fclose(fp);
                return 0;
            } 
            else{
                while(1){
                    if(input[i] == ' ' ){        
                        break; 
                    }
                    i++; 
                }
                i++; 
                if( input[i] == 'S' && input[i+1] == 'T' && input[i+2] == 'O' && input[i+3] == 'P'){ 
                    fclose(op);
                    fclose(fp);
                    return 0;
                }
                else{
                    while(1){
                        if(input[i] == ' '){
                            break;
                        }    
                        fputc(input[i], op);    
                        i++;
                    }
                }
            }
            for( i=i+1; i < size; i++){ 
                if(input[i] == 'S' && input[i+1] == 'T' && input[i+2] == 'O' && input[i+3] == 'P'){ 
                    fclose(op);
                    fclose(fp);
                    return 0;
                } 
                else{
                    while(1){
                        if(input[i] == ' ' ){           
                            break; 
                        }
                        i++; 
                    }
                    i++; 
                    if( input[i] == 'S' && input[i+1] == 'T' && input[i+2] == 'O' && input[i+3] == 'P'){ 
                        fclose(op);
                        fclose(fp);
                        return 0;
                    }
                    else{
                        fputc(' ', op);
                        while(1){
                          if(input[i] == ' '){
                                break;
                            }    
                            fputc(input[i], op);    
                            i++;
                        }
                    }
                }
            }          
        }     
    } 
    fclose(fp);
    fclose(op);  
    return 0;

}

