//==============================================
// Name:           Harsh Patel
// Student Number: 146315205
// Email:          hpatel262@myseneca.ca
// Section:        IPC144NJJ
// Date:           17 - 07 - 2021
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n') ;     // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
}


// getInt function definition goes here:
int getInt(void)
{
    char NL = 'x';
    int value;        
    while (NL != '\n')
    {
        scanf("%d%c", &value, &NL);
        if (NL != '\n')
        {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
       
    }
    return value;
}


// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
    int integer;
    do
    {
        integer = getInt();
        if (integer < min || integer > max)
        {
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        }
    } while (integer < min || integer > max);

    return integer;
}


// yes function definition goes here:
int yes(void)
{
    char character, NL;
   do
    {
        character = getchar();
        if (character != 'Y' && character != 'y' && character != 'N' && character != 'n')
        {
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        }
        NL = getchar();
        if (NL != '\n')
        {
            clearKeyboard();
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        }
    } while ((character != 'Y' && character != 'y' && character != 'N' && character != 'n') || NL != '\n');

    if (character == 'Y' || character == 'y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// menu function definition goes here:
int menu(void)
{
    int valid_integer ;
    int min = 0;
    int max = 6;
    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");
    printf("\n");
   
    printf("Select an option:> ");
    valid_integer = getIntInRange(min, max);
    return valid_integer;
    
}
// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
    int intA, yesNo;
    do
    {
        intA = menu();
        if (intA != 0)
        {
            printf("\n<<< Feature %d is unavailable >>>\n\n", intA);
            pause();
            yesNo = 0;
        }
        else
        {
            printf("\nExit the program? (Y)es/(N)o: ");
            yesNo = yes();
        }
        printf("\n");
    } while (!yesNo);

    printf("Contact Management System: terminated\n");
}