#pragma once
#include <iostream>

using namespace std;

const int START_YEAR = 1970;

const int MINUTE_IN_SEC = 60;
const int HOUR_IN_SEC = MINUTE_IN_SEC * 60;
const int DAY_IN_SEC = HOUR_IN_SEC * 24;

const int DAYS_PER_YEAR = 365;
const int DAYS_PER_LEAP_YEAR = 366;
const int MONTHS_PER_YEAR = 12;
const int HOURS_PER_DAY = 24;

const int JANUARY_LENGTH = 31;
const int FEBRUARY_LENGTH = 28;
const int FEBRUARY_LEAP_LENGTH = 29;
const int MARCH_LENGTH = 31;
const int APRIL_LENGTH = 30;
const int MAY_LENGTH = 31;
const int JUNE_LENGTH = 30;
const int JULY_LENGTH = 31;
const int AUGUST_LENGTH = 31;
const int SEPTEMBER_LENGTH = 30;
const int OCTOBER_LENGTH = 31;
const int NOVEMBER_LENGTH = 30;
const int DECEMBER_LENGTH = 31;

const int JANUARY = 1;
const int FEBRUARY = 2;
const int MARCH = 3;
const int APRIL = 4;
const int MAY= 5;
const int JUNE = 6;
const int JULY = 7;
const int AUGUST = 8;
const int SEPTEMBER = 9;
const int OCTOBER = 10;
const int NOVEMBER = 11;
const int DECEMBER = 12;

const int YEARS_PER_LEAP_YEARS = 4;

class Date
{
public:
	Date();

	bool operator<(Date &c_date);
	bool operator>(Date &c_date);
	bool operator<=(Date &c_date);
	bool operator>=(Date &c_date);
	bool operator==(Date &c_date);

	bool bSetDate(int i_year, int i_month, int i_day);
	int iDayDifference(Date &c_date);
	void vAddDays(int i_days);
	
	int iGetYear();
	int iGetMonth();
	int iGetDay();

protected:

	int iGetLeapYearsFromStartYear(int i_year);
	int iGetPreviousLeapYear(int i_year);
	int iGetLengthOfMonth(int i_year, int i_month);
	bool bIsDateValid(int i_year, int i_month, int i_day);
	double dTime; // seconds
};