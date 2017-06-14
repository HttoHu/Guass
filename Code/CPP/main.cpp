#include "../polynomial.h"
#include "../Count.h"
#include "../equation.h"
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#include<psapi.h>

//@ ⁰
//b*[^:b#/]+.*$
void showMemoryInfo(void)
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
		std::cout << "input an equation:\n";
		std::string input;
		while (input!="q")
		{
			cin >> input;
			std::cout << Count::Equation::get_polynomial(input).ToString()<<"=0\n";
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
