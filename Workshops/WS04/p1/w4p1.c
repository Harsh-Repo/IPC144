/*
	==================================================
	Workshop #4 (Part-1):
	==================================================
	Name   :Harsh Patel
	ID     :146315205
	Email  :hpatel262@myseneca.ca
	Section: IPC144NJJ
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define max_item 10
#define max_cost 100
int main()
{
	float income;
	const float max_income = 400000.00;
	const float min_income = 500.00;
	int flag = 0;
	int t = 1;

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");
	while (t > 0 && (flag == 0))

	{
		printf("\nEnter your monthly NET income: $");
		scanf("%f", &income);
		if (income < min_income)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
		}
		else if (income > max_income)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
		}
		else
		{
			if (income >= min_income && income <= max_income)
			{
				flag = 1;
			}
		}
	}

	int priority;
	char finance_option;
	double total = 0;
	int item;
	int n = 1;
	while (n > 0)
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &item);
		if (item < 1 || item > max_item)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}
		else if (item >= 1 && item <= max_item)
		{
			break;
		}
	}
	double cost;
	double ar[10][4];
	int i = 1;
	for (; i <= item; i++)
	{
		ar[i][1] = i;
		printf("\nItem-%d Details:\n", i);

		while (n > 0)
		{
			printf("   Item cost: $");
			scanf("%lf", &cost);
			if (cost < max_cost)
			{
				printf("      ERROR: Cost must be at least $100.00\n");
			}
			else
			{
				if (cost >= max_cost)
				{
					ar[i][4] = cost;
					total = total + cost;
					break;
				}
			}
		}

		while (n > 0)
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority);

			if (priority < 1 || priority > 3)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
			}
			else if (priority >= 1 || priority <= 3)
			{
				ar[i][2] = priority;
				break;
			}
		}

		while (n > 0)
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &finance_option);
			if ((finance_option != 'y') && (finance_option != 'n'))
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}

			else
			{
				if ((finance_option == 'y') || (finance_option == 'n'))
				{
					ar[i][3] = finance_option;
					break;
				}
			}
		}
	}
	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	int j = 1;
	for (; j <= item; j++)

	{
		printf("%3d  %5d    %5c    %11.2lf\n", (int)ar[j][1], (int)ar[j][2], (char)ar[j][3], ar[j][4]);
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", total);
	printf("Best of luck in all your future endeavours!\n");

	return 0;
}