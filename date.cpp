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

bool operator<(const Date& lhs, const Date& rhs) 
{
	if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() == rhs.GetMonth())
		{
			return lhs.GetDay() < rhs.GetDay();
		}

		return lhs.GetMonth() < rhs.GetMonth();
	}

	return lhs.GetYear() < rhs.GetYear();
}

bool operator<=(const Date& lhs, const Date& rhs) 
{
	if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() == rhs.GetMonth())
		{
			return lhs.GetDay() <= rhs.GetDay();
		}

		return lhs.GetMonth() < rhs.GetMonth();
	}

	return lhs.GetYear() < rhs.GetYear();
}

bool operator==(const Date& lhs, const Date& rhs) 
{
	return lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay();
}


bool operator!=(const Date& lhs, const Date& rhs) 
{
	return lhs.GetYear() != rhs.GetYear() || lhs.GetMonth() != rhs.GetMonth() || lhs.GetDay() != rhs.GetDay();
}

bool operator>(const Date& lhs, const Date& rhs) 
{
	if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() == rhs.GetMonth())
		{
			return lhs.GetDay() > rhs.GetDay();
		}

		return lhs.GetMonth() > rhs.GetMonth();
	}

	return lhs.GetYear() > rhs.GetYear();
}

bool operator>=(const Date& lhs, const Date& rhs) 
{
	if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() == rhs.GetMonth())
		{
			return lhs.GetDay() >= rhs.GetDay();
		}

		return lhs.GetMonth() > rhs.GetMonth();
	}

	return lhs.GetYear() > rhs.GetYear();
}

ostream& operator<<(ostream& out, const Date& date) 
{
	out << setw(4) << setfill('0') << date.GetYear() << "-"
		<< setw(2) << setfill('0') << date.GetMonth() << "-"
		<< setw(2) << setfill('0') << date.GetDay();
	return out;
}

Date ParseDate(istream& in) 
{
	unsigned int year, month, day;
	if (in.peek() == '-')
	{
		in.get();	
	}
	in >> year;
	EnsureNextCharAndSkip(in);
	in >> month;
	EnsureNextCharAndSkip(in);
	in >> day;
	if (!in.eof() || !in)
	{
		throw logic_error("Wrong date format");
	}
	return { year, month, day };
}

void EnsureNextCharAndSkip(istream& s)
{
	if (s.peek() != '-')
	{
		throw logic_error("Wrong date format");
	}
	s.ignore(1);
}