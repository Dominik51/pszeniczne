#include "Date.h"
#include "TimeStamp.h"
#include <iostream>

using namespace std;

int main()
{
	Date d1;
	Date d2;
	cout << (d1 == d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 <= d2) << endl;

	cout << " ================= " << endl; 
	d1.bSetDate(1970, 11, 30);
	TimeStamp ts1;
	TimeStamp ts2;
	ts1.bSetTimeStamp(1970, 11, 30, 23, 25);
	ts2.bSetTimeStamp(1970, 11, 30, 15, 03);
	cout << (ts1 == ts2) << endl;
	cout << (ts1 > ts2) << endl;
	cout << (ts1 < ts2) << endl;
	cout << (ts1 >= ts2) << endl;
	cout << (ts1 <= ts2) << endl;

	cout << "t1: " << ts1.iGetYear() << " : " << ts1.iGetMonth() << " : " << ts1.iGetDay() << " : " << ts1.iGetHour() << " : " << ts1.iGetMinute() << endl;
	cout << "t2: " << ts2.iGetYear() << " : " << ts2.iGetMonth() << " : " << ts2.iGetDay() << " : " << ts2.iGetHour() << " : " << ts2.iGetMinute() << endl;


	cout << "Minute difference: " << ts1.iMinuteDifference(ts2);
	cout << "Days difference: " << ts1.iDayDifference(ts2);



	d1.bSetDate(1970, 3, 1);
	cout << d1.iGetYear() << "____________________________" << d1.iGetMonth() << "  :  " << d1.iGetDay() << endl;
	d1.bSetDate(1972, 02, 29);
	cout << d1.iGetYear() << "____________________________" << d1.iGetMonth() << "  :  " << d1.iGetDay() << endl;
	d1.bSetDate(2003, 12, 31);
	cout << d1.iGetYear() << "____________________________" << d1.iGetMonth() << "  :  " << d1.iGetDay() << endl;
	d1.bSetDate(1970, 3, 1);
	cout << d1.iGetYear() << "____________________________" << d1.iGetMonth() << "  :  " << d1.iGetDay() << endl;
	d1.bSetDate(1970, 3, 1);
	cout << d1.iGetYear() << "____________________________" << d1.iGetMonth() << "  :  " << d1.iGetDay() << endl;
	/*
	d1.vSetDate(1975, 2, 2);
	d1.vSetDate(1980, 2, 27);
	d1.vSetDate(1980, 2, 29);*/


	int a;
	cin >> a;
}