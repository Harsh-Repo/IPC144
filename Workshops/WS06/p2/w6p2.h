/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   :Harsh Patel
	ID     :146315205
	Email  :hpatel262@myseneca.ca
	Section:IPC144NJJ
	*/

// ----------------------------------------------------------------------------
// defines/macros
#define MAX_PRODUCTS 3
#define SUGGESTED_GRAMS 64
#define pound_to_kg 2.20462


// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
	int skuNumber;
	double price;
	int caloriesPerServing;
	double productWeight;
};
struct ReportData
{
	int sku;
	double product_price;
	int cal_per_sugg_serving;
	double weight_pound;
	double weight_kg;
	int weight_g;
	double total_serving;
	double cost_per_serving;
	double cost_cal_per_serving;
};

// ----------------------------------------------------------------------------
// function prototypes
// PART-1

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
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuNumber, const int caloriesPerServing, const double* Price, const double* productWeight);
// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(double* lbs, double* lbs_kg);

// 9. convert lbs: g
int convertLbsG(double* lbs, int* g);

// 10. convert lbs: kg / g
void convertLbs(double* lbs, double* lbs_kg, int* g);


// 11. calculate: servings based on gPerServ
double calculateServings(const int gPerServ, const int totalg, double* no_of_serving);


// 12. calculate: cost per serving
double calculateCostPerServing(double* product_price, double* total_serving, double* cost_per_serving);

// 13. calculate: cost per calorie
double calculateCostPerCal(double* product_price, double* total_calories, double* cost_per_calories);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo);


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData ReportData, const int chepest_product);


// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapest_Reportdata);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);
