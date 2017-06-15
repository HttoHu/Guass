#include"../monomial.h"
using std::string;
using namespace Htto;
string UseAndClearString(std::string & str)
{
	string ret = str;
	str = "";
	return ret;
}
bool isNumebr(const std::string & str)
{
	for (const auto & a : str)
	{
		if (!isdigit(a) || a == '.')
			return false;
	}
	return true;
}

Htto::Monomial::Monomial(std::string str)
{
	int state = 0;
	std::string front;
	std::string tp_times;
	std::string tp_name;
	for (const auto & tp : str)
	{
		if (isdigit(tp))
		{
			;
		}
		else if (isalpha(tp))
		{
			if (tp_name != "")
			{
				if (!isNumebr(tp_times))
					throw std::runtime_error("Monomial bad input");
				if (tp_times == "")
				{
					tp_times = "1";
				}
				Fraction times = Fraction(UseAndClearString(tp_times));
				std::map<string, Fraction>::iterator it = variableTable.find(tp_name);
				if (it == variableTable.end())
				{
					variableTable.insert({ UseAndClearString(tp_name),times });
				}
				else
					it->second += times;
			}
			state = 10;
		}
		else if (tp == '^')
		{
			state = 1;
			continue;
		}
		switch (state)
		{
		case 0:
			front += tp;
			break;
		case 1:
			tp_times += tp;
			break;
		case 10:
			tp_name += tp;
			break;
		default:
			break;
		}
	}
	if (tp_name != "")
	{
		if (!isNumebr(tp_times))
			throw std::runtime_error("Monomial bad input");
		if (tp_times == "")
		{
			tp_times = "1";
		}
		Fraction times = Fraction(UseAndClearString(tp_times));
		std::map<string, Fraction>::iterator it = variableTable.find(tp_name);
		if (it == variableTable.end())
		{
			variableTable.insert({ UseAndClearString(tp_name),times });
		}
		else
			it->second += times;
	}
	if (front == ""&&variableTable.size() != 0)
	{
		coef = Fraction("1");
		return;
	}
	else if (front == "-")
		front += "1";
	else if (front == "+")
		front = "1";
	coef = Fraction(front);
}

bool Htto::Monomial::operator!=(const Monomial & M) const
{
	if (coef == M.coef&&variableTable == M.variableTable)
		return false;
	else
		return true;
}

Monomial Htto::Monomial::operator*(const Monomial & M)const
{
	Monomial ret;
	ret.coef = coef*M.coef;
	ret.variableTable = variableTable;
	for (std::map<std::string, Fraction>::const_iterator it = M.variableTable.cbegin();it != M.variableTable.cend();it++)
	{
		if (ret.variableTable.find(it->first) != ret.variableTable.end())
		{
			ret.variableTable[it->first] = ret.variableTable[it->first] + it->second;
		}
		else
		{
			ret.variableTable.insert({ it->first,it->second });
		}
	}
	return ret;
}

Monomial Htto::Monomial::operator/(const Monomial & M) const
{
	Monomial ret;
	if (coef == Fraction(0))
	{
		throw std::runtime_error("a Monomial try to divided by zero.");
	}
	ret.coef = coef*(M.coef.get_reciprocal());
	ret.variableTable = variableTable;
	for (std::map<std::string, Fraction>::const_iterator it = M.variableTable.cbegin();it != M.variableTable.cend();it++)
	{
		if (ret.variableTable.find(it->first) != ret.variableTable.end())
		{
			ret.variableTable[it->first] = ret.variableTable[it->first] - it->second;
		}
		else
		{
			ret.variableTable.insert({ it->first,-(it->second) });
		}
	}
	return ret;
}

bool Htto::Monomial::operator==(const Monomial & M) const
{
	return variableTable == M.variableTable;
}

bool Htto::Monomial::operator<(const Monomial & M) const
{
	if (times() > M.times())
	{
		return true;
	}
	else if (times() == M.times())
	{
		return name() < M.name();
	}
	else
	{
		return false;
	}
}

bool Htto::Monomial::operator>(const Monomial & M) const
{
	if (!(*this < M))
		return true;
	else
		return false;
}

std::string Htto::Monomial::ToString()const
{
	std::string ret;
	if (variableTable.size() == 0)
	{
		return coef.ToString();
	}
	if (coef == Fraction(0))
	{
		return "0";
	}

	else if (coef == Fraction("-1"))
	{
		ret += "-";
	}
	else if (coef != Fraction("1"))
	{
		ret += coef.ToString();
	}
	bool haveZeroTimesVariable = false;
	int count = 0;
	for (std::map<string, Fraction>::const_iterator it = variableTable.begin();it != variableTable.end();it++)
	{
		if (it->second == Fraction("0"))
		{
			haveZeroTimesVariable = true;
			count++;
			continue;
		}
		ret += it->first;
		if (it->second != Fraction("1"))
		{
			ret += string("^") + it->second.ToString();
		}
	}
	if (haveZeroTimesVariable&&variableTable.size() == count)
	{
		ret = "1";
	}
	return ret;
}

std::string Htto::Monomial::name() const
{
	string ret;
	for (std::map<string, Fraction>::const_iterator it = variableTable.cbegin();it != variableTable.cend();it++)
	{
		ret += it->first+"^"+it->second.ToString();
	}
	return ret;
}

bool Htto::Monomial::is_like_term(const Monomial & mono1, const Monomial & mono2)
{
	return mono1.variableTable == mono2.variableTable;
}

void Htto::Monomial::simplifiction()
{
	std::map<string, Fraction> ::iterator it1, it2;
	if (variableTable.size() < 2)
		return;
	it1 = variableTable.begin();
	it2 = it1;
	while (it2 != variableTable.end())
	{
		if (it1->second == Fraction(0))
		{
			it2++;
			variableTable.erase(it1);
			it1 = it2;
		}
		else
			it1 = ++it2;
	}
}

Fraction Htto::Monomial::times()const
{
	Fraction ret = 0;
	Monomial  tp = *this;
	tp.simplifiction();
	for (const auto & a : tp.variableTable)
	{
		//std::cout << a.second.ToString() << std::endl;
		ret = ret + a.second;
	}
	return ret;
}
#ifdef CONSOLE_DEBUG
std::map<std::string, Fraction> Htto::Monomial::debug() const
{
	return variableTable;
}
#endif
Monomial  Htto::operator-(Monomial  fra)
{
	fra.coef = -fra.coef;
	return fra;
}
