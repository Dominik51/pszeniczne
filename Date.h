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
protected:
	int iGetDaysOfMonth(int i_month);
	bool bIsDateValid(int i_year, int i_month, int i_day);
	double dTime; // seconds
};