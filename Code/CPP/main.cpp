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
		Example::polyv_equation();
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	std::cout << "\n\n======================================\n\n";
	try
	{
		//Example::polynomial_counter();
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
