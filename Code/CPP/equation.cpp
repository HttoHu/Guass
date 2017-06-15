#include "../equation.h"
using namespace Htto::Count;
using namespace Htto;
std::vector<Fraction> Htto::Count::Equation::solve(const std::string & str)
{
	Polynomial poly_temp = get_polynomial(str);
	poly_temp.simplification();
	if (poly_temp.max_times() > Htto::Fraction(2))
		throw std::runtime_error("Equation::solve:   can not solve the equation that the times over 2");
	else if (poly_temp.variable_count() != 1)
		throw std::runtime_error("Equation::solve:   please input a single variable equation");
	if (poly_temp.max_times() == Fraction(1))
	{
		const size_t size = poly_temp.term_count();
		std::vector<Fraction> vec(2);
		for (int i = 0;i < size;i++)
		{
			vec[poly_temp[i].times()] = poly_temp[i].get_coef();
		}
		if (size == 1)
			return{ Fraction(0) };
		else if (size == 2)
		{
			return{ (-vec[0]/vec[1]) };
		}
	}
	if (poly_temp.max_times() == Fraction(2))
	{
		const size_t size = poly_temp.term_count();
		std::vector<Fraction> vec(3);
		for (int i = 0;i < size;i++)
		{
			vec[poly_temp[i].times()] = poly_temp[i].get_coef();
		}
		Fraction diat = (vec[1] * vec[1]) - (Fraction(4)*vec[0] * vec[2]);
		if (diat < Fraction(0))
			return{};
		else
		{
			diat.numsqrt();
			return{ ((-vec[1] - diat) / (Fraction(2)*vec[2])),((-vec[1] + diat) / (Fraction(2)*vec[2])) };
		}
	}
}
Polynomial Htto::Count::Equation::get_polynomial(const std::string & str)
{
	if (str.find('=') == std::string::npos)
	{
		throw std::runtime_error("Equation::<public>get_polynomial: '=' disappeared.");
	}
	size_t index = str.find('=');
	std::string left = str.substr(0, index);
	std::string right = str.substr(index + 1, str.size() - index - 1);
	return merage(left, right);
}
Htto::Polynomial Htto::Count::Equation::merage(const std::string & left, const std::string & right)
{
	UniversalCount<Polynomial>temp;
	temp.InfixToPostfix(Htto::Count::SimpleCount::PushToListP(StringTools::convert_expression(left)));
	Polynomial poly_left = temp.Count();
	temp.InfixToPostfix(Htto::Count::SimpleCount::PushToListP(StringTools::convert_expression(right)));
	Polynomial poly_right = temp.Count();
	return (poly_left - poly_right);
}
