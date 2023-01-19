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

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"

//============================================
// getName:
void getName(struct Name* name)
{

    int yesNo;

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);
    clearKeyboard();
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    //scanf("%s%*c", &yesNo); //<--- Incorrect, not a c string, must be a char
    //scanf("%c%*c", &yesNo);
    yesNo = yes();
    if (yesNo == 1)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
        clearKeyboard();
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", name->lastName);
    clearKeyboard();
}

// getAddress:
void getAddress(struct Address* address)
{
    int yesNo;

    printf("Please enter the contact's street number: ");
    do
    {
        //scanf("%d%*c", &address->streetNumber);
        address->streetNumber = getInt();
        if (address->streetNumber < 1)
        {
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        }
    } while (address->streetNumber < 1);

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);
    clearKeyboard();

    printf("Do you want to enter an apartment number? (y or n): ");
    //scanf("%c%*c", &yesNo);
    yesNo = yes();

    if (yesNo)
    {
        printf("Please enter the contact's apartment number: ");
        do
        {
            //scanf("%d%*c", &address->apartmentNumber);
            address->apartmentNumber = getInt();
            if (address->apartmentNumber < 1)
            {
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            }
        } while (address->apartmentNumber < 1);
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", address->city);
    clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    int yesNo;
    printf("Please enter the contact's cell phone number: ");
    scanf("%10[^\n]", numbers->cell);
    clearKeyboard();

    printf("Do you want to enter a home phone number? (y or n): ");
    //scanf("%c%*c", &yesNo);
    yesNo = yes();

    if (yesNo)
    {
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]", numbers->home);
        clearKeyboard();
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    //scanf("%c%*c", &yesNo);
    yesNo = yes();

    if (yesNo)
    {
        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]", numbers->business);
        clearKeyboard();
    }
}

// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}

