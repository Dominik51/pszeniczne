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
	ts1.bSetTimeStamp(1970, 11, 30, 1, 0);
	ts2.bSetTimeStamp(1970, 11, 30, 1, 40);
	cout << (ts1 == ts2) << endl;
	cout << (ts1 > ts2) << endl;
	cout << (ts1 < ts2) << endl;
	cout << (ts1 >= ts2) << endl;
	cout << (ts1 <= ts2) << endl;

	cout << "Minute difference: " << ts1.iMinuteDifference(ts2);
	cout << "Days difference: " << ts1.iDayDifference(ts2);



	/*d1.vSetDate(1973, 2, 2);
	d1.vSetDate(1975, 2, 2);
	d1.vSetDate(1980, 2, 27);
	d1.vSetDate(1980, 2, 29);*/


	int a;
	cin >> a;
}