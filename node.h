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
	virtual bool Evaluate(const Date& date, const string& event) = 0;
};

class DateComparisonNode : public Node 
{
public:
	bool Evaluate(const Date& date, const string& event) override;
};

class EventComparisonNode : public Node
{
public:
	bool Evaluate(const Date& date, const string& event) override;
};

class LogicalOperationNode : public Node
{
public:
	bool Evaluate(const Date& date, const string& event) override;
};

class EmptyNode : public Node
{
public:
	bool Evaluate(const Date& date, const string& event) override;
};