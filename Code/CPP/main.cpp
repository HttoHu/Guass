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
		Example::polynomial_counter();
		//std::cout << Count::Equation2::convert_single_to_polynomial("y", Count::SimpleCount::PolyCount("(2/3)y+(5/3)z-2")).ToString();
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	std::cout << "\n\n======================================\n\n";
	try
	{
		//std::cout << Count::Equation2::convert_single_to_polynomial("x", Polynomial("5x+y-3")).ToString();
		//std::cout << (Polynomial("-y") - Polynomial("1/2") - Polynomial("4/5")).ToString();
		map<std::string, Fraction> result;
		result = Count::Equation2::solve({ "3x+y+z=3","x+y+2z=1","2x+y-z=3"});
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
