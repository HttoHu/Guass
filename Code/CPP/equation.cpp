#include "../equation.h"
using namespace Htto::Count;
using namespace Htto;
Polynomial Htto::Count::Equation::get_polynomial(const std::string & str)
{
	if (str.find('=') == std::string::npos)
	{
		throw std::runtime_error("Equation::<public>get_polynomial: '=' disappeared.");
	}
	size_t index = str.find('=');
	std::string left = str.substr(0, index);
	std::string right = str.substr(index+1, str.size()-index-1);
	return merage(left, right);
}
Htto::Polynomial Htto::Count::Equation::merage(const std::string & left, const std::string & right)
{
	UniversalCount<Polynomial>temp;
	temp.InfixToPostfix(SimpleCount::PushToListP(left));
	Polynomial left_part=temp.Count();
	temp.InfixToPostfix(SimpleCount::PushToListP(right));
	Polynomial right_part = temp.Count();
	return (left_part - right_part);
}
