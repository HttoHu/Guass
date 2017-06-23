#include "../rational_fraction.h"
using namespace Htto;

std::string Htto::Rational_fraction::ToString()
{
	if (m_denomilator.ToString() == "1")
		return m_molecular.ToString();
	return "(" + m_molecular.ToString() + std::string(")/(") + m_denomilator.ToString() + ")";
}

Rational_fraction Htto::Rational_fraction::get_reciprocal() const
{
	Rational_fraction ret = *this;
	std::swap(ret.m_denomilator, ret.m_molecular);
	if (ret.m_denomilator = Polynomial("0"))
		throw std::runtime_error("Ration_fraction::<public>get_reciprocal m_denomoilator is zero.");
}

Rational_fraction Htto::Rational_fraction::operator+(const Rational_fraction & r_fraction)const
{
	Polynomial den = m_denomilator*r_fraction.m_denomilator;
	Rational_fraction ret;
	ret.m_denomilator = den;
	ret.m_molecular = (m_molecular*den) + (r_fraction.m_molecular*den);
	ret.simplifaction();
	return ret;
}
Rational_fraction Htto::Rational_fraction::operator-(const Rational_fraction &r_fraction) const
{
	Polynomial den = m_denomilator*r_fraction.m_denomilator;
	Rational_fraction ret;
	ret.m_denomilator = den;
	ret.m_molecular = (m_molecular*den) - (r_fraction.m_molecular*den);
	ret.simplifaction();
}
Rational_fraction Htto::Rational_fraction::operator*(const Rational_fraction & r_fraction) const
{
	Rational_fraction ret;
	ret.m_denomilator = r_fraction.m_denomilator;
	ret.m_molecular = r_fraction.m_molecular;
	ret.simplifaction();
	return ret;
}
Rational_fraction Htto::Rational_fraction::operator/(const Rational_fraction & r_fraction) const
{
	Rational_fraction ret = (*this)*r_fraction.get_reciprocal();
	return ret;
}
#ifdef CONSOLE_DEBUG
void Htto::Rational_fraction::simplifaction()
{
	std::vector<Polynomial> vec = Count::factorization::factoring(m_denomilator);
	std::vector<Polynomial> vec2 = Count::factorization::factoring(m_molecular);
	if (vec.size() == 1 && vec2.size() == 1)
	{
		m_molecular =m_molecular/m_denomilator;
		m_molecular.get_rid_of_zero_monomial();
		m_denomilator = Polynomial("1");
		for (size_t i = 0;i < m_molecular.data.size();i++)
		{
			auto & a = m_molecular[i];
			if (a.times() < Fraction(0))
			{
				m_denomilator.data.push_back(-a);
				m_molecular.data.erase(m_molecular.data.begin() + i);
				i--;
			}
		}
		return;
	}
	else
	{
		for (size_t i=0;i<vec.size();i++)
			for (size_t j = 0;j < vec2.size();j++)
			{
				if (vec[i] == vec2[j])
				{
					vec.erase(vec.begin() + i);
					vec2.erase(vec2.begin() + j);
					if (i != 0 && j != 0)
					{
						j--;i--;
					}
				}
			}
	}
	m_denomilator = Polynomial("1");
	m_molecular = Polynomial("1");
	for (const auto &a: vec)
	{
		m_denomilator *= a;
	}
	for (const auto & a : vec2)
	{
		m_molecular *= a;
	}

}
void Htto::Rational_fraction::debug()
{
	std::cout << "rational_fraction debug msg:\n";
	std::cout << m_molecular.ToString()<<std::endl;
	std::cout << m_denomilator.ToString() << std::endl;
}
#endif

Rational_fraction Htto::operator-( Rational_fraction param)
{
	param.m_molecular = -param.m_molecular;
	return param;
}
