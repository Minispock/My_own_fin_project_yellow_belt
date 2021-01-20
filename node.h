#pragma once
#include "date.h"

#include <string>
#include <memory>

using namespace std;

enum class Comparison
{
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

enum class LogicalOperation 
{
	Or,
	And
};

class Node
{
public:
	Node() = default;
	virtual bool Evaluate(const Date& date, const string& event) = 0;
	virtual ~Node() = default;
};

class DateComparisonNode : public Node 
{
public:
	DateComparisonNode() = default;
	DateComparisonNode(const Comparison& cmp, const Date& date);
	bool Evaluate(const Date& date, const string& event) override;
};

class EventComparisonNode : public Node
{
public:
	EventComparisonNode() = default;
	EventComparisonNode(const Comparison& cmp, const string& event);
	bool Evaluate(const Date& date, const string& event) override;
};

class LogicalOperationNode : public Node
{
public:

	LogicalOperationNode() = default;
	LogicalOperationNode(const LogicalOperation& logical_operation, const shared_ptr<Node>& left, const shared_ptr<Node>& right);
	bool Evaluate(const Date& date, const string& event) override;
};

class EmptyNode : public Node
{
public:
	EmptyNode() = default;
	bool Evaluate(const Date& date, const string& event) override;
};