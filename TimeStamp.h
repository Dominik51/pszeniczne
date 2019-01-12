#pragma once
#include"Date.h"

class TimeStamp : public Date
{
public:

	bool operator<(TimeStamp &c_date);
	bool operator>(TimeStamp &c_date);
	bool operator<=(TimeStamp &c_date);
	bool operator>=(TimeStamp &c_date);
	bool operator==(TimeStamp &c_date);

	bool bSetTimeStamp(int i_year, int i_month, int i_day, int i_hour, int i_minute);
	bool bIsHourValid(int i_hour, int i_minute);
	int iMinuteDifference(TimeStamp & c_time_stamp);
	void vAddHours(int i_hour);

private:
	int pszeniczne;
};