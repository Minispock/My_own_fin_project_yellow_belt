#include "database.h"




using namespace std;

void Database::Add(const Date& date, const string& event) 
{
	if (date.GetDay() > 0 && date.GetMonth() > 0)
	{
		events[date].insert(event);
	}
}

void Database::Print(ostream& out) const
{
	for  (const auto& event : events)
	{
		if (event.second.size() > 0)
		{
			for (auto e : event.second) 
			{
				out << event.first << " " << e << endl;
			}
		}		
	}	
}