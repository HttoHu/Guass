#include "../polynomial.h"
#include "../Count.h"
#include "../equation.h"
#include <time.h>
#include "../Examples/polynomial_counter.h"
#ifdef _WIN32
#include <Windows.h>
#include<psapi.h>

//@ ⁰
//b*[^:b#/]+.*$
void showMemoryInfo()
{
	HANDLE handle = GetCurrentProcess();
	PROCESS_MEMORY_COUNTERS pmc;
	GetProcessMemoryInfo(handle, &pmc, sizeof(pmc));
	std::cout << "\n内存使用:" << pmc.WorkingSetSize / 1000 << "K/" << pmc.PeakWorkingSetSize / 1000 << "K + " << pmc.PagefileUsage / 1000 << "K/" << pmc.PeakPagefileUsage / 1000 << "K" << std::endl;
}
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
		//Example::polynomial_counter();
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	std::cout << "\n\n======================================\n\n";
	try
	{
		map<std::string, Fraction> result;
		result = Count::Equation2::solve({ "x+y+z=3","x-y+z=5","x+4z=4"});
		//result = Count::Equation2::solve({"2x+2y+3z+4t=5","6x-5y+8z+9t=10","11x+12y+13z+14t=5","16x+17y+18z+19t=20"});
		for (map<std::string, Fraction>::iterator it = result.begin();it != result.end();it++)
		{
			std::cout << it->first << "=" << it->second.ToString() << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	finish = clock();
	total = (double)(finish - start);
	cout << "\nTIME:" << total;
#ifdef _WIN32
	showMemoryInfo();
#endif
	while (1)
		std::cin.get();
	return 0;
}
