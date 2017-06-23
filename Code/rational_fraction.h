#pragma once
#include "polynomial.h"
#include "factorization.h"
#include "Count.h"
//polynomial����ʹ��std::string ���һ��Rational_fraction����ʱΪ���ӷ�ĸ�������
namespace Htto
{
	class Rational_fraction
	{
	public:
		Rational_fraction() = default;
		Rational_fraction(const Polynomial & mol, const Polynomial & den) :m_molecular(mol), m_denomilator(den) {}
		Rational_fraction(const Polynomial & poly) { m_molecular = poly, m_denomilator = Polynomial("1"); }
		std::string ToString();
		Rational_fraction get_reciprocal()const;
		Rational_fraction operator+ (const Rational_fraction&)const;
		Rational_fraction operator- (const Rational_fraction&)const;
		Rational_fraction operator* (const Rational_fraction&)const;
		Rational_fraction operator/ (const Rational_fraction&)const;
		void simplifaction();
#ifdef CONSOLE_DEBUG
		void debug();
#endif
	private:
		friend Rational_fraction operator- ( Rational_fraction param);
		//����
		Polynomial m_molecular;
		//��ĸ
		Polynomial m_denomilator;
	};
}