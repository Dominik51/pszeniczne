#include "Date.h"

Date::Date()
{
	dTime = 0;
	cout << "Konstruktor domyslny Date" << endl;
}

Date::Date(Date & c_date)
{
	dTime = c_date.dTime;
	cout << "Konstruktor kopiujacy Date" << endl;
}

bool Date::operator<(Date &c_date)
{
	return dTime < c_date.dTime;
}

bool Date::operator>(Date &c_date)
{
	return dTime > c_date.dTime;
}

bool Date::operator<=(Date &c_date)
{
	return dTime <= c_date.dTime;
}

bool Date::operator>=(Date &c_date)
{
	return dTime >= c_date.dTime;
}

bool Date::operator==(Date &c_date)
{
	return dTime == c_date.dTime;
}

bool Date::bSetDate(int i_year, int i_month, int i_day)
{
	if (bIsDateValid(i_year, i_month, i_day))
	{
		double dTimeInSeconds = (i_year - 1970) * 365 * 86400;
		cout << "before: " << dTimeInSeconds << endl;
		int iLeapDays = abs((i_year - 1972) / 4) + 1;
		if (i_year < 1972 || (i_year % 4 == 0 && i_month <= 2)) iLeapDays--;
		cout << "Leap Days: " << iLeapDays << endl;
		if (i_year >= 1970)
		{
			dTimeInSeconds += iLeapDays * 86400;
		}
		else
		{
			dTimeInSeconds -= iLeapDays * 86400;
		}
		for (int i = 1; i < i_month; i++)
		{
			dTimeInSeconds += iGetDaysOfMonth(i) * 86400;
		}
		dTimeInSeconds += i_day * 86400;
		dTime = dTimeInSeconds;
		cout << "Date set (seconds)" << dTimeInSeconds << endl;
		return true;
	}
	else return false;
	
}

int Date::iDayDifference(Date & c_date)
{
	double dTimeDifference = dTime - c_date.dTime;
	return abs(dTimeDifference / 86400);
}

void Date::vAddDays(int i_days)
{
	dTime += i_days * 86400;
}

int Date::iGetDaysOfMonth(int i_month)
{
	switch (i_month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		return 28;
		break;
	default:
		return 0;
		break;
	}
}

bool Date::bIsDateValid(int i_year, int i_month, int i_day)
{
	return i_month <= 12 && i_month > 0 && i_day > 0 && i_day <= iGetDaysOfMonth(i_month);
}
