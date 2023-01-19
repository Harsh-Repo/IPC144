/*
	==================================================
	Workshop #2 (Part-2):
	==================================================
	Name   :
	ID     :
	Email  :
	Section:
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	double a, tax;
	int b, d, f, h, j, l;

	float x;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &a);
	tax = 0.05 * a;
	printf("Service fee (5.0 percent): %0.2lf\n", tax);
	x = a - tax;
	printf("Balance to despense: $%0.2lf", x);

	b = x / 2;
	printf("\n\n$2.00 Toonies  X %d (remaining: $%0.2f)\n", b, (float)x - b * 2);
	float c = (float)x - b * 2;
	d = c / 1;
	printf("$1.00 Loonies  X %d (remaining: $%0.2f)\n", d, (float)c - d * 1);
	float e = (float)c - d * 1;
	f = e / 0.25;
	printf("$0.25 Quarters X %d (remaining: $%0.2f)\n", f, (float)e - f * 0.25);
	float g = (float)e - f * 0.25;
	h = g / 0.10;
	printf("$0.10 Dimes    X %d (remaining: $%0.2f)\n", h, (float)g - h * 0.10);
	float i = (float)g - h * 0.10;
	j = i / 0.05;
	printf("$0.05 Nickels  X %d (remaining: $%0.2f)\n", j, (float)i - j * 0.05);
	float k = (float)i - j * 0.05;
	l = k / 0.01;
	float m = (float)k - l * 0.01;
	printf("$0.01 Pennies  X %d (remaining: $%0.2f)\n", l, (float)k - l * 0.01);
	

	printf("\nAll coins dispensed!\n");
	
	

	return 0;

}

