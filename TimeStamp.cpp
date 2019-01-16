#include "TimeStamp.h"

bool TimeStamp::operator<(TimeStamp &c_time_stamp)
{
	return dTime < c_time_stamp.dTime;
}

bool TimeStamp::operator>(TimeStamp &c_time_stamp)
{
	return dTime > c_time_stamp.dTime;
}

bool TimeStamp::operator<=(TimeStamp &c_time_stamp)
{
	return dTime <= c_time_stamp.dTime;
}

bool TimeStamp::operator>=(TimeStamp &c_time_stamp)
{
	return dTime >= c_time_stamp.dTime;
}

bool TimeStamp::operator==(TimeStamp &c_time_stamp)
{
	return dTime == c_time_stamp.dTime;
}

bool TimeStamp::bSetTimeStamp(int i_year, int i_month, int i_day, int i_hour, int i_minute)
{
	if (bIsHourValid(i_hour, i_minute) && bIsDateValid(i_year, i_month, i_day))
	{
		bSetDate(i_year, i_month, i_day);
		cout << dTime << endl;
		dTime += 60 * (i_hour * 60 + i_minute);
		cout << "Time set (seconds): " << dTime << endl;
		return true;
	}
	else return false;
}

bool TimeStamp::bIsHourValid(int i_hour, int i_minute)
{
	return i_hour >= 0 && i_hour < 24 && i_minute >= 0 && i_minute < 60;
}

int TimeStamp::iMinuteDifference(TimeStamp & c_time_stamp)
{
	return abs((dTime - c_time_stamp.dTime)/60);
}

void TimeStamp::vAddHours(int i_hour)
{
	dTime += i_hour * 60 * 60;
}

int TimeStamp::iGetHour()
{
	return ((int)dTime % 86400) / (60 * 60);
}

int TimeStamp::iGetMinute()
{
	return ((int)dTime % 3600) / 60;;
}
