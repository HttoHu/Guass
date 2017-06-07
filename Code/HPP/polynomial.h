#pragma once
#include "monomial.h"
#include <vector>
#include <set>
#include <algorithm>
namespace Htto
{
	//多项式类
	//请注意，多项式类除法(operator/)是有问题的（算法上的问题）。我花了2个小时尝试解决它，但是我失败了。但我发现了fraction的bug。抱歉精力有限，现在请不要使用.
	//除以一个单项式是没有问题的。我将写一个分式类来处理除法问题。
	class Polynomial
	{
	public:
		Polynomial() = default;
		Polynomial(std::string str);
		Polynomial(const Polynomial & poly) :data(poly.data) {}
		Polynomial(const Monomial& mono) :data({ mono }) {}
		void simplification();
		std::string ToString()const;
		std::size_t  term_count();
		std::size_t variable_count();
		Fraction max_times();
		void sort();

		Polynomial & operator =(const Polynomial &) = default;
		Polynomial operator +(const Polynomial &)const;
		Polynomial operator -(const Polynomial &)const;
		Polynomial operator *(const Polynomial &)const;
		Polynomial operator /(const Polynomial &)const;
		Polynomial& operator +=(const Polynomial &);
		Polynomial& operator -=(const Polynomial &);
		Polynomial& operator *=(const Polynomial &);
		Polynomial& operator /=(const Polynomial &);
		std::vector<Monomial> debug()
		{
			return data;
		}
	private:
		std::vector<Monomial> data;
		void push_monomial(const std::string & str);
	};
}