/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   :Harsh Patel
	ID     :146315205
	Email  :hpatel262@myseneca.ca
	Section:IPC144NJJ
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include<stdio.h>
#include "w6p1.h"
// User Libraries


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intA)
{
	int num ;

	if (intA != NULL)
	{
		do
		{
			scanf("%d", intA);
			if (*intA < 1)
			{
				printf("ERROR: Enter a positive value: ");
			}
		} while (*intA < 1);

		return *intA;
	}
	else
	{
		do
		{
			scanf("%d", &num);
			if (num < 1)
			{
				printf("ERROR: Enter a positive value: ");
			}
		} while (num < 1);

		return num;
	}
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* dbA)
{
	double num;

	if (dbA != NULL)
	{

		do
		{
			scanf("%lf", dbA);
			if (*dbA < 1)
			{
				printf("ERROR: Enter a positive value: ");
			}
		} while (*dbA < 1);
		return *dbA;
	}
	else
	{
		do
		{
			scanf("%lf", &num);
			if (num < 1)
			{
				printf("ERROR: Enter a positive value: ");
			}
		} while (num < 1);
		return num;
	}
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProducts)
{
	
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", numProducts);
	printf("NOTE: A 'serving' is %dg\n", SUGGESTED_GRAMS);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int numProducts_user)
{
	struct CatFoodInfo CatFoodInfo = { 0 };
	printf("\nCat Food Product #%d\n", numProducts_user);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&CatFoodInfo.skuNumber);
	printf("PRICE         : $");
	getDoublePositive(&CatFoodInfo.price);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&CatFoodInfo.productWeight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&CatFoodInfo.caloriesPerServing);

	return CatFoodInfo;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuNumber, const int caloriesPerServing,const double* price, const double* productWeight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", skuNumber, *price, *productWeight, caloriesPerServing);
}

// 7. Logic entry point
void start(void)
{
	int i;
	struct CatFoodInfo CatFood[MAX_PRODUCTS] = { { 0 } };

	openingMessage(MAX_PRODUCTS);

	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		CatFood[i] = getCatFoodInfo(i + 1);
	}

	printf("\n");
	displayCatFoodHeader();

	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayCatFoodData(CatFood[i].skuNumber, CatFood[i].caloriesPerServing, &CatFood[i].price, &CatFood[i].productWeight);
	}
}