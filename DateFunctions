#include <iostream>
#include <string>

using namespace std;

// Function prototypes
int getMonthInt(string);
int getDayInt(string);
int getYearInt(string);
string getDateString(int, int, int);

// These functions assume dateStr input is MM/DD/YYYY or MM-DD-YYYY

// Accepts the date string and returns the month as an int
int getMonthInt(string dateStr)
{
  string monthStr;
  int monthInt;
  
  monthStr = dateStr.substr(0, 2);
	monthInt = stoi(monthStr);
	
	return monthInt;
}

// Accepts the date string and returns the day as an int
int getDayInt(string dateStr)
{
  string dayStr;
  int dayInt;
  
  dayStr = dateStr.substr(3, 2);
	dayInt = stoi(dayStr);
	
	return dayInt;
}

// Accepts the date string and returns the year as an int
int getYearInt(string dateStr)
{
  string yearStr;
  int yearInt;
  
  yearStr = dateStr.substr(6, 4);
	year = stoi(yearStr);
	
	return yearInt;
}

// Accepts the month, day, and year as ints and returns
// a string as "YYYY-MM-DD"
string getDateString(int, int, int)
{

	string yearStr = to_string(year);
	string monthStr = to_string(month);
	string dayStr = to_string(day);

	string dateString = yearStr + "-" + monthStr + "-" + dayStr;

	return dateString;
}
