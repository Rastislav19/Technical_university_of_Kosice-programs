#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
    
    float lift_a_car(const int stick_lenght, const int human_weight, const int car_weight);

    float unit_price(const float pack_price, const int rolls_count, const int pieces_count);

    int collatz(const int number);

    int opposite_number(const int n, const int number);

    void counter(const int input_array[], const int array_size, int result_array[2]);     

    unsigned long sum_squared(const int line); 

    int array_min(const int input_array[], const int array_size);

    int array_max(const int input_array[], const int array_size);

    unsigned long special_counter(const int input_array[], const int array_size);

    int special_numbers(const int input_array[], const int array_size, int result_array[]);

    return 0;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

float lift_a_car(const int stick_lenght, const int human_weight, const int car_weight){
    
    float where= (float)stick_lenght * (float)human_weight / ( (float)car_weight + (float)human_weight );
    where= round (where*100)/100;

    return (float)where;
}

float unit_price(const float pack_price, const int rolls_count, const int pieces_count){
    
    float unit_price= ( pack_price / ( (float)rolls_count * (float)pieces_count ) * 100 );
    
    unit_price= round (unit_price * 100)/100;

    return unit_price;
}

int collatz(const int number){
    
    int new_number= number;
    int idx=1;

    while (new_number != 1){
        if(new_number%2 == 0){
            new_number=new_number/2;
        }
        else{
            new_number= 3*new_number+1;
        }
        idx=idx+1;
    }

    return idx;
}

int opposite_number(const int n, const int number){
    
    int opposite_number;

    if(number<(n/2)){
        opposite_number = (n/2) + number;
    }    
    else{
        opposite_number = number - (n/2);
    }

    return opposite_number;
}

void counter(const int input_array[], const int array_size, int result_array[2]){
     
    if(array_size%2 == 0){ 
        for ( int idx = 0; idx < array_size; idx=idx+2){
            result_array[0]=input_array[idx]+ result_array[0];
        }
        for (int i = 1; i < array_size ; i=i+2){
            result_array[1]= result_array[1]+ input_array[i];
        }
    }
    else{
        for ( int idx = 0; idx <= array_size; idx=idx+2){
            result_array[0]=input_array[idx]+ result_array[0];
        }
        for (int i = 1; i <= array_size-1; i=i+2){
            result_array[1]= result_array[1]+ input_array[i];
        }
    }
}

unsigned long sum_squared(const int line){
    
    unsigned long sum=0;
    unsigned long number=1;

    if ( line%2 == 0 ){
        for ( int i = 1; i <= (line/2); i++){

            number = number *(unsigned long)(line - i + 1) / (unsigned long) i ;
            if (i != ( line/2 ) ){
                sum= sum +(unsigned long)(number*number)*2;   
            }
            else{
                sum= (unsigned long) 2 + sum + (unsigned long)(number*number);

            number = number *(unsigned long) (line - i + 1) / (unsigned long)i ;
            if (i != ( line/2 ) ){
                sum= sum + (unsigned long)(number*number)*2;   
            }
            else{
                sum= 2 + sum + (unsigned long)(number*number);

            }
        }
    }
    }   else if ( line == 1){
            sum=2;
    }
    else if (line == 0){
        sum=1;
    }
    else if (line == 2){
        sum =6;
    }    
    else{ 
        for ( int i = 1; i <= ( ( (line-1)/2) ); i++){

            number= number *(unsigned long) ( line - i + 1) / (unsigned long) i;
            if( i != ( (line-1)/2) ){
                sum= sum +(unsigned long)(number*number)*(unsigned long)2;    
            }
            else{
                sum= (unsigned long)2 + sum +(unsigned long)(number*number)*2;

            number= number * (unsigned long)( line - i + 1) / (unsigned long)i;
            if( i != ( (line-1)/2) ){
                sum= sum +(unsigned long)(number*number)*2;    
            }
            else{
                sum= 2 + sum +(unsigned long)(number*number)*2;

            }
        }
    }    
    return sum;
}


int array_min(const int input_array[], const int array_size){
     
    int data[array_size-1];
    if (input_array == NULL){
        return -1;
    }    
    else{    
        for (int idx=0; idx < array_size; idx++){
            data[idx]=input_array[idx];
        }
        for(int idx=0; idx < array_size; idx++){
            for(int i = 0; i < array_size; i++){
                if( data[i] > data[i+1] ){
                    int swap=data[i];
                    data[i]=data[i+1];
                    data[i+1]=swap;
                }
            }
        }
    }
    return data[0];
}

int array_max(const int input_array[], const int array_size){
    
    int data[array_size-1];
    if(input_array == NULL){
        return -1; 
    }
    else{
        for ( int idx = 0; idx < array_size; idx++){
            data[idx]=input_array[idx];
        }
        for (int idx= 0; idx < array_size; idx ++){
            for(int i=0; i < array_size -1; i++){
                if(data[i] < data[i+1]){
                    int swap=data[i];
                    data[i]=data[i+1];
                    data[i+1]=swap;
                } 
            }
        }
    }
    return data[0];
}

unsigned long special_counter(const int input_array[], const int array_size){
 
    unsigned long sum1=0;
    unsigned long sum2=0;
    
    for ( int  idx = 0; idx < array_size;){
        sum1=sum1 + (unsigned long)input_array[idx];
        idx=idx+2;
        
    }
    int idx=1;
    sum2= input_array[idx]*input_array[idx];
    
    for (int  idx=3; idx < array_size ;){
        sum2= sum2+ ((unsigned long)input_array[idx]*(unsigned long)input_array[idx]);

        idx=idx+2;
    }
    unsigned long sum= sum1+sum2;
    return sum;
}

int special_numbers(const int input_array[], const int array_size, int result_array[]){
    
    int together=0;
    int x = 0;
    
    for( int idx = 0; idx < array_size -1; idx++ ){
        for( int i = idx + 1; i <= array_size -1; i++){
            together = together + input_array[i];
        }
        if (input_array[idx] > together ){
            result_array[x] = input_array[idx];
            x++;
        }
        together = 0;
    }
    result_array[x]= input_array[array_size -1];
    x++;

    return x;
}   









































