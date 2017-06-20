#include "../factorization.h"
using namespace Htto;
std::vector<Polynomial> Htto::Count::factorization::factoring(Polynomial poly)
{
	std::vector<Polynomial> ret;
	poly.simplification();
	Monomial m_factor = poly.data.at(0);//cheak index.
	for (const auto & a : poly.data)
	{
		m_factor = get_public_factor(m_factor, a);
	}
	ret.push_back(Polynomial({ m_factor }));
	poly /= Polynomial({ m_factor });
	if (poly.term_count() == 3)
	{
		std::sort(poly.data.begin(), poly.data.end(), [](const Monomial & m1, const Monomial & m2) 
		{
			if (m1.times() > m2.times())
				return true;
			else if (m1.times() == m2.times()&&m1.get_coef() > m2.get_coef())
				return true; 
			else return false;
		});
		if (poly.max_times() == Fraction(2))
		{
			std::vector<Monomial> vec;
			for (const auto & a : poly.data)
			{
				if (a.is_square())
				{
					vec.push_back(a);
				}
			}
			if (vec.size() < 2)
				;
			else
			{
				Monomial m3("1");
				for (const auto & a : vec)
				{
					m3 = m3*a.get_numsqrt();
				}
				m3 = m3*Monomial("2");
				if (std::find(poly.data.cbegin(), poly.data.cend(), m3)!=poly.data.cend())
				{
					ret.push_back({ vec[0].get_numsqrt(),vec[1].get_numsqrt() });
					ret.push_back({ vec[0].get_numsqrt(),vec[1].get_numsqrt() });
				}
			}
		}

	}
	else
	{
		if (poly.term_count() == 2)
		{
			std::sort(poly.data.begin(), poly.data.end(), [](const Monomial & m1, const Monomial & m2) {return m1.get_coef() > m2.get_coef();});
			if (poly.data[1].coef < Fraction(0) && poly.data[0].is_square() && (-poly.data[1]).is_square())
			{
				if ((int)poly.data[0].coef > 0)
				{
					ret.push_back({ poly.data[0].get_numsqrt(),(-poly.data[1]).get_numsqrt() });
					ret.push_back({ poly.data[0].get_numsqrt(),-(-poly.data[1]).get_numsqrt() });
				}
			}
		}
	}
	return ret;
}
Monomial Htto::Count::factorization::get_public_factor(const Monomial & m1, const Monomial & m2)
{
	using const_iterator = std::map<std::string, Fraction>::const_iterator;
	Monomial ret("1");
	if (m1.coef.is_interger() && m2.coef.is_interger())
	{
		ret.coef = Fraction(Htto::SimpleAlgorithm::INT_GCD(m1.coef, m2.coef));
		
	}
	for (const_iterator it = m1.variableTable.cbegin(); it != m1.variableTable.cend();it++)
	{
		const_iterator it2 = m2.variableTable.find(it->first);
		if (it2 != m2.variableTable.end())
		{
			ret.variableTable.insert({ it->first ,Htto::SimpleAlgorithm::get_min(it->second,it2->second) });
		}
	}
	return ret;
}
