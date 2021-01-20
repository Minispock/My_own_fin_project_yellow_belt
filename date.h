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

private:
	unsigned int year, month, day;
	
};

bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);

ostream& operator<<(ostream& out, const Date& date);

Date ParseDate(istream& in);