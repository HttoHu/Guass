#include "../fraction.h"
#include "../Count.h"
#include "../rational_fraction.h"
#include "../monomial.h"
#include "../handle.h"
#include "../polynomial.h"
//@ ⁰
//b*[^:b#/]+.*$
int main()
{
	using namespace Htto;
	using namespace std;
	try
	{
		Fraction a[3];
		std::string input;
		for (int i = 0;i < 3;i++)
		{
			cin >> input;
			a[i] = Fraction(input);
		}
		Fraction diat = a[1] * a[1] - Fraction(4)*a[0] * a[2];
		if (diat < Fraction(0))
		{
			throw std::runtime_error("diat<0");
		}
		diat.numsqrt();
		Fraction x1, x2;
		//std::cout << diat.ToString()<<std::endl;
		x1 = (-a[1] + diat) / (Fraction(2) * a[0]);
		x2 = (-a[1] - diat) / (Fraction(2) * a[0]);
		std::cout << x1.ToString() << std::endl;
		std::cout << x2.ToString();
		cin.get();
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	while (1)
		std::cin.get();
	return 0;
}
