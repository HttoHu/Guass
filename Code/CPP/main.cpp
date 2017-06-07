#include "fraction.h"
#include "Count.h"
#include "monomial.h"
#include "handle.h"
#include "polynomial.h"
//√ ⁰
//b*[^:b#/]+.*$
int main()
{
	using namespace Htto;
	using namespace std;
	try
	{
		Polynomial pn("wx^3");
		Polynomial p1("2x^2+y");
		Polynomial p2("x+y");
		std::cout << (p1*p2*p1*pn+p2-pn).ToString();
		cin.get();
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	return 0;
}
