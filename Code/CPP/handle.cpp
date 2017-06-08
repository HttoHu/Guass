#include "../handle.h"
#include <iostream>
#include <cctype>
//获得最大公因数
int Htto::Handle::INT_GCD(int n, int m)
{
	if (n < m)
	{
		int temp;
		temp = n;
		n = m;
		m = temp;
	}
	if (m == 0)
		return 1;
	while (n%m)
	{
		int r = n%m;
		n = m;
		m = r;
	}
	return m;
}
//获得最大因子(未优化)
int Htto::Handle::INT_MAX_FACTOR(int n)
{
	if (n < 1)
		return 1;

	for (int i = n - 1;i > 0;i--)
	{
		if (!(n%i))
			return i;
	}
	return 1;
}
bool Htto::Handle::isEqual(int n, float f)
{
	if ((float)n == f)
		return true;
	else
		return false;
}
//====================== TAB AA4  (class) StringTools=========================
int Htto::StringTools::isSingleNumber(char ch)
{
	if (ch >= 48 && ch <= 57)
		return 1;
	else if (ch == '.')
		return -1;
	else
		return 0;
}

int STgetCharValue(char ch)
{
	if (ch == '(')
		return 1;
	else if (ch == ')')
		return -1;
	else if (ch == '[')
		return 2;
	else if (ch == ']')
		return -2;
	else
		return 0;
}
bool Htto::StringTools::isNumber_int(std::string str)
{
	for (size_t i = 0;i < str.size();i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
			continue;
		else
			return false;
	}
	return true;
}
bool Htto::StringTools::isNumber(std::string str)
{
	for (size_t i = 0;i < str.size();i++)
	{
		if ((str[i] >= 48 && str[i] <= 57) || str[i] == '.')
			continue;
		else
			return false;
	}
	int count = 0;
	for (auto a : str)
	{
		if (a == '.')
			count++;
	}
	if (count > 1)
		return false;
	return true;
}
std::string Htto::StringTools::get_rid_of_parentheses(std::string parameter)
{
	std::string ret;
	int state = 0;
	unsigned index = 0;
	for (;index < parameter.size();index++)
	{
		state += STgetCharValue(parameter[index]);
		if (state == 0 && parameter[index] != ')')
		{
			ret += parameter[index];
		}
		else
		{
			continue;
		}
	}
	return ret;
}
std::string Htto::StringTools::get_parentheses_model(std::string parameter)
{
	std::string ret;
	unsigned index = 0;
	int nindex = 0;
	int lastState = 0;
	int state = 0;
	for (;index < parameter.size();index++)
	{
		lastState = state;
		state += STgetCharValue(parameter[index]);
		if (lastState - state == 0)
		{
			if (state < lastState)
				++nindex;
		}
		else
		{
			ret += parameter[index];
			continue;
		}
	}
	return ret;
}

std::string Htto::StringTools::get_match_content(std::string parameter, int n)
{
	std::string rv;
	int state = 0;
	int lastState = 0;
	unsigned index = 0;
	int nindex = 1;
	for (;index < parameter.size();index++)
	{
		lastState = state;
		state += STgetCharValue(parameter[index]);

		if (lastState != state&&lastState > state&&lastState < 2)
		{
			if (nindex++ == n)
			{
				break;
			}
		}
		else if (lastState != 0)
		{
			if (nindex == n)
				rv += parameter[index];
		}
	}
	return rv;
}

int Htto::StringTools::get_end_index(std::string str, unsigned index)
{
	if (index >= str.size())
		throw std::out_of_range("stringTools.cpp->get_number_end_index: index too large");
	int endPos = index;
	while (isSingleNumber(str[endPos]))
	{
		if (endPos != str.size())
			++endPos;
		else
			break;
	}
	return endPos;
}

std::string Htto::StringTools::get_number_by_index(std::string str, unsigned index)
{
	if (index >= str.size())
		throw std::out_of_range("stringTools.cpp->get_number_end_index: index too large");
	int endPos = index;
	while (isSingleNumber(str[endPos]))
	{
		if (endPos != str.size())
			++endPos;
		else
			break;
	}
	return str.substr(index, endPos);
}

float Htto::StringTools::string_to_float(std::string str)
{
	bool isN = ((str[0] == '-')||(str[0]=='+'));
	int frontPart = 0;
	int tv = 1;
	int index = 0;
	if (isN)
	{ 
		index++;
	}

	for (const auto & a : str)
	{
		if (std::isdigit(a) || a == '.' || a == '-'||a=='+')
			continue;
		else
			throw std::runtime_error("error input" + str + " string_to_float is a bad input");
	}
	while (index != str.size() && str[index] != '.')
	{
		frontPart = frontPart * 10 + (str[index] - 48);
		index++;
	}
	if (index == str.size())
		if (isN&&str[0]=='-')
			return -(float)frontPart;
		return (float)frontPart;
	index++;
	float ret = (float)frontPart;
	tv = 1;
	while (index != str.size())
	{
		tv *= 10;
		ret += (float)(str[index++] - 48) / (float)tv;
	}
	if (isN)
		return -ret;
	return ret;
}

