#pragma once
#include "fraction.h"
#include <stack>
#include <list>
namespace Htto
{
	namespace Count
	{
		struct unit
		{
			std::string strData;
			float numData;
			int priority;
			bool isNumber;
		};
		//实现一个小小的计算器。
		class Simple_Count
		{
		public:
			static std::list<unit> PushToList(std::string input);
			static std::list<unit> InfixToPostfix(std::list<unit> & ExpStream);
			static Htto::Fraction GetCountResult(const std::list<unit> & exp);
			static Htto::Fraction Count(const std::string str);
		};
	}
}