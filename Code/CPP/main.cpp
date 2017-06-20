#include "../polynomial.h"
#include "../Count.h"
#include "../equation.h"
#include <time.h>
#include "../factorization.h"
#include "../Examples/polynomial_counter.h"
#ifdef _WIN32
#include <Windows.h>
#include<psapi.h>

//@ ⁰
//b*[^:b#/]+.*$
#endif
int main()
{
	using namespace Htto;
	using namespace std;
	clock_t start, finish;
	double total;
	start = clock();
	try
	{
		//std::cout << Monomial("4y^6x^7").get_numsqrt().ToString();
		for (const auto & a : Count::factorization::factoring(std::string("x^2+2x+1")))
		{
			std::cout << "(" << a.ToString() + ")";
		}
		//std::cout<<Count::factorization::get_public_factor(Monomial("2"), Monomial("xy")).ToString();
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	std::cout << "\n\n======================================\n\n";
	try
	{
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	finish = clock();
	total = (double)(finish - start);
	cout << "\nTIME:" << total;
	while (1)
		std::cin.get();
	return 0;
}
