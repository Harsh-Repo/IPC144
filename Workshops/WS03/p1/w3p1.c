/*
	==================================================
	Workshop #3 (Part-1):
	==================================================
	Name   :HARSH PATEL
	ID     :146315205
	Email  :hpatel262@myseneca.ca
	Section:IPC144NJJ
*/
#include<stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021

int main()
{
	int month, year, t = 1;  // t is just a variable like we use i for running loop.
	const int JAN = 1;
	const int DEC = 12;
	int flag = 0;  // flag
	printf("General Well-being Log\n");
	printf("=======================\n");

	while ((t > 0)&&(flag==0))
	{
		printf("Set the year and month fot the well-being log (YYYY MM): ");
		scanf_s("%d %d", &year, &month);

		if (year<MIN_YEAR || year>MAX_YEAR)
		{
			if (month >= JAN && month <= DEC)
			{
				printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
			}
			else
			{
				if (month < JAN || month> DEC)
				{
					printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
					printf("   ERROR :Jan.(1) - Dec.(12)\n");
				}
			}
		}

		else if (year >= MIN_YEAR && year <= MAX_YEAR)
		{
			if (month < JAN || month> DEC)
			{
				printf("   ERROR: Jan.(1) - Dec.(12)\n");
			}
			else
			{
				if (month >= JAN && month <= DEC)
				{
					printf("\n*** Log date set!***\n");
					flag = 1;
					break;
				}
			}
		}
	}

	
	if (month == 1)
	{
		printf("\nLog starting date: %d-JAN-01", year);
		
	}
	else if (month == 2)
	{
		printf("\nLog starting date: %d-FEB-01", year);
	}
	else if (month == 3)
	{
		printf("\nLog starting date: %d-MAR-01", year);
	}
	else if (month == 4)
	{
		printf("\nLog starting date: %d-APR-01", year);
	}
	else if (month == 5)
	{
		printf("\nLog starting date: %d-MAY-01", year);
	}
	else if (month == 6)
	{
		printf("\nLog starting date: %d-JUN-01", year);
	}
	else if (month == 7)
	{
		printf("\nLog starting date: %d-JUL-01", year);
	}
	else if (month == 8)
	{
		printf("\nLog starting date: %d-AUG-01", year);
	}
	else if (month == 9)
	{
		printf("\nLog starting date: %d-SEP-01", year);
	}
	else if (month == 10)
	{
		printf("\nLog starting date: %d-OCT-01", year);
	}
	else if (month == 11)
	{
		printf("\nLog starting date: %d-NOV-01", year);
	}
	else
	{
		printf("\nLog starting date: %d-DEC-01", year);
	}
	return 0;
}