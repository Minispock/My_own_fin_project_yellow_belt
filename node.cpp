#include "node.h"


using namespace std;

DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date)
	:m_cmp(cmp), m_date(date) {};

bool DateComparisonNode::Evaluate(const Date& date, const string& event) 
{
	switch (m_cmp)
	{
	case Comparison::Less:
		return m_date > date;
	case Comparison::LessOrEqual:
		return m_date >= date;
	case Comparison::Greater:
		return m_date < date;
	case Comparison::GreaterOrEqual:
		return m_date <= date;
	case Comparison::Equal: 
		return m_date == date;
	case Comparison::NotEqual:
		return m_date != date;
	default:
		return false;
	}

	return false;
}

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const string& event)
	:m_cmp(cmp), m_event(event) {};

bool EventComparisonNode::Evaluate(const Date& date, const string& event) 
{
	switch (m_cmp)
	{
	case Comparison::Less:
		return m_event > event;
	case Comparison::LessOrEqual:
		return m_event >= event;
	case Comparison::Greater:
		return m_event < event;
	case Comparison::GreaterOrEqual:
		return m_event <= event;
	case Comparison::Equal:
		return m_event == event;
	case Comparison::NotEqual:
		return m_event != event;
	default:
		return false;
	}
	return false;
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& logical_operation, const shared_ptr<Node>& left, const shared_ptr<Node>& right)
	:m_logical_operation(logical_operation), m_left(left), m_right(right) {};

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) 
{
	switch (m_logical_operation)
	{
	case LogicalOperation::Or:
		return m_left->Evaluate(date, event) || m_right->Evaluate(date, event);
	case LogicalOperation::And:
		return m_left->Evaluate(date, event) && m_right->Evaluate(date, event);
	default:
		return false;
	}
	return false;
}

bool EmptyNode::Evaluate(const Date& date, const string& event) 
{
	return true;
}