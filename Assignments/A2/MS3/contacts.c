//==============================================
// Name:           Harsh Patel
// Student Number: 146315205
// Email:          hpatel262@myseneca.ca
// Section:        ipc144NJJ
// Date:           
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
#include "contacts.h"
#include "contactHelpers.h"

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

    //printf("Do you want to enter a cell phone number? (y or n): ");
    //scanf("%c%*c", &yesNo);

    //if (yesNo == 'y' || yesNo == 'Y')
    //{
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);
    //scanf("%10[^\n]", numbers->cell);
    //clearKeyboard();
    //}

    printf("Do you want to enter a home phone number? (y or n): ");
    //scanf("%c%*c", &yesNo);
    yesNo = yes();

    //if (yesNo == 'y' && yesNo == 'Y') // <-- No! can't be both 'y' AND 'Y' (should be OR ||)
    if (yesNo)
    {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);
        //scanf("%10[^\n]", numbers->home);
        //clearKeyboard();
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    //scanf("%c%*c", &yesNo);
    yesNo = yes();

    if (yesNo)
    {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
        //scanf("%10[^\n]", numbers->business);
        //clearKeyboard();
    }
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:

void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}