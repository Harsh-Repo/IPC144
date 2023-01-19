
#include <stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021
#define LOG_DAYS 3
#define _CRT_SECURE_NO_WARNINGS
int main()
{
	int month, year, t = 1;				//variables used.
	int flag = 0;
	const int JAN = 1;
	const int DEC = 12;
	float evening, morning;
	int n = 1;
	float eve = 0, mor = 0, sum = 0;
	printf("General Well-Being Log\n");
	printf("======================\n");

	while (t > 0 && (flag == 0))			// loop for printing correct year and month                                            
	{
		printf("Set the year and month fot the well-being log (YYYY MM): ");
		scanf("%d %d", &year, &month);

		if (year < MIN_YEAR || year > MAX_YEAR)
		{
			if (month >= JAN && month <= DEC)
			{
				printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
			}
			else
			{
				if (month < JAN || month > DEC)
				{
					printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
					printf("   ERROR: Jan.(1) - Dec.(12)\n");
				}
			}
		}

		else if (year >= MIN_YEAR && year <= MAX_YEAR)
		{
			if (month < JAN || month > DEC)
			{
				printf("   ERROR: Jan.(1) - Dec.(12)\n");
			}
			else
			{
				if (month >= JAN && month <= DEC)
				{
					printf("\n*** Log date set! ***\n");
					flag = 1;
				}
			}
		}
	}
	
	if (month == JAN)			//condition used for JAN month
	{
		int i = 1;
		for (; i <= LOG_DAYS; i++)
		{
			printf("\n%d-JAN-0%d\n", year, i);
			while (n > 0)
			{
				printf("\n   Morning rating(0.0-5.0): ");
				scanf("%f", &morning);
				if (morning < 0.0 || morning > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (morning >= 0.0 && morning <= 5.0)
				{
					mor = mor + morning;
					break;
				}
			}
			while (n > 0)
			{
				printf("\n   Evening rating(0.0-5.0): ");
				scanf("%f", &evening);
				if (evening < 0.0 || evening > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (evening >= 0.0 && evening <= 5.0)
				{
					eve = eve + evening;
					break;
				}
			}
		}
	}
	else if (month == 2)				//Conditon for FEB month 
	{
		int i = 1;
		for (; i <= LOG_DAYS; i++)
		{
			printf("\n%d-FEB-0%d\n", year, i);
			while (n > 0)
			{
				printf("   Morning rating(0.0-5.0): ");
				scanf("%f", &morning);
				if (morning < 0.0 || morning > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (morning >= 0.0 && morning <= 5.0)
				{
					mor = mor + morning;
					break;
				}
			}
			while (n > 0)
			{
				printf("   Evening rating(0.0-5.0): ");
				scanf("%f", &evening);
				if (evening < 0.0 || evening > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (evening >= 0.0 && evening <= 5.0)
				{
					eve = eve + evening;
					break;
				}
			}
		}
	}
	else if (month == 3)	//Conditon for MAR month 
	{
		int i = 1;
		for (; i <= LOG_DAYS; i++)
		{
			printf("\n%d-MAR-0%d\n", year, i);
			while (n > 0)
			{
				printf("   Morning rating(0.0-5.0): ");
				scanf("%f", &morning);
				if (morning < 0.0 || morning > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (morning >= 0.0 && morning <= 5.0)
				{
					mor = mor + morning;
					break;
				}
			}
			while (n > 0)
			{
				printf("\tEvening rating(0.0-5.0): ");
				scanf("%f", &evening);
				if (evening < 0.0 || evening > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (evening >= 0.0 && evening <= 5.0)
				{
					eve = eve + evening;
					break;
				}
			}
		}
	}
	else if (month == 4)	//Conditon for APR month 
	{
		int i = 1;
		for (; i <= LOG_DAYS; i++)
		{
			printf("\n%d-APR-0%d\n", year, i);
			while (n > 0)
			{
				printf("   Morning rating(0.0-5.0): ");
				scanf("%f", &morning);
				if (morning < 0.0 || morning > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (morning >= 0.0 && morning <= 5.0)
				{
					mor = mor + morning;
					break;
				}
			}
			while (n > 0)
			{
				printf("\tEvening rating(0.0-5.0): ");
				scanf("%f", &evening);
				if (evening < 0.0 || evening > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (evening >= 0.0 && evening <= 5.0)
				{
					eve = eve + evening;
					break;
				}
			}
		}
	}
	else if (month == 5)	//Conditon for MAY month 
	{
		int i = 1;
		for (; i <= LOG_DAYS; i++)
		{
			printf("\n%d-MAY-0%d\n", year, i);
			while (n > 0)
			{
				printf("   Morning rating(0.0-5.0): ");
				scanf("%f", &morning);
				if (morning < 0.0 || morning > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (morning >= 0.0 && morning <= 5.0)
				{
					mor = mor + morning;
					break;
				}
			}
			while (n > 0)
			{
				printf("\tEvening rating(0.0-5.0): ");
				scanf("%f", &evening);
				if (evening < 0.0 || evening > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (evening >= 0.0 && evening <= 5.0)
				{
					eve = eve + evening;
					break;
				}
			}
		}
	}
	else if (month == 6)	//Conditon for JUN month 
	{
		int i = 1;
		for (; i <= LOG_DAYS; i++)
		{
			printf("\n%d-JUN-0%d\n", year, i);
			while (n > 0)
			{
				printf("   Morning rating(0.0-5.0): ");
				scanf("%f", &morning);
				if (morning < 0.0 || morning > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (morning >= 0.0 && morning <= 5.0)
				{
					mor = mor + morning;
					break;
				}
			}
			while (n > 0)
			{
				printf("\tEvening rating(0.0-5.0): ");
				scanf("%f", &evening);
				if (evening < 0.0 || evening > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (evening >= 0.0 && evening <= 5.0)
				{
					eve = eve + evening;
					break;
				}
			}
		}
	}
	else if (month == 7)	//Conditon for JUL month 
	{
		int i = 1;
		for (; i <= LOG_DAYS; i++)
		{
			printf("\n%d-JUL-0%d\n", year, i);
			while (n > 0)
			{
				printf("   Morning rating(0.0-5.0): ");
				scanf("%f", &morning);
				if (morning < 0.0 || morning > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (morning >= 0.0 && morning <= 5.0)
				{
					mor = mor + morning;
					break;
				}
			}
			while (n > 0)
			{
				printf("\tEvening rating(0.0-5.0): ");
				scanf("%f", &evening);
				if (evening < 0.0 || evening > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (evening >= 0.0 && evening <= 5.0)
				{
					eve = eve + evening;
					break;
				}
			}
		}
	}
	else if (month == 8)	//Conditon for AUG month 
	{
		int i = 1;
		for (; i <= LOG_DAYS; i++)
		{
			printf("\n%d-AUG-0%d\n", year, i);
			while (n > 0)
			{
				printf("   Morning rating(0.0-5.0): ");
				scanf("%f", &morning);
				if (morning < 0.0 || morning > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (morning >= 0.0 && morning <= 5.0)
				{
					mor = mor + morning;
					break;
				}
			}
			while (n > 0)
			{
				printf("\tEvening rating(0.0-5.0): ");
				scanf("%f", &evening);
				if (evening < 0.0 || evening > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (evening >= 0.0 && evening <= 5.0)
				{
					eve = eve + evening;
					break;
				}
			}
		}
	}
	else if (month == 9)	//Conditon for SEP month 
	{
		int i = 1;
		for (; i <= LOG_DAYS; i++)
		{
			printf("\n%d-SEP-0%d\n", year, i);
			while (n > 0)
			{
				printf("   Morning rating(0.0-5.0): ");
				scanf("%f", &morning);
				if (morning < 0.0 || morning > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (morning >= 0.0 && morning <= 5.0)
				{
					mor = mor + morning;
					break;
				}
			}
			while (n > 0)
			{
				printf("\tEvening rating(0.0-5.0): ");
				scanf("%f", &evening);
				if (evening < 0.0 || evening > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (evening >= 0.0 && evening <= 5.0)
				{
					eve = eve + evening;
					break;
				}
			}
		}
	}
	else if (month == 10)	//Conditon for OCT month 
	{
		int i = 1;
		for (; i <= LOG_DAYS; i++)
		{
			printf("\n%d-OCT-0%d\n", year, i);
			while (n > 0)
			{
				printf("   Morning rating(0.0-5.0): ");
				scanf("%f", &morning);
				if (morning < 0.0 || morning > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (morning >= 0.0 && morning <= 5.0)
				{
					mor = mor + morning;
					break;
				}
			}
			while (n > 0)
			{
				printf("\tEvening rating(0.0-5.0): ");
				scanf("%f", &evening);
				if (evening < 0.0 || evening > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (evening >= 0.0 && evening <= 5.0)
				{
					eve = eve + evening;
					break;
				}
			}
		}
	}
	else if (month == 11)	//Conditon for NOV month 
	{
		int i = 1;
		for ( ;i <= LOG_DAYS; i++)
		{
			printf("\n%d-NOV-0%d\n", year, i);
			while (n > 0)
			{
				printf("   Morning rating(0.0-5.0): ");
				scanf("%f", &morning);
				if (morning < 0.0 || morning > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (morning >= 0.0 && morning <= 5.0)
				{
					mor = mor + morning;
					break;
				}
			}
			while (n > 0)
			{
				printf("\tEvening rating(0.0-5.0): ");
				scanf("%f", &evening);
				if (evening < 0.0 || evening > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (evening >= 0.0 && evening <= 5.0)
				{
					eve = eve + evening;
					break;
				}
			}
		}
	}
	else	//Conditon for DEC month 
	{
		int i = 1;
		for (; i <= LOG_DAYS; i++)
		{
			printf("\n%d-DEC-0%d\n", year, i);
			while (n > 0)
			{
				printf("   Morning rating(0.0-5.0): ");
				scanf("%f", &morning);
				if (morning < 0.0 || morning > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (morning >= 0.0 && morning <= 5.0)
				{
					mor = mor + morning;
					break;
				}
			}
			while (n > 0)
			{
				printf("\tEvening rating(0.0-5.0): ");
				scanf("%f", &evening);
				if (evening < 0.0 || evening > 5.0)
				{
					printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				}
				else if (evening >= 0.0 && evening <= 5.0)
				{
					eve = eve + evening;
					break;
				}
			}
		}
	}

	float avg_mor = mor / LOG_DAYS;
	float avg_eve = eve / LOG_DAYS;
	float avg = (avg_mor + avg_eve) /2;
	sum = mor + eve;
	printf("\nSummary\n");
	printf("=======\n");
	printf("Morning total rating: %0.3f\n", mor);
	printf("Evening total rating: %0.3f\n", eve);
	printf("----------------------------\n");
	printf("Overall total rating: %0.3f\n", sum);
	printf("\n");
	printf("Average morning rating: %0.1f\n", avg_mor);
	printf("Average evening rating: %0.1f\n", avg_eve);
	printf("----------------------------\n");
	printf("Average overall rating: %0.1f\n", avg);
	return 0;
}



