/*
	==================================================
	Workshop #2 (Part-1):
	==================================================
	Name   : HARSH PATEL
	ID     : 146315205
	Email  : hpatel262@myseneca.ca
	Section: ipc144 NJJ
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{    
	double a;
	int b, d, f;
	float c, e, g;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &a);
	b = a / 2;
	c = a - b * 2;
	d = c / 1;
	e = c - d * 1;
	f = e / 0.25;
	g = e - f * 0.25;
	printf("\n$2.00 Toonies  X %d (remaining: $%0.2f)\n", b,c );
	printf("$1.00 Loonies  X %d (remaining: $%0.2f)\n", d,e );
	printf("$0.25 Quarters X %d (remaining: $%0.2f)\n", f,g );
	printf("\nMachine error! Thank you for letting me keep $%0.2f!\n", g);
	return 0;

}

