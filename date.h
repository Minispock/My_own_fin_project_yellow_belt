#pragma once

#include <iomanip>

using namespace std;

class Date
{
public:
	Date(unsigned int n_year, unsigned int n_month, unsigned int n_day);

	unsigned int GetYear() const;
	unsigned int GetMonth() const;
	unsigned int GetDay() const;

	bool operator<(const Date& d2) const;
	

private:
	unsigned int year, month, day;
	
};

ostream& operator<<(ostream& sstream, const Date& date)
{
	sstream << setw(4) << setfill('0') << date.GetYear() << "-"
		<< setw(2) << setfill('0') << date.GetMonth() << "-"
		<< setw(2) << setfill('0') << date.GetDay();
	return sstream;
}