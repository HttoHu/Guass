#include "../rational_fraction.h"

Htto::Rational_fraction::Rational_fraction(const std::string & str)
{
	std::string tempStr;
	int state = 0;
	bool state2 = 0;
	int pos = 0;
	for (const auto & a : str)
	{
		if (a == '/')
		{
			state2 = true;
		}
		if (a == '(')
		{
			state = 12;
			continue;
		}
		else if (a == ')')
		{ 
			state = 13;
		}
		else if (state == 13 && a == '/')
		{
			pos = 1;
			state = 12;
			continue;
		}
		else if (state2&&state == 12)
		{
			m_molecular = Polynomial(tempStr);
			tempStr == "";
		}
		switch (state)
		{
		case 0:
			tempStr += a;
			break;
		case 12:
			tempStr += a;
			break;
		case 13:
			if (pos == 0)
			{
				m_molecular = Polynomial(tempStr);
				tempStr = "";
			}
			else if (pos == 1)
			{
				m_denomilator = Polynomial(tempStr);
				tempStr = "";
			}
			else
				throw std::runtime_error("rational_fraction: bad input too many '/' .");
			break;
		default:
			break;
		}
	}
	if (state == 0)
	{
		m_molecular = Polynomial(tempStr);
		m_denomilator = Polynomial("1");
	}
	else if (state == 12)
	{
		m_denomilator = Polynomial(tempStr);
	}
}

std::string Htto::Rational_fraction::ToString()
{
	if (m_denomilator.ToString() == "1")
		return m_molecular.ToString();
	return "(" + m_molecular.ToString() + std::string(")/(") + m_denomilator.ToString() + ")";
}

void Htto::Rational_fraction::debug()
{
	std::cout << "rational_fraction debug msg:\n";
	std::cout << m_molecular.ToString()<<std::endl;
	std::cout << m_denomilator.ToString() << std::endl;
}
