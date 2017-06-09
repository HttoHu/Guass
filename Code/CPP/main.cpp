#include "../../FractionTest.h"
//@ ⁰
//b*[^:b#/]+.*$
int main()
{
	using namespace Htto;
	using namespace std;
	try
	{
		//std::cout << Htto::StringTools::get_match_content("x");
		//Radical_Exp r("2@2+3@3");
		//std::cout << r.ToString();
		Htto::Show::FractionInit();
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	while (1)
		std::cin.get();
	return 0;
}
