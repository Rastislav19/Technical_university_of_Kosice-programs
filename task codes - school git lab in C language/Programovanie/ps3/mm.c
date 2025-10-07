#include <stdio.h>

int main(){
        
    int digit=0;
    int long sum=0;
    while( (digit=getchar()) != '\n'){
	    sum = sum+ digit - '0';
    }
    int remainder=0;
    int number= 0;
    while(sum >= 10){
        number = sum;
        sum=0;
        while(number != 0){
            remainder = number % 10;
            sum = sum + remainder;
            number = number / 10;             
            
        }   
    }
    printf("%ld\n", sum);
   
    return 0;  
}
