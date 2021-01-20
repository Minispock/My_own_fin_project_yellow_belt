#pragma once
#include "date.h"


#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class Database
{
public:

	const map<Date, set<string>>& GetEvents() const;

	void AddEvent(const Date& date, const string& event);

	void Print() const;

	const set<string>& Find(const string condition) const;

	bool Delete(string condition);

	map<Date, set<string>> Last(Date date) const;

private:
	map<Date, set<string>> events;
};

void EnsureNextCharAndSkip(stringstream& s, const string& date)
{
	if (s.peek() != '-')
	{
		throw logic_error("Wrong date format: " + date);
	}
	s.ignore(1);
}

Date ParseDate(const string& date)
{
	stringstream date_stream(date);
	unsigned int year, month, day;
	if (date_stream.peek() == '-')
	{
		date_stream.get();//read the first symbol and continue program	
	}
	date_stream >> year;
	EnsureNextCharAndSkip(date_stream, date);
	date_stream >> month;
	EnsureNextCharAndSkip(date_stream, date);
	date_stream >> day;
	if (!date_stream.eof() || !date_stream)
	{
		throw logic_error("Wrong date format: " + date);
	}
	return { year, month, day };
}

//standar output operators don't have defenitions for constant streams. P.S. Getted const parameter can not be changed in the function body
//The overloads of operator>> and operator<< that take a std::istream& or std::ostream& as the left hand argument are known 
//as insertion and extraction operators. Since they take the user-defined type as the right argument (b in a@b), they must be implemented as non-members.
ostream& operator<<(ostream& sstream, const Date& date)
{
	sstream << setw(4) << setfill('0') << date.GetYear() << "-"
		<< setw(2) << setfill('0') << date.GetMonth() << "-"
		<< setw(2) << setfill('0') << date.GetDay();
	return sstream;
}

ostream& operator<<(ostream& stream, Database datebase)
{
	for (const auto& item : datebase.GetEvents())
	{
		for (const auto& event : item.second)
		{
			stream << item.first << " " << event << endl;
		}
	}
	return stream;
}