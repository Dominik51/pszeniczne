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
		dTime += MINUTE_IN_SEC * (i_hour * MINUTE_IN_SEC + i_minute);
		return true;
	}
	else return false;
}

bool TimeStamp::bIsHourValid(int i_hour, int i_minute)
{
	return i_hour >= 0 && i_hour < HOURS_PER_DAY && i_minute >= 0 && i_minute < MINUTE_IN_SEC;
}

int TimeStamp::iMinuteDifference(TimeStamp & c_time_stamp)
{
	return abs((dTime - c_time_stamp.dTime)/ MINUTE_IN_SEC);
}

void TimeStamp::vAddHours(int i_hour)
{
	dTime += i_hour * HOUR_IN_SEC;
}

int TimeStamp::iGetHour()
{
	return ((int)dTime % DAY_IN_SEC) / (HOUR_IN_SEC);
}

int TimeStamp::iGetMinute()
{
	return ((int)dTime % HOUR_IN_SEC) / MINUTE_IN_SEC;;
}
