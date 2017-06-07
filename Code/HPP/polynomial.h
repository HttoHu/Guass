#pragma once
#include "monomial.h"
#include <vector>
#include <set>
#include <algorithm>
namespace Htto
{
	//����ʽ��
	//��ע�⣬����ʽ�����(operator/)��������ģ��㷨�ϵ����⣩���һ���2��Сʱ���Խ������������ʧ���ˡ����ҷ�����fraction��bug����Ǹ�������ޣ������벻Ҫʹ��.
	//����һ������ʽ��û������ġ��ҽ�дһ����ʽ��������������⡣
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