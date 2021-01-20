#include "date.h"

#include <string>
#include <stdexcept>

using namespace std;

Date::Date(unsigned int n_year, unsigned int n_month, unsigned int n_day)
{
	year = n_year;

	if (n_month > 12)
	{
		throw logic_error("Month value is invalid: " + to_string(n_month));
	}
	month = n_month;
	if (n_day > 31)
	{
		throw logic_error("Day value is invalid: " + to_string(n_day));
	}
	day = n_day;
}

unsigned int Date::GetYear() const 
{
	return year;
}
unsigned int Date::GetMonth() const 
{
	return month;
}
unsigned int Date::GetDay() const 
{
	return day;
}



