#pragma once
#include "Count.h"
namespace Htto
{
	namespace Count
	{
		class Equation
		{
		public:
			static Polynomial get_polynomial(const std::string & str);
		private:
			static Polynomial merage(const std::string & left, const std::string & right);
		};
	}
}