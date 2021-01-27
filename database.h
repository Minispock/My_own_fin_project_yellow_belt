#pragma once
#include "date.h"


#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;


class Database
{
public:
	void Add(const Date& date, const string& event);
	void Print(ostream& out) const;

	template <typename T>
	int RemoveIf(const T predicate);

	template <typename T>
	vector<pair<Date, string>> FindIf(const T predicate) const;
	
	string Last(Date date) const;

private:
	map<Date, set<string>> events;
};

