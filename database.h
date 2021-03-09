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
	
	string Last(const Date& date) const;

private:
	map<Date, vector<string>> events;
};

template <typename T>
vector<pair<Date, string>> Database::FindIf(const T predicate) const
{
	vector<pair<Date, string>> result;

	for (auto& e : events) 
	{
		for (size_t i = 0; i < e.second.size(); i++)
		{
			if (predicate(e.first, e.second[i]))
			{
				result.push_back(make_pair(e.first, e.second[i]));
			}
		}
	}

	return result;
}

template <typename T>
int Database::RemoveIf(const T predicate)
{
	int count = 0;

	for (auto& ev : events)
	{
		for (auto it = ev.second.begin(); it != ev.second.end();)
		{
			if (predicate(ev.first, *it))
			{
				count++;
				it = ev.second.erase(it);						
			}
			else
			{
				++it;
			}
		}		
	}

	for (auto data_it = events.begin(); data_it != events.end();)
	{
		if (data_it->second.size() == 0)
		{
			data_it = events.erase(data_it);
		}
		else
		{
			++data_it;
		}
	}
	
	return count;
}
