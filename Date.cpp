#include "Date.h"

Date::Date()
{
	dTime = 0;
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
		double dTimeInSeconds = (i_year - START_YEAR) * DAYS_PER_YEAR * DAY_IN_SEC;
		int iLeapDays = iGetLeapYearsFrom1970(i_year);
	    dTimeInSeconds += iLeapDays * DAY_IN_SEC;
		for (int i = 1; i < i_month; i++)
		{
			dTimeInSeconds += iGetLengthOfMonth(i_year, i) * DAY_IN_SEC;
		}
		dTimeInSeconds += (i_day - 1) * DAY_IN_SEC;
		dTime = dTimeInSeconds;
		return true;
	}
	else return false;
	
}

int Date::iDayDifference(Date & c_date)
{
	double dTimeDifference = dTime - c_date.dTime;
	return abs(dTimeDifference / DAY_IN_SEC);
}

void Date::vAddDays(int i_days)
{
	dTime += i_days * DAY_IN_SEC;
}

int Date::iGetYear()
{
	int iYear = START_YEAR + (dTime / (DAYS_PER_YEAR * DAY_IN_SEC));
	int iLeapDays = iGetLeapYearsFrom1970(iYear);
	if (dTime < (iYear - START_YEAR) * DAYS_PER_YEAR * DAY_IN_SEC + iLeapDays * DAY_IN_SEC)
	{
		iYear--;
	}
	return iYear;
}

int Date::iGetMonth()
{
	double dTimePassed = (iGetYear() - START_YEAR) * DAYS_PER_YEAR * DAY_IN_SEC + iGetLeapYearsFrom1970(iGetYear()) * DAY_IN_SEC;
	int iMonth = 0;
	while (dTimePassed <= dTime)
	{
		dTimePassed += iGetLengthOfMonth(iGetYear(), ++iMonth) * DAY_IN_SEC;
	}
	return iMonth;
}

int Date::iGetDay()
{
	double dTimePassed = (iGetYear() - START_YEAR) * DAYS_PER_YEAR * DAY_IN_SEC + iGetLeapYearsFrom1970(iGetYear()) * DAY_IN_SEC;
	for(int i = 1; i < iGetMonth(); i++)
	{
		dTimePassed += iGetLengthOfMonth(iGetYear(), i) * DAY_IN_SEC;
	}
	cout << dTime << " : " << dTimePassed << endl;
	return (dTime - dTimePassed) / DAY_IN_SEC + 1;
}

int Date::iGetLeapYearsFrom1970(int i_year)
{
	int iLeapYears = abs((i_year - START_YEAR - 1) / 4);
	return iLeapYears;
}

int Date::iGetLengthOfMonth(int i_year, int i_month)
{
	switch (i_month)
	{
	case JANUARY:
		return JANUARY_LENGTH;
	case FEBRUARY:
		return i_year % YEARS_PER_LEAP_YEARS == 0 ? FEBRUARY_LEAP_LENGTH : FEBRUARY_LENGTH;
	case MARCH:
		return MARCH_LENGTH;
	case APRIL:
		return APRIL_LENGTH;
	case MAY:
		return MAY_LENGTH;
	case JUNE: 
		return JUNE_LENGTH;
	case JULY:
		return JULY_LENGTH;
	case AUGUST:
		return AUGUST_LENGTH;
	case SEPTEMBER:
		return SEPTEMBER_LENGTH;
	case OCTOBER:
		return OCTOBER_LENGTH;
	case NOVEMBER:
		return NOVEMBER_LENGTH;
	case DECEMBER:
		return DECEMBER_LENGTH;
	default:
		return 0;
	}
}

bool Date::bIsDateValid(int i_year, int i_month, int i_day)
{
	return  i_month > 0 && i_month <= MONTHS_PER_YEAR && i_day > 0 && i_day <= iGetLengthOfMonth(i_year, i_month);
}
