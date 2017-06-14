#pragma once
#include "polynomial.h"
//polynomial请在使用std::string 获得一个Rational_fraction对象时为分子分母添加括号
namespace Htto
{
	class Rational_fraction
	{
	public:
		Rational_fraction() = default;
		Rational_fraction(const Polynomial & mol, const Polynomial & den) :m_molecular(mol), m_denomilator(den) {}
		Rational_fraction(const std::string &  str);
		std::string ToString();

		Rational_fraction operator+ (const Rational_fraction&)const;
		Rational_fraction operator- (const Rational_fraction&)const;
		Rational_fraction operator* (const Rational_fraction&)const;
		Rational_fraction operator/ (const Rational_fraction&)const;
		void debug();
	private:
		//分子
		Polynomial m_molecular;
		//分母
		Polynomial m_denomilator;
	};
}