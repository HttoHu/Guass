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
			//�򵥷��̽��޵�Ԫ����x һ�η��̺Ͷ��η���
			static std::vector<Fraction> solve(const std::string & str);
			static Polynomial get_polynomial(const std::string & str);
			static Polynomial merage(const std::string & left, const std::string & right);
		private:

		};
	}
}