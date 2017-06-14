#pragma once
#include "polynomial.h"
//polynomial����ʹ��std::string ���һ��Rational_fraction����ʱΪ���ӷ�ĸ�������
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
		//����
		Polynomial m_molecular;
		//��ĸ
		Polynomial m_denomilator;
	};
}