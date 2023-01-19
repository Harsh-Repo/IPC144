
/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   :Harsh Patel
	ID     :146315205
	Email  :hpatel262@myseneca.ca
	Section:IPC144NJJ
*/
// System Libraries
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// User Libraries
#include "w6p2.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intA)
{
	int num;

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
void displayCatFoodData(const int skuNumber, const int caloriesPerServing, const double* price, const double* productWeight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", skuNumber, *price, *productWeight, caloriesPerServing);
}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(double* lbs1, double* lbs_kg)
{

	double LBS;
	if (lbs_kg != NULL)
	{
		*lbs_kg = *lbs1 / pound_to_kg;
		return *lbs_kg;
	}
	else
	{
		LBS = *lbs1/ pound_to_kg;
		return LBS;
	}
}


// 9. convert lbs: g (call convertKG, then * 1000)

int convertLbsG(double *lbs, int* g)
{
	double G; // gram
	if (g != NULL)
	{
		*g = (*lbs / pound_to_kg) * 1000;
		return *g;
	}
	else
	{
		G = (*lbs / pound_to_kg) * 1000;
		return G;
	}
}

// 10. convert lbs: kg and g
void convertLbs(double* lbs, double* lbs_kg, int* g)
{
	*lbs_kg = convertLbsKg(lbs, lbs_kg);
	*g = convertLbsG(lbs, g);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int gPerServ, const int totalg, double* total_serving)
{
	double no_of_serving;
	if (total_serving != NULL)
	{
		*total_serving = (double)totalg / (double)gPerServ;
		return *total_serving;
	}
	else
	{
		no_of_serving =  (double)totalg / (double)gPerServ;
		return no_of_serving;
	}
}
// 12. calculate: cost per serving
double calculateCostPerServing(double* product_price, double* no_of_serving, double* cost_per_serving)
{
	double cost;
	if (cost_per_serving !=NULL)
	{
		*cost_per_serving = *product_price / *no_of_serving;
		return *cost_per_serving;
	}
	else
	{
		cost = *product_price / *no_of_serving;
		return cost;
	}
}
// 13. calculate: cost per calorie
double calculateCostPerCal(double* product_price, double* total_calories, double* cost_per_calorie)
{
	double calorie_cost;
	if (cost_per_calorie != NULL)
    {									//   1.52/325= costpercalorie

		*cost_per_calorie = *product_price / *total_calories;
		return *cost_per_calorie;
	}
	else
	{
		calorie_cost= *product_price / *total_calories;
		return calorie_cost;
	}
}



// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo CatFoodInfo)
{ 
	struct ReportData ReportData = { 0 };
	ReportData.sku = CatFoodInfo.skuNumber;
	ReportData.product_price = CatFoodInfo.price;
	ReportData.cal_per_sugg_serving =CatFoodInfo.caloriesPerServing;
	ReportData.weight_pound = CatFoodInfo.productWeight;
	ReportData.weight_kg = convertLbsKg(&ReportData.weight_pound, &ReportData.weight_kg);
	ReportData.weight_g = convertLbsG(&ReportData.weight_pound, &ReportData.weight_g);
	ReportData.total_serving = calculateServings(SUGGESTED_GRAMS, ReportData.weight_g, &ReportData.total_serving);
	ReportData.cost_per_serving = calculateCostPerServing(&ReportData.product_price, &ReportData.total_serving, &ReportData.cost_per_serving);
	double totalCalories = ReportData.cal_per_sugg_serving * ReportData.total_serving;
	ReportData.cost_cal_per_serving = calculateCostPerCal(&ReportData.product_price, &totalCalories, &ReportData.cost_cal_per_serving);

		return ReportData;
}


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg\n", SUGGESTED_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData ReportData, const int cheapest)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", ReportData.sku, ReportData.product_price,ReportData.weight_pound, ReportData.weight_kg, ReportData.weight_g,ReportData.cal_per_sugg_serving,ReportData.total_serving, ReportData.cost_per_serving, ReportData.cost_cal_per_serving);
	if (cheapest != 0)
	{
		printf(" ***");
	}

}
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestReportData)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", cheapestReportData.skuNumber, cheapestReportData.price);
	printf("Happy shopping!");
}


// ----------------------------------------------------------------------------

// 7. Logic entry point
	void start(void)
	{
		int i;
		int index = 0;
		int flag;
		struct CatFoodInfo CatFood[MAX_PRODUCTS] = { { 0 } };
		struct ReportData ReportData[MAX_PRODUCTS] = { {0} };

		openingMessage(MAX_PRODUCTS);

		for (i = 0; i < MAX_PRODUCTS; i++)
		{
			CatFood[i] = getCatFoodInfo(i + 1);
			ReportData[i] = calculateReportData(CatFood[i]);

		}
		double cheapest = ReportData[0].cost_per_serving;

		
		for (i = 0; i < MAX_PRODUCTS; i++)
		{
			if (cheapest >= ReportData[i].cost_per_serving)
			{
				cheapest = ReportData[i].cost_per_serving;
				index = i;
			}
		}

		printf("\n");
		displayCatFoodHeader();

		for (i = 0; i < MAX_PRODUCTS; i++)
		{
			displayCatFoodData(CatFood[i].skuNumber, CatFood[i].caloriesPerServing, &CatFood[i].price, &CatFood[i].productWeight);
		}

		printf("\n");
		displayReportHeader();
		
		for (i = 0; i < MAX_PRODUCTS; i++)
		{
			if (ReportData[i].cost_per_serving == cheapest)
			{
				flag = 1;
				displayReportData(ReportData[i], flag);
			}
			else
			{
				flag = 0;
				displayReportData(ReportData[i], flag);
			}
			printf("\n");
		}

		printf("\n");
		displayFinalAnalysis(CatFood[index]);

	}
