#include<stdio.h>
#include<math.h>

float racer(float field[][2]) {
	long double a = 0, c = 10, k = 0, krok = 0.000001, s = (long double)pole[0][1], predosle = 0, j = 0;
	int pocet = pole[0][0], minimum = pole[1][1], smeriteracie = 0, tst = 0;
	for (int i = 1; i < pocet + 1; i++) {
		if (minimum > pole[i][1]) minimum = pole[i][1];
	}
    if (minimum <= 0) {
		k = (long double)(fabs(minimum));
		smeriteracie = 1;
	}
	else {
		for (int xx = 1; xx < pocet + 1; xx++) {
			a += pole[xx][0] / (pole[xx][1]);
		}
		if (a < s) smeriteracie = 0;
		else if (a > s) smeriteracie = 1;
		else return 0;
	}
    while (c > 0.0000001)
	{
		//smeriteracie = 0;
		a = 0;
		for (int xx = 1; xx < pocet + 1; xx++) {
			a += pole[xx][0] / (pole[xx][1] + k);
		}
		//printf("\n smer iteracie %f", a);
		c = fabs(a - s);
		if (tst == 0) {
			predosle = c; tst = 1;
		}
        else {
			if (predosle < c) {
				if (smeriteracie == 1) {
					k = k - 2 * krok;
					krok = krok / 10;
					//printf("\nkrok spat%.25f", krok);
					tst = 0;
				}
				else {
					k = k + 2 * krok;
					krok = krok / 10;
					//printf("\nkrok spat%.25f", krok);
					tst = 0;
				}
			}
            else
			{
				if (smeriteracie == 1)k += krok;
				else k -= krok;
				predosle = c;
			}
		}
		//printf("%.24Lg     %.24Lg   %.24Lg\n", c, k, krok);
		if (c > 0.1) {
			if (smeriteracie == 1)j++;
		}
	}
	return (float)k;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	float pole[a][2];
	for (int i = 1; i <= a; i++) {
		scanf("%f %f", &pole[i][0], &pole[i][1]);
	}
	pole[0][0] = (float)a;
	pole[0][1] = (float)b;
	printf("%.8f", racer(pole));
}
