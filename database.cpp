#include "database.h"




using namespace std;

void Database::Add(const Date& date, const string& event)
{
	events[date].insert(event);
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