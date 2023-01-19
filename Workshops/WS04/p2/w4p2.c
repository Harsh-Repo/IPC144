/*
    ==================================================
    Workshop #4 (Part-2):
    ==================================================
    Name   :Harsh Patel
    ID     :146315205
    Email  :hpatel262@myseneca.ca
    Section:IPC144NJJ
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
    printf("                      $%11.2lf", total);

    int selection;
    int years1 = 0, years2 = 0, years3 = 0, years4 = 0, months1 = 0, months2 = 0, months3 = 0, months4 = 0;
    double amt_priority2 = 0.00, amt_priority3 = 0.00, amt_priority4 = 0.00;
    double t_months1 = 0.00, t_months2 = 0.00, t_months3 = 0.00, t_months4 = 0.00;
    int count = 0, count1 = 0, count2 = 0, count3 = 0;
    int prior;

    int hold = 0;

    while (t > 0 && hold == 0)
    {
        printf("\nHow do you want to forecast your wish list ?");
        printf("\n1. All items(no filter)");
        printf("\n2. By priority");
        printf("\n0. Quit/Exit");
        printf("\nselection: ");
        scanf("%d", &selection);
        
        if (selection == 1)
        {
            
            printf("\nFilter: All item (no filter)");
            printf("\nAmount: %11.2lf ", total);

            t_months1 = total / income;
            years1 = t_months1 / 12;
            months1 = (int)t_months1 % 12 + 1;

            printf("\nForecast: %d years, %d months", years1, months1);
            int i = 0;
            for (; i < item; i++)
            {
                if ((char)ar[i][3] == 'y')
                {
                    count += 1;
                }
            }
            if (count == 0)
            {
                printf("\n====================================================");                
            }
            else
            {
                printf("\nNOTE: Financing options are available on some items.");
                printf("\n      You can likely reduce the estimated months.");
                printf("\n====================================================");
                
            }
        }
        else if (selection == 2)
        {
            printf("\nWhat priority do you want to filter by? [1-3]: ");
            scanf("%d", &prior);
            printf("\n\n====================================================");
            if (prior == 1)
            {
                printf("\nFilter: by priority (%d)", prior);
                int i = 0;
                for (; i < item; i++)
                {
                    if (ar[i][2] == 1)
                    {
                        amt_priority2 += ar[i][4];
                        if ((char)ar[i][3] == 'y')
                        {
                            count1 += 1;
                        }
                    }
                }

                printf("\nAmount: %11.2lf ", amt_priority2);

                t_months2 = amt_priority2 / income;
                years2 = t_months2 / 12;
                months2 = (int)t_months2 % 12 + 1;
                printf("\nForecast: %d years, %d months", years2, months2);
                if (count1 == 0)
                {
                    printf("\n====================================================");          
                }
                else
                {
                    printf("\nNOTE: Financing options are available on some items.");
                    printf("\n      You can likely reduce the estimated months.");
                    printf("\n====================================================");   
                }
            }
            else if (prior == 2)
            {

                printf("\nFilter: by priority (%d)", prior);
                int i = 0;
                for (; i < item; i++)
                {
                    if (ar[i][2] == 2)
                    {
                        amt_priority3 += ar[i][4];
                        if ((char)ar[i][3] == 'y')
                        {
                            count2 += 1;
                        }
                    }
                }

                printf("\nAmount: %11.2lf ", amt_priority3);

                t_months3 = amt_priority3 / income;
                years3 = t_months3 / 12;
                months3 = (int)t_months3 % 12 + 1;
                printf("\nForecast: %d years, %d months", years3, months3);
                if (count2 == 0)
                {
                    printf("\n====================================================");               
                }
                else
                {
                    printf("\nNOTE: Financing options are available on some items.");
                    printf("\n\     You can likely reduce the estimated months.");
                    printf("\n====================================================");    
                }
            }
            else if (prior == 3)
            {

                printf("\nFilter: by priority (%d)", prior);
                int i = 0;
                for (; i <= item; i++)
                {
                    if (ar[i][2] == 3)
                    {
                        amt_priority4 += ar[i][4];
                        if ((char)ar[i][3] == 'y')
                        {
                            count3 += 1;
                        }
                    }
                }

                printf("\nAmount: %11.2lf ", amt_priority4);

                t_months4 = amt_priority4 / income;
                years4 = t_months4 / 12;
                months4 = (int)t_months4 % 12 + 1;
                printf("\nForecast: %d years, %d months", years4, months4);
                if (count3 == 0)
                {
                    printf("\n====================================================");
                }
                else
                {
                    printf("\nNOTE: Financing options are available on some items.");
                    printf("\n      You can likely reduce the estimated months.");
                    printf("\n====================================================");
                }
            }
        }
        else if (selection == 0)
        {
            printf("\nBest of luck in all your future endeavours!");
            hold = 1;
        }
        else
        {
            printf("\nERROR: Invalid menu selection.");
        }
    }
  return 0;
}