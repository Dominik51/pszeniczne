#pragma once
#include <iostream>

using namespace std;

class Date
{
public:
	Date();
	Date(Date & c_date);

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

	int iGetLeapYearsFrom1970(int i_year);
	int iGetLengthOfMonth(int i_year, int i_month);
	bool bIsDateValid(int i_year, int i_month, int i_day);
	double dTime; // seconds
};