#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

// data structure to store transactions and date
struct date;
struct transaction;
struct date
{
  int day;
  int month;
  int year;
};
struct transaction
{
  struct date date;
  char description[255];
  float value;
  char type[255];
};

//function to print instructions
void printInstructions();

//functions to obtain input from the user
int obtainAction();
struct date obtainDate();
char *obtainDescription();
float obtainValue();
char* obtainType();

//function to run all tests
bool runAllTests();

//tests for all functions that validate data
bool testValidateAction();
bool testValidateDate();
bool testValidateDescription();
bool testValidateValue();
bool testValidateType();
bool testMax();
bool testCompareTwoDates();

//functions that validate input
bool validateAction(char action[]);
bool validateDate(char date[]);
bool validateDescription(char description[]);
bool validateValue(char value[]);
bool validateType(char type[]);

//function that calculate the max between two values
int max(int value1, int value2);

//function to compare two dates
bool compareTwoDates(struct date date1,struct date date2);

// F1
struct transaction obtainTransaction();
//F2
void printData(struct transaction transactions[200], int length);
//F3
void displayAccountBalance(struct transaction transactions[200], int length);
//F4
void displayExpensesAndIncomes(struct transaction transactions[200], int length);
// F5
void saveData(struct transaction transactions[200], int length);
//F6
int loadData(struct transaction transactions[200]);

int main()
{
  runAllTests();
  printInstructions();
  struct transaction transactions[200];
  int transactionsLength = 0;
  while (true)
  {
    int action = obtainAction("What option do you want to choose?\n", "That was not a valid option, please choose a valid one.\n");
    switch (action)
    {
      case 1:
        transactions[transactionsLength] = obtainTransaction();
        transactionsLength++;
        break;
      case 2:
        printData(transactions, transactionsLength);
        break;
      case 3:
        displayAccountBalance(transactions, transactionsLength);
        break;
      case 4:
        displayExpensesAndIncomes(transactions, transactionsLength);
        break;
      case 5:
        saveData(transactions, transactionsLength);
        printf("The transactions were saved successfully!\n");
        break;
      case 6:
        transactionsLength = loadData(transactions);
        break;
      case 7:
        return 0;
        break;
      }
  }

  return 0;
}

bool runAllTests()
{
  /*
  A function that runs all of the tests.
  Preconditions: -
  Post-conditions: a bool
  */
  if (!testValidateAction())
    return false;
  if (!testValidateDate())
    return false;
  if (!testValidateDescription())
    return false;
  if (!testValidateValue())
    return false;
  if (!testValidateType())
    return false;
  if (!testMax())
    return false;
  if (!testCompareTwoDates())
    return false;
  return true;
}

void printInstructions()
{
  /*
  A function that prints the instructions of the application.
  Precondition: -
  Post-conditions: -
  */
  printf("Welcome!\nThis application manages financial data.\nYou can choose one of the following actions:\n  1. Add a transaction.\n  2. Print all transactions.\n  3. Print account balance,\n  4. Print the incomes and expenses from a certain period of time.\n  5. Save the transaction.\n  6. Load the transactions.\n  7. Exit the application.\n");
}

bool testValidateAction()
{
  if (validateAction("10") != false)
    return false;
  if (validateAction("0") != false)
    return false;
  if (validateAction("as5") != false)
    return false;
  if (validateAction("3") != true)
    return false;
  return true;
}

bool testValidateDate()
{
  if (validateDate("12.34.567") != false)
    return false;
  if (validateDate("12a/12/2434") != false)
    return false;
  if (validateDate("16/12/2000") != false)
    return false;
  if (validateDate("11/111/2000") != false)
    return false;
  if (validateDate("12/16/0") != false)
    return false;
  if (validateDate("3/19/2004") != true)
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

bool testMax()
{
  if (max(12, 14) == 12)
    return false;
  if (max(12, 14) != 14)
    return false;
  if (max(15, 16) == 15)
    return false;
  if (max(15, 16) != 16)
    return false;
  return true;
}

bool testCompareTwoDates()
{
  struct date date1 = {10, 30, 2000};
  struct date date2 = {11, 30, 2000};
  struct date date3 = {10, 20, 2000};
  struct date date4 = {10, 30, 2001};

  if (compareTwoDates(date1, date2) != true)
    return false;
  if (compareTwoDates(date1, date3) != false)
    return false;
  if (compareTwoDates(date1, date4) != true)
    return false;
  return true;
}

bool validateAction(char action[])
{
  /*
  A function that checks if the received input is a valid action.
  Preconditions: action: a string
  Post-conditions: a bool
  */
  for (int index = 0; index < strlen(action); index++)
    if (!('0' <= action[index] && action[index] <= '9'))
      return false;
  if (!(1 <= atoi(action) && atoi(action) <= 7))
    return false;
  return true;
}

bool validateDate(char date[])
{
  /*
  A function that checks if the received input is a valid date.
  Preconditions: date: a string
  Post-conditions: a bool
  */
  for (int index = 0; index < strlen(date); index++)
  {
    if (!('0' <= date[index] && date[index] <= '9' || date[index] == '/'))
      return false;
  }
  char dateToBeModified[200];
  strcpy(dateToBeModified, date);
  char *pointer = strtok(dateToBeModified, "/");
  if (!(1 <= atoi(pointer) && atoi(pointer) <= 12))
    return false;
  pointer = strtok(NULL, "/");
  if (!(1 <= atoi(pointer) && atoi(pointer) <= 31))
    return false;
  pointer = strtok(NULL, "/");
  if (!(1 <= atoi(pointer) && atoi(pointer) <= 9999))
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
    if (!('0' <=  value[index] && value[index] <= '9' || value[index] == '.'))
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
  if (strcmp(type, "Expense") && strcmp(type,"Income"))
    return false;
  return true;
}

int obtainAction(char initialMessage[], char messageForInvalidData[])
{
  /*
  A function that asks the user for input the number of an action,
  Preconditions: initialMessage: a string
                 messageForInvalidData: a string
  Post-conditions: a integer between 1 and 7
  */
  char message[200];
  strcpy(message, initialMessage);
  char action[100];
  while (true)
  {
    printf("%s",message);
    scanf("%s", action);
    if (validateAction(action))
    {
      return atoi(action);
    }
    else
    {
      strcpy(message, messageForInvalidData);
    }
  }
}

struct date obtainDate(char initialMessage[], char messageForInvalidData[])
{
  /*
  A function that asks the user to input a valid date for their transaction.
  Preconditions: initialMessage: a string
                 messageForInvalidData: a string
  Post-conditions: a struct that contains the day, month and year of a transaction
  */
  char message[200];
  strcpy(message, initialMessage);
  struct date date;
  char input[100];
  while (true)
  {
    printf("%s",message);
    scanf("%s", input);
    if(!validateDate(input))
    {
      strcpy(message, messageForInvalidData);
    }
    else
    {
      char *pointer = strtok(input, "/");
      date.month = atoi(pointer);
      pointer = strtok(NULL, "/");
      date.day = atoi(pointer);
      pointer = strtok(NULL, "/");
      date.year = atoi(pointer);
      return date;
    }
  }
}

char* obtainDescription(char initialMessage[], char messageForInvalidData[])
{
  /*
  A function that asks the user to input a valid description for their transaction.
  Preconditions: initialMessage: a string
                messageForInvalidData
  Post-conditions: a string
  */
  char message[200];
  strcpy(message, initialMessage);
  char *description = malloc(255);
  while (true)
  {
    printf("%s",message);
    fgets(description, 255, stdin);
    strtok(description, "\n");
    if (!validateDescription(description))
      strcpy(message, messageForInvalidData);
    else
      return description;
  }
}

float obtainValue(char initialMessage[], char messageForInvalidData[])
{
  char message[200];
  strcpy(message, initialMessage);
  char value[100];
  while (true)
  {
    printf("%s",message);
    scanf("%s", value);
    if(!validateValue(value))
      strcpy(message, messageForInvalidData);
    else
      return atof(value);
  }
}

char* obtainType(char initialMessage[], char messageForInvalidData[])
{
  /*
  A function that asks the user to input the type of the transaction.
  Preconditions: initialMessage: a string
                 messageForInvalidData: a string
  Post-conditions: a string
  */
  char message[200];
  strcpy(message, initialMessage);
  char *transactionType = malloc(200);
  while (true)
  {
    printf("%s",message);
    scanf("%s", transactionType);
    if (!validateType(transactionType))
      strcpy(message, messageForInvalidData);
    else
      return transactionType;
  }
}

int max(int value1, int value2)
{
  /*
  A function that returns the max value between two integers.
  Preconditions: value1: an integer
                 value2: an integer
  Post-conditions: an integer
  */
  if (value1 > value2)
    return value1;
  return value2;
}

bool compareTwoDates(struct date date1,struct date date2)
{
  /*
  A function that compares two dates.
  Preconditions: date1: a struct that contains the day, the month and the year of a transaction
                 date2: a struct that contains the day, the month and the year of a transaction
  Post-conditions: a bool, true if the second date is bigger or equal with the first date and false otherwise
  */
  if (date1.year > date2.year)
    return false;
  if (date1.year < date2.year)
    return true;
  if (date1.month > date2.month)
    return false;
  if (date1.month < date2.month)
    return true;
  if (date1.day <= date2.day)
    return true;
  return false;
}

struct transaction obtainTransaction()
{
  /*
  A functions that asks the user to input information about a transactions.
  Preconditions: -
  Post-conditions: a struct that constains the date, the description, the value and the type of a transaction
  */
  struct transaction transaction;
  transaction.date = obtainDate("Input the date on which was the expense made. It must have this format: mm/dd/yyyy\n", "That was not a valid date, please input a valid one.\n");
  char ch = getchar();
  strcpy(transaction.description, obtainDescription("Input a description for the transaction.\n", "That was not a valid description, please input a valid one.\n"));
  transaction.value = obtainValue("What is the amount this transaction?\n", "That was not a valid value, please input a valid one.\n");
  strcpy(transaction.type, obtainType("What was the type of the transaction? (Income or Expense)\n", "That was not a valid type, please input a valid one.\n"));
  printf("The transaction was recorded successfully!\n");
  return transaction;
}

void printData(struct transaction transactions[200], int length)
{
  /*
  A function that prints all of the recorded transactions.
  Preconditions: transactions: an array with the recorded transactions
                 length: an int with the number of recorded expenses
  Post-conditions: -
  */
  for (int index = 0; index < length; index++)
  {
    printf("%d %d/%d/%d %s %f %s\n",index + 1, transactions[index].date.month, transactions[index].date.day, transactions[index].date.year, transactions[index].description, transactions[index].value, transactions[index].type);
  }
}

void displayAccountBalance(struct transaction transactions[200], int length)
{
  /*
  A function that displays the account balance.
  Preconditions: transactions: an array with all of the recorded expenses
                 length: an integer with the number of recorded expenses
  Post-conditions: -
  */
  float accountBalance = 0;
  for (int index = 0; index < length; index++)
  {
    if(!strcmp(transactions[index].type, "Income"))
      accountBalance += transactions[index].value;
    else
      accountBalance -= transactions[index].value;
  }
  printf("Your account balance is: %f\n", accountBalance);
}

void displayExpensesAndIncomes(struct transaction transactions[200], int length)
{
  /*
  A function that displays the expenses and the incomes that were made in a given time period.
  Preconditions: transactions: an array of structs that contain the date, the description, the value and the type of transactions
                 length: the number of recorded transactions in transactions
  Post-conditions: -
  */
  struct date date1;
  struct date date2;
  char messageForFirstDate[200] = "Input the starting date of the period in which your transactions were made. It must have the following format: mm/dd/yyyy.\n";
  char messageForSecondDate[200] = "Input the ending date of the period in which your transactions were made. It must have the following format: mm/dd/yyyy.\n";
  char messageForInvalidData[200] = "That was not a valid date, please input a valid one.\n";
  char messageForInvalidInterval[200] = "That starting date is smaller than the ending date, please input a valid interval.\n";
  while (true)
  {
    date1 = obtainDate(messageForFirstDate, messageForInvalidData);
    date2 = obtainDate(messageForSecondDate, messageForInvalidData);
    if (compareTwoDates(date1, date2) == false)
      printf("%s",messageForInvalidInterval);
    else
      break;
  }

  struct transaction incomes[200];
  int incomesLength = 0;
  struct transaction expenses[200];
  int expensesLength = 0;
  for (int index = 0; index < length; index++)
  {
    if (compareTwoDates(date1, transactions[index].date) && compareTwoDates(transactions[index].date, date2))
      if (!strcmp(transactions[index].type, "Income"))
      {
        incomes[incomesLength] = transactions[index];
        incomesLength++;
      }
      else
      {
        expenses[expensesLength] = transactions[index];
        expensesLength++;
      }
  }
  printf("Expenses:\n");
  printData(expenses, expensesLength);
  printf("\nIncomes:\n");
  printData(incomes, incomesLength);
}

void saveData(struct transaction transactions[200], int length)
{
  /*
  A function that saves all recorded transactions in a file.
  Preconditions: transactions: an array with all of the recorded transactions
                 length: an integer with the number of recorded transactions
  Postconditions: -
  */
  FILE *dataFile = NULL;
  dataFile = fopen("data.txt", "w");
  fprintf(dataFile, "%d\n", length);
  for (int index = 0; index < length; index++)
  {
    fprintf(dataFile, "%d/%d/%d/%f/%s/%s\n", transactions[index].date.month, transactions[index].date.day, transactions[index].date.year, transactions[index].value, transactions[index].description, transactions[index].type);
  }
  fclose(dataFile);
}

int loadData(struct transaction transactions[200])
{
  /*
  A function that loads all of the saved transactions from a file.
  Preconditions: transactions: an array in which the transaction will be loaded
  Post-conditions: an integer with the number of loaded transactions
  */
  FILE *dataFile = NULL;
  dataFile = fopen("data.txt", "r");
  int length;
  fscanf(dataFile, "%d", &length);
  for (int index = 0; index < length; index++)
  {
    char input[200];
    fscanf(dataFile, "%d/%d/%d/%f", &transactions[index].date.month, &transactions[index].date.day, &transactions[index].date.year, &transactions[index].value);
    fgets(input, 200, dataFile);
    char *pointer = strtok(input, "/");
    strcpy(transactions[index].description, pointer);
    pointer = strtok(NULL, "/");
    strtok(pointer, "\n");
    strcpy(transactions[index].type, pointer);
  }
  fclose(dataFile);
  printf("The transactions were loaded successfully!\n");
  return length;
}
