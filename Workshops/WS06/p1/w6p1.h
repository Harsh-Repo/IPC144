/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   :Harsh Patel
	ID     :146315205
	Email  :hpatel262@myseneca.ca
	Section:IPC144NJJ
	*/
#define MAX_PRODUCTS 3
#define SUGGESTED_GRAMS 64
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
	int skuNumber;
	double price;
	int caloriesPerServing;
	double productWeight;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intA);
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* dbA);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProducts);
 
// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int numProducts_user);

// 5. Display the formatted table header
void displayCatFoodHeader();

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuNumber, const int caloriesPerServing, const double* Price, const double* productWeight);

// 7. Logic entry point
void start(void);

