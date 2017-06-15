#pragma once
#include "Count.h"
#include <vector>
namespace Htto
{
	namespace Count
	{
		class Equation
		{
		public:
			//简单方程仅限单元变量x 一次方程和二次方程
			static std::vector<Fraction> solve(const std::string & str);
			static Polynomial get_polynomial(const std::string & str);
			static Polynomial merage(const std::string & left, const std::string & right);
		private:

		};
	}
}