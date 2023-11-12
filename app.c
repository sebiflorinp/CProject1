#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// data structure to store transactions
struct transaction;

//function to print instructions
void printInstructions();

//function to run all tests
bool runAllTests();

//functions to test each getter
bool testGetDay();
bool testGetMonth();
bool testGetYear();
bool testGetDescription();
bool testGetValue();
bool testGetType();
bool testGetTransaction();

//a function to test compareTransactions
bool testCompareTransactions();

//a function for comparing two expenses
bool compareTransactions(struct transaction transaction1, struct transaction transaction2);

//getters
int getDay(struct transaction transaction);
int getMonth(struct transaction transaction);
int getYear(struct transaction transaction);
const char *getDescription(struct transaction transaction);
float getValue(struct transaction transaction);
const char *getType(struct transaction transaction);
struct transaction getTransaction(int day, int month, int year, char description[], float value, char type[]);

//test Float equality
bool testFloatEquality();

//for checking if 2 floats are equal
bool floatEquality(float value1, float value2);

//obtaining a transaction from the user
struct transaction obtainTransaction();

//tests for all functions that validate data
bool testValidateDay();
bool testValidateMonth();
bool testValidateYear();
bool testValidateDescription();
bool testValidateValue();
bool testValidateType();

//functions that validate input
bool validateDay(char day[]);
bool validateMonth(char month[]);
bool validateYear(char year[]);
bool validateDescription(char description[]);
bool validateValue(char value[]);
bool validateType(char type[]);

//function for printing tables
void printTable(struct transaction transactions);

//function to test addTransaction
bool testAddTransaction();

//function to add a transactions
void addTransaction(struct transaction transaction);

//function to test calculateAccountBalance
bool testCalculateAccountBalance();

//function that returns your account balance
float calculateAccountBalance(struct transaction transactions);

//function to get a date interval
void obtainDateInterval();

//function to test displayExpensesAndIncomes
bool testDisplayExpensesAndIncomes();

//function that prints expenses and incomes
void displayExpensesAndIncomes(int day1, int month1, int year1, int day2, int month2, int year2);

//function that saves the transactions locally
void saveTransactions();

//function that load the expenses from a file
void loadTransactions();

struct transaction
{
  int day;
  int month;
  int year;
  char description[255];
  float value;
  char type[255];
};

int main()
{
  //runAllTests();
  struct transaction transaction = getTransaction(1, 2, 3, "fdg", 12.2, "Expense");
  printf("%s", transaction.description);
  char description[200];
  strcpy(description, getDescription(transaction));
  printf("%s",description);
  printInstructions();
  while (true)
  {
    printf("What option do you want to choose?\n");
    int action;
    scanf("%d", &action);
  }
  return 0;
}

void printInstructions()
{
  /*
  A function that prints the instructions of the application.
  Precondition: -
  Post-conditions: -
  */
  printf("Welcome!\nThis application manages financial data.\nYou can choose one of the following actions:\n  1. Add a transaction.\n  2. Print all transactions.\n  3. Print account balance,\n  4. Print the incomes and expenses from a certain period of time.\n  5. Save the transaction.\n  6. Load the transactions.\n");
}

bool runAllTests()
{
  if(!testFloatEquality())
    return false;
  return true;
};

bool testFloatEquality()
{
  if(floatEquality(1.2, 1.2) == false)
    return false;
  if(floatEquality(2.3004, 2.3005) == true)
    return false;
  return true;
}

bool floatEquality(float value1, float value2)
{
  /*
  A function that checks the equality of two floats.
  Preconditions: value1: a float
                 value2: a float
  Post-conditions: a boolean
  */
  return abs(value1 - value2) < 0.00000000001;
}

bool testGetDay()
{
  struct transaction transaction1 = {2, 1, 2000, "A necessary expense!", 50.20, "Expense"};
  struct transaction transaction2 = {10, 2, 1919, "An inheritance!", 1000, "Income"};
  if (getDay(transaction1) != 2)
    return false;
  if (getDay(transaction2) != 10)
    return false;
  return true;
}

bool testGetMonth()
{
  struct transaction transaction1 = {2, 1, 2000, "A necessary expense!", 50.20, "Expense"};
  struct transaction transaction2 = {10, 2, 1919, "An inheritance!", 1000, "Income"};
  if (getMonth(transaction1) != 1)
    return false;
  if (getMonth(transaction2) != 2)
    return false;
  return true;
}

bool testGetYear()
{
  struct transaction transaction1 = {2, 1, 2000, "A necessary expense!", 50.20, "Expense"};
  struct transaction transaction2 = {10, 2, 1919, "An inheritance!", 1000, "Income"};
  if (getYear(transaction1) != 2000)
    return false;
  if (getYear(transaction2) != 1919)
    return false;
  return true;
}

bool testGetDescription()
{
  struct transaction transaction1 = {2, 1, 2000, "A necessary expense!", 50.20, "Expense"};
  struct transaction transaction2 = {10, 2, 1919, "An inheritance!", 1000, "Income"};
  if (getDescription(transaction1) != "A necessary expense!")
    return false;
  if (getDescription(transaction2) != "An inheritance!")
    return false;
  return true;
}

bool testGetValue()
{
  struct transaction transaction1 = {2, 1, 2000, "A necessary expense!", 50.20, "Expense"};
  struct transaction transaction2 = {10, 2, 1919, "An inheritance!", 1000, "Income"};
  if (floatEquality(getValue(transaction1), 50.20) != true)
    return false;
  if (floatEquality(getValue(transaction2), 1000.01) != false)
    return false;
  return true;
}

bool testGetType()
{
  struct transaction transaction1 = {2, 1, 2000, "A necessary expense!", 50.20, "Expense"};
  struct transaction transaction2 = {10, 2, 1919, "An inheritance!", 1000, "Income"};
  if (getDescription(transaction1) != "A necessary expense!")
    return false;
  if (getDescription(transaction2) == "An inheritance")
    return false;
  return true;
}

bool testGetTransaction()
{
  struct transaction transaction1 = {2, 1, 2000, "A necessary expense!", 50.20, "Expense"};
  struct transaction transaction2 = getTransaction(2, 1, 2000, "A necessary expense!", 50.20, "Expense");
  if (compareTransactions(transaction1, transaction2) != true)
    return false;
  transaction2 = getTransaction(1, 1, 2000, "A necessary expense!", 50.20, "Expense");
  if(compareTransactions(transaction1, transaction2) != false)
    return false;
  transaction2 = getTransaction(2, 3, 2000, "A necessary expense!", 50.20, "Expense");
  if(compareTransactions(transaction1, transaction2) != false)
    return false;
  transaction2 = getTransaction(2, 1, 2001, "A necessary expense!", 50.20, "Expense");
  if(compareTransactions(transaction1, transaction2) != false)
    return false;
  transaction2 = getTransaction(2, 1, 2000, "A necessary expens!", 50.20, "Expense");
  if(compareTransactions(transaction1, transaction2) != false)
    return false;
  transaction2 = getTransaction(2, 1, 2000, "A necessary expense!", 50.10, "Expense");
  if(compareTransactions(transaction1, transaction2) != false)
    return false;
  transaction2 = getTransaction(2, 1, 2000, "A necessary expense!", 50.20, "Income");
  if(compareTransactions(transaction1, transaction2) != false)
    return false;
  return true;
}

int getDay(struct transaction transaction)
{
  /*
  A function that returns the day when the transaction was made.
  Preconditions: a structure with the day, month, year, description, value and type of the transaction.
  Post-conditions: a positive int between 1 and 31.
  */
  return transaction.day;
}

int getMonth(struct transaction transaction)
{
  /*
  A function that returns the month when the transaction was made.
  Preconditions: a structure with the day, month, year, description, value and type of the transaction.
  Post-conditions: a positive int between 1 and 12.
  */
  return transaction.month;
}

int getYear(struct transaction transaction)
{
  /*
  A function that returns the year when the transaction was made.
  Preconditions: a structure with the day, month, year, description, value and type of the transaction.
  Post-conditions: a positive int that is bigger than 0.
  */
}

const char * getDescription(struct transaction transaction)
{
  /*
  A function that returns the description of the transaction.
  Preconditions: a structure with the day, month, year, description, value and type of the transaction
  Post-conditions: a non-empty array of chars.
  */
  char *pointer;
  return pointer;
}

float getValue(struct transaction transaction)
{
  /*
  A function that returns the value of the transaction.
  Preconditions: a structure with the day, month, year, description, value and type of the transaction
  Post-conditions: a positive float that is bigger than 0.
  */
  return transaction.value;
}

const char *getType(struct transaction transaction)
{
  /*
  A function that returns the type of the transaction.
  Preconditions: a structure with the day, month, year, description, value and type of the transaction
  Post-conditions: a non-empty string that is one of the following: "Expense", "Income".
  */
  char *type = transaction.type;
  return type;
}

struct transaction getTransaction(int day, int month, int year, char description[], float value, char type[])
{
  /*
  A function that returns a transaction.
  Preconditions: day: a positive int between 1 and 31.
                 month: a positive int between 1 and 12.
                 year: a positive int that is bigger than 0.
                 description: a non-empty string.
                 value: a positive float that is bigger than 0.
                 type: a non-empty string that has to be one of the following: "Expense", "Income".
  Post-conditions: a struct that contains the day, month, year, description, value and type of a transaction.
  */
  struct transaction transaction = {day, month, year, *description, value, *type};
  return transaction;
}

bool testCompareTransactions()
{
  struct transaction transaction1 = {2, 1, 2000, "A necessary expense!", 50.20, "Expense"};
  struct transaction transaction2 = {10, 2, 1919, "An inheritance!", 1000, "Income"};
  struct transaction transaction3 = {2, 1, 2000, "A necessary expense!", 50.20, "Expense"};
  if (compareTransactions(transaction1, transaction2) != false)
    return false;
  if (compareTransactions(transaction1, transaction3) != true)
    return false;
  if (compareTransactions(transaction2, transaction3) != false)
    return false;
  return true;
}

bool compareTransactions(struct transaction transaction1, struct transaction transaction2)
{
  /*
  A function that returns whether two transactions are the same or not.
  Preconditions: transaction1: a struct that contains the day, the month, the year, the description, the value and the type of the transaction.
                 transaction2: a struct that contains the day, the month, the year, the description, the value and the type of the transaction.
  Post-conditions: a boolean.
  */
  if (transaction1.day != transaction2.day)
    return false;
  if (transaction1.month != transaction2.month)
    return false;
  if (transaction1.year != transaction2.year)
    return false;
  if (transaction1.description != transaction2.description)
    return false;
  if (transaction1.type != transaction2.type)
    return false;
  if (floatEquality(transaction1.value, transaction2.value) == false)
    return false;
  return true;
}

bool testValidateDay()
{
  if (validateDay("12") != true)
    return false;
  if(validateDay("100") != false)
    return false;
  if(validateDay("0") != false)
    return false;
  if(validateDay("1s4") != false)
    return false;
  return true;
}

bool testValidateMonth()
{
  if (validateMonth("2") != true)
    return false;
  if (validateMonth("20") != false)
    return false;
  if (validateMonth("0") != false)
    return false;
  if (validateMonth("ad") != false)
    return false;
  return true;
}

bool testValidateYear()
{
  if (validateYear("1000") != true)
    return false;
  if (validateYear("0") != false)
    return false;
  if (validateYear("adf") != false)
    return false;
  return true;
}

bool testValidateDescription()
{
  if (validateDescription("asfg, sdgg.") != true)
    return false;
  if (validateDescription("") != false)
    return false;
  return true;
}

bool testValidateValue()
{
  if (validateValue("30") != true)
    return false;
  if (validateValue("10.20") != true)
    return false;
  if (validateValue("ag") != false)
    return false;
  if (validateValue("0") != false)
    return false;
  return true;
}

bool testValidateType()
{
  if (validateType("Expense") != true)
    return false;
  if (validateType("Income") != true)
    return false;
  if (validateType("sfgh") != false)
    return false;
  if (validateType("") != false)
    return false;
  return true;
}

bool validateDay(char day[])
{
  /*
  A function that checks if the received string is a valid day.
  Preconditions: day: a string.
  Post-conditions: a bool.
  */
  if (strlen(day) == 0)
    return false;
  for (int index = 0; index < strlen(day); index++)
  {
    if(!('0' < day[index] && day[index] < '9'))
      return false;
  }
  if (!(0 < atoi(day) && atoi(day) < 32))
    return false;
  return true;
}

bool validateMonth(char month[])
{
  /*
  A function that checks if the received string is a valid month.
  Preconditions: month: a string
  Post-conditions: a bool.
  */
  if (strlen(month) == 0)
    return false;
  for (int index = 0; index < strlen(month); index++)
  {
    if (!('0' <= month[index] && month[index] <= '9'))
      return false;

  }
  if(!(0 < atoi(month) && atoi(month) < 13))
    return false;
  return true;
}

bool validateYear(char year[])
{
  /*
  A function that checks if the received string is a valid year.
  Preconditions: year: a string
  Post-conditions: a bool.
  */
  if (strlen(year) == 0)
    return false;
  for (int index = 0; index < strlen(year); index++)
  {
    if (!('0' <= year[index] && year[index] <= '9'))
      return false;
  }
  if (!(0 < atoi(year)))
    return false;
  return true;
}

bool validateDescription(char description[])
{
  /*
  A function that checks if a string is a valid description.
  Preconditions: description: a string
  Post-conditions: a bool
  */
  if (strlen(description) == 0)
    return false;
  return true;
}

bool validateValue(char value[])
{
  /*
  A function that checks if the received string is a valid value.
  Preconditions: value: string
  Post-conditions: a bool
  */
  if (strlen(value) == 0)
    return false;
  for (int index = 0; index < strlen(value); index++)
  {
    if (!('0' <=  value[index] && value[index] <= '9' || value[index] != '.'))
      return false;
  }
  if (atof(value) <= 0)
    return false;
  return true;
}

bool validateType(char type[])
{
  /*
  A function that checks if a received string is a valid type.
  Preconditions: a string
  Post-conditions: a bool
  */
  if (type != "Expense" && type != "Income")
    return false;
  return true;
}