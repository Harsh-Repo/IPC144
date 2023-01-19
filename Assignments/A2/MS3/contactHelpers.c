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
// |        contents below...                        |
// +-------------------------------------------------+

#include <stdio.h>
#include <ctype.h>
#include <string.h>
// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:

#include "contactHelpers.h"

#define MAXCONTACTS 5

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
    while (getchar() != '\n'); // empty execution code block on purpose
}

// pause: Empty function definition goes here:
void pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
}

// getInt: Empty function definition goes here:
int getInt(void)
{
    char NL = 'x';
    int Value;
    while (NL != '\n')
    {
        scanf("%d%c", &Value, &NL);
        if (NL != '\n')
        {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    }
    return Value;
}

//getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
    int intA;                                                                               
    do
    {
        intA = getInt();
        if (intA < min || intA > max)
        {
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        }
    } while (intA < min || intA > max);

    return intA;
}


// yes: Empty function definition goes here:
int yes(void)
{
    char charA, charB;
    do
    {
        charA = getchar();
        if (charA != 'Y' && charA != 'y' && charA != 'N' && charA != 'n')
        {
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        }
        charB = getchar();
        if (charB != '\n')
        {
            clearKeyboard();
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        }
    } while ((charA != 'Y' && charA != 'y' && charA != 'N' && charA != 'n') || charB != '\n');

    if (charA == 'Y' || charA == 'y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// menu: Empty function definition goes here:
int menu(void)
{
    int intA;
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
    printf("0. Exit\n\n");
    printf("Select an option:> ");
    intA = getIntInRange(min, max);
    return intA;
}

// contactManagerSystem: Empty function definition goes here:

void contactManagerSystem(void)
{
    struct Contact contacts[MAXCONTACTS] = { {  { "Rick", {'\0'}, "Grimes" },
                                                   { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
                                                   { "4161112222", "4162223333", "4163334444" }
                                                },
                                                {
                                                   { "Maggie", "R.", "Greene" },
                                                   { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
                                                   { "9051112222", "9052223333", "9053334444" }
                                                },
                                                {
                                                   { "Morgan", "A.", "Jones" },
                                                   { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
                                                   { "7051112222", "7052223333", "7053334444" }
                                                },
                                                {
                                                   { "Sasha", {'\0'}, "Williams" },
                                                   { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
                                                   { "9052223333", "9052223333", "9054445555" }
                                                },
    };

    int intA, yesNo;
    do
    {
        intA = menu();
        if (intA != 0)
        {
            if (intA == 1)
            {
                printf("\n");
                displayContacts(contacts, MAXCONTACTS);
            }
            else if (intA == 2)
            {
                printf("\n");
                addContact(contacts, MAXCONTACTS);
            }
            else if (intA == 3)
            {
                printf("\n");
                updateContact(contacts, MAXCONTACTS);
            }
            else if (intA == 4)
            {
                printf("\n");
                deleteContact(contacts, MAXCONTACTS);
            }
            else if (intA == 5)
            {
                printf("\n");
                searchContacts(contacts, MAXCONTACTS);
            }
            else if (intA == 6)
            {
                printf("\n");
                sortContacts(contacts, MAXCONTACTS);
            }
            // printf("\n<<< Feature %d is unavailable >>>\n\n", intA);
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





// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1, i;

    while (needInput)
    {
        scanf("%10s", phoneNum);
        clearKeyboard();
        // (String Length Function: validate entry of 10 characters)
        if (strlen(phoneNum) == 10)
        {
            needInput = 0;
            for (i = 0; i < 10; i++)
            {
                if (!(isdigit(phoneNum[i])))
                {
                    needInput = 1;
                }
            }
            if (needInput == 1)
            {
                printf("Enter a 10-digit phone number: ");
            }
        }
        else
        {
            printf("Enter a 10-digit phone number: ");
        }
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
        {
            return i;
        }
    }
    return -1;
}


// displayContactHeader
// Put empty function definition below:

void displayContactHeader(void)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:

void displayContactFooter(int count)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n\n", count);
}

// displayContact:
// Put empty function definition below:

void displayContact(const struct Contact* contact)
{
    printf(" %s ", contact->name.firstName);
    if (contact->name.middleInitial[0] != '\0')
    {
        printf("%s ", contact->name.middleInitial);
    }
    printf("%s\n", contact->name.lastName);
    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
    if (contact->address.apartmentNumber > 0)
    {
        printf("Apt# %d, ", contact->address.apartmentNumber);
    }
    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts:
// Put empty function definition below:

void displayContacts(const struct Contact contacts[], int size)
{
    int i;
    int count = 0;
    displayContactHeader();
    for (i = 0; i < size; i++)
    {
        if (contacts[i].numbers.cell[0] > 0)
        {
            displayContact(&contacts[i]);
            count++;
        }
    }
    displayContactFooter(count);
}

// searchContacts:
// Put empty function definition below:

void searchContacts(const struct Contact contacts[], int size)
{
    char phoneNum[11];
    int index;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNum);
    index = findContactIndex(contacts, size, phoneNum);
    if (index > -1)
    {
        printf("\n");
        displayContact(&contacts[index]);
    }
    else
    {
        printf("*** Contact NOT FOUND ***\n");
    }
    printf("\n");
}

// addContact:
// Put empty function definition below:

void addContact(struct Contact contacts[], int size)
{
    char cellNum[11] = { 0 };
    int index;
    index = findContactIndex(contacts, size, cellNum);
    if (index == -1)
    {
        printf("*** ERROR: The contact list is full! ***\n\n");
    }
    else
    {
        getContact(&contacts[index]);
        printf("--- New contact added! ---\n\n");
    }
}

// updateContact:
// Put empty function definition below:

void updateContact(struct Contact contacts[], int size)
{
    struct Contact empty = { {{0}} };
    char phoneNum[11];
    int index;
    int yesNo, yesNo1, yesNo2;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNum);
    index = findContactIndex(contacts, size, phoneNum);
    if (index > -1)
    {
        printf("\nContact found:\n");
        displayContact(&contacts[index]);
        printf("\n");

        printf("Do you want to update the name? (y or n): ");
        yesNo = yes();
        if (yesNo)
        {
            contacts[index].name = empty.name;
            getName(&contacts[index].name);
        }

        printf("Do you want to update the address? (y or n): ");
        yesNo1 = yes();
        if (yesNo1)
        {
            contacts[index].address = empty.address;
            getAddress(&contacts[index].address);
        }

        printf("Do you want to update the numbers? (y or n): ");
        yesNo2 = yes();
        if (yesNo2)
        {
            contacts[index].numbers = empty.numbers;
            getNumbers(&contacts[index].numbers);
        }

        printf("--- Contact Updated! ---\n\n");
    }
    else
    {
        printf("*** Contact NOT FOUND ***\n\n");
    }

}

// deleteContact:
// Put empty function definition below:

void deleteContact(struct Contact contacts[], int size)
{
    struct Contact empty = { {{0}} };
    char phoneNum[11];
    int index;
    int yesNo;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNum);
    index = findContactIndex(contacts, size, phoneNum);

    if (index > -1)
    {
        printf("\nContact found:\n");
        displayContact(&contacts[index]);
        printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");
        yesNo = yes();
        if (yesNo)
        {
            contacts[index] = empty;
            printf("--- Contact deleted! ---\n");
        }
        printf("\n");
    }
    else
    {
        printf("*** Contact NOT FOUND ***\n");
    }
}

// sortContacts:
// Put empty function definition below:

void sortContacts(struct Contact contacts[], int size)
{
    struct Contact temp = { {{0}} };
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (strcmp(contacts[i].numbers.cell, contacts[j].numbers.cell) < 0)
            {
                temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }
    printf("--- Contacts sorted! ---\n\n");
}