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
		int iLeapDays = iGetLeapYearsFrom1970(i_year);
	    dTimeInSeconds += iLeapDays * 86400;
		for (int i = 1; i < i_month; i++)
		{
			dTimeInSeconds += iGetLengthOfMonth(i_year, i) * 86400;
		}
		dTimeInSeconds += (i_day - 1) * 86400;
		dTime = dTimeInSeconds;
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

int Date::iGetYear()
{
	int iYear = 1970 + (dTime / (365 * 86400));
	int iLeapDays = iGetLeapYearsFrom1970(iYear);
	if (dTime < (iYear - 1970) * 365 * 86400 + iLeapDays * 86400)
	{
		iYear--;
	}
	return iYear;
}

int Date::iGetMonth()
{
	double dTimePassed = (iGetYear() - 1970) * 365 * 86400 + iGetLeapYearsFrom1970(iGetYear()) * 86400;
	int iMonth = 0;
	while (dTimePassed <= dTime)
	{
		dTimePassed += iGetLengthOfMonth(iGetYear(), ++iMonth) * 86400;
	}
	return iMonth;
}

int Date::iGetDay()
{
	double dTimePassed = (iGetYear() - 1970) * 365 * 86400 + iGetLeapYearsFrom1970(iGetYear() - 1) * 86400;
	for(int i = 1; i < iGetMonth(); i++)
	{
		dTimePassed += iGetLengthOfMonth(iGetYear(), i) * 86400;
	}
	return (dTime - dTimePassed) / 86400 + 1;
}

int Date::iGetLeapYearsFrom1970(int i_year)
{
	int iLeapYears = abs((i_year - 1969) / 4);
	return iLeapYears;
}

int Date::iGetLengthOfMonth(int i_year, int i_month)
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
		return i_year % 4 == 0 ? 29 : 28;
		break;
	default:
		return 0;
		break;
	}
}

bool Date::bIsDateValid(int i_year, int i_month, int i_day)
{
	return i_month <= 12 && i_month > 0 && i_day > 0 && i_day <= iGetLengthOfMonth(i_year, i_month);
}
