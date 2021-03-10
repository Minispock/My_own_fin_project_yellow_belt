#include "database.h"

#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <string>

using namespace std;

void Database::Add(const Date& date, const string& event)
{
	if (events.count(date))
	{
		for (auto ev: events)
		{
			for (auto it = ev.second.begin(); it != ev.second.end(); it ++)
			{
				if (*it != event)
				{
					events[date].push_back(event);
				}
			}
		}
	}
	else
	{
		events[date].push_back(event);
	}
}

void Database::Print(ostream& out) const
{
	for (const auto& event : events)
	{
		for (auto e : event.second)
		{
			out << event.first << " " << e << endl;
		}
	}
}

string Database::Last(const Date& date) const
{
	stringstream ss;

	auto it = events.upper_bound(date);
	if (it == events.begin())
	{
		return "No entries";
	}

	ss << (--it)->first << ' ' << it->second.back();

	return ss.str();
}