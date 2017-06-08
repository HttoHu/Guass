#include "..\HPP\Count.h"
#include "..\HPP\BalanceStack.h"
#include <stdlib.h>
using namespace Htto::Count;
void string_replace(std::string&s1, const std::string&s2, const std::string&s3)
{
	using std::string;
	string::size_type pos = 0;
	string::size_type a = s2.size();
	string::size_type b = s3.size();
	while ((pos = s1.find(s2, pos)) != string::npos)
	{
		s1.replace(pos, a, s3);
		pos += b;
	}
}
float StringToFloat(std::string str)
{
	float i;
	i = atof(str.c_str());
	return i;
}
unit Push_unit(int & index, std::string input)
{
	unit ret;
	if (index > input.size())
		throw std::out_of_range("stringTools.cpp->get_number_end_index: index too large");
	if (Htto::StringTools::isSingleNumber(input[index]))
	{
		ret.numData = StringToFloat(Htto::StringTools::get_number_by_index(input, index));
		ret.priority = 0;
		ret.isNumber = true;
		ret.strData = "";
		index = Htto::StringTools::get_end_index(input, index);
		return ret;
	}
	else if (input[index] == '+' || input[index] == '-')
	{
		ret.strData = input[index] + std::string();
		ret.priority = 1;
		ret.isNumber = false;
	}
	else if (input[index] == '*' || input[index] == '/')
	{
		ret.strData = input[index] + std::string();
		ret.priority = 2;
		ret.isNumber = false;
	}
	else if (input[index] == '@' || input[index] == '^')
	{
		ret.strData = input[index] + std::string();
		ret.priority = 3;
		ret.isNumber = false;
	}
	else if (input[index] == '(')
	{
		ret.strData = input[index] + std::string();
		ret.priority = -5;
		ret.isNumber = false;
	}
	else if (input[index] == ')')
	{
		ret.strData = input[index] + std::string();
		ret.priority = 100;
		ret.isNumber = false;
	}
	index++;
	return ret;
}
std::list <unit> Simple_Count::PushToList(std::string input)
{
	std::list<unit> ret;
	string_replace(input, "@", std::string() + '@');
	int index = 0;
	while (index < input.size())
	{
		ret.push_back(Push_unit(index, input));
	}
	return ret;
}
std::list<unit> Simple_Count::InfixToPostfix(std::list<unit>& ExpStream)
{
	std::list<unit> output;
	std::stack<unit> Stack;
	for (auto & index : ExpStream)
	{
		if (index.priority == 0)
		{
			output.push_back(index);
		}
		else if (Stack.empty())
		{
			Stack.push(index);
		}
		else if (index.strData == "(")
		{
			Stack.push(index);
		}
		else if (index.strData == ")")
		{
			while (!Stack.empty() && Stack.top().strData != "(")
			{
				output.push_back(Stack.top());
				Stack.pop();
			}
			if (!Stack.empty())
				Stack.pop();
		}
		else
		{
			while (!Stack.empty() && index.priority <= Stack.top().priority)
			{
				output.push_back(Stack.top());
				Stack.pop();
			}
			Stack.push(index);
		}
	}
	while (!Stack.empty())
	{
		output.push_back(Stack.top());
		Stack.pop();
	}
	return output;
}
Htto::Fraction Simple_Count::GetCountResult(const std::list<unit>& exp)
{
	Htto::Fraction ret;
	Htto::Fraction tp1;
	Htto::Fraction tp2;
	std::stack<Htto::Fraction> Stack;
	for (const auto & a : exp)
	{
		if (a.isNumber)
		{
			Stack.push(Htto::Fraction(std::to_string(a.numData)));
		}
		else
		{
			if (a.strData == "+")
			{
				tp2 = Stack.top();
				Stack.pop();
				tp1 = Stack.top();
				Stack.pop();

				Stack.push(tp1 + tp2);
			}
			else if (a.strData == "-")
			{
				tp2 = Stack.top();
				Stack.pop();
				tp1 = Stack.top();
				Stack.pop();

				Stack.push(tp1 - tp2);
			}
			else if (a.strData == "*")
			{
				tp2 = Stack.top();
				Stack.pop();
				tp1 = Stack.top();
				Stack.pop();

				Stack.push(tp1 * tp2);
			}
			else if (a.strData == "/")
			{
				tp2 = Stack.top();
				Stack.pop();
				tp1 = Stack.top();
				Stack.pop();
				Stack.push(tp1 / tp2);
			}
			else if (a.strData == "@")
			{
				Stack.top().numsqrt();
			}
			else if (a.strData == "^")
			{
				int tp3 = Stack.top();
				Stack.pop();
				tp1 = Stack.top();
				Stack.pop();
				tp1 = Htto::Handle::Pow(tp1, tp3);
				Stack.push(tp1);
			}
		}
	}
	return Stack.top();
}
Htto::Fraction Simple_Count::Count(const std::string str)
{
	Htto::BalanceStack bs(str);
	if (!bs.checkBalance())
	{
		throw std::runtime_error("str is bad try to reput");
	}
	std::list<unit> x1 = PushToList(str);
	x1 = InfixToPostfix(x1);
	return GetCountResult(x1);
}
