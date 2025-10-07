#include<stdio.h>
#include<math.h>

float racer(float field[][2]){
	long double a = 0, konst = 0;
    long double s = (long double)field[0][1]; 
	int count = field[0][0], min = field[1][1];
    int smeriteracie = 0;
	for(int idx = 1; idx < (count + 1); idx++){
		if(min > field[idx][1]){ 
            min = field[idx][1];
	    }
    }
	if(min <= 0){
		konst = (long double)(fabs(min));
		smeriteracie = 1;
	}
	else{
		for(int idx = 1; idx < (count + 1); idx++){
            a += field[idx][0] / (field[idx][1]);
		}
		if(a < s){
            smeriteracie = 0;
		}
        else if(a > s){ 
            smeriteracie = 1;
		}
        else{ 
            return 0;
	    }
    }
    long double c = 10, next = 0.000001; 
    int tst= 0;
    long double b_last_one = 0;
    while(c > 0.0000001){
		//smeriteracie = 0;
		a = 0;
		for(int idx = 1; idx < (count + 1); idx++){
			a += field[idx][0] / (field[idx][1] + konst);
		}
		//printf("\n smer iteracie %f", a);
		c = fabs(a - s);
		if(tst == 0){
			b_last_one = c; 
            tst = 1;
		}
        else{
			if(b_last_one < c){
				if(smeriteracie == 1){
					konst = konst - (2 * next);
					next = next / 10;
					//printf("\nkrok spat%.25f", krok);
					tst = 0;
				}
				else{
					konst = konst + (2 * next);
					next = next / 10;
					//printf("\nkrok spat%.25f", krok);
					tst = 0;
				}
			}
            else{
				if(smeriteracie == 1){
                    konst += next;
				}
                else{ 
                    konst -= next;
                    b_last_one = c;
                }
            }
		}
		//printf("%.24Lg    %.24Lg   %.24Lg\n", c, k, krok);
		long double how_many = 0;
        if(c > 0.1){
			if(smeriteracie == 1){
                how_many++;
		    }
        }
	}
	return (float)konst;
}

int main(){
	int n = 0, t = 0;
	scanf("%d %d", &n, &t);
	float field[n][2];
    field[0][0] = (float)n;
	field[0][1] = (float)t;
    for (int idx = 1; idx <= n; idx++) {
		scanf("%f %f", &field[idx][0], &field[idx][1]);
	} 

	printf("%.8f\n", racer(field));
    
    return 0;
}
