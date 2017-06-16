/*����ʽ��
�汾:1.01
����:17-5-17
*/
#pragma once
#include <string>
#include <cctype>
#include <list>
#include "fraction.h"
#include <map>
namespace Htto
{
	class Polynomial;
	class Monomial
	{
	private:
		friend class Polynomial;
		friend Polynomial operator-(Polynomial  fra);
		friend Monomial operator-(Monomial  fra);
		Fraction coef;//ϵ��
		std::map<std::string, Fraction> variableTable;
	public:
		Monomial() = default;
		Monomial(std::string str);
		Monomial(const Monomial& M) :variableTable(M.variableTable), coef(M.coef) {}
		Monomial(Monomial && m)noexcept { coef = m.coef;variableTable = m.variableTable; }
		Monomial & operator=(const Monomial & M)
		{
			variableTable = M.variableTable;
			coef = M.coef;
			return *this;//ΰ���Sccot Meray(ģ������~�� �̵����� copying or copying-assigned operatorҪ����һ������.
		}
		bool operator!=(const Monomial & M)const;
		Monomial operator* (const Monomial &M)const;
		Monomial operator/ (const Monomial & M)const;
		bool operator==(const Monomial & M)const;
		bool operator < (const Monomial & M)const;
		bool operator >(const Monomial & M)const;
		std::string ToString()const;
		//the difference between name and ID:
		//name return times,but ID not
		std::string name()const;
		std::string ID()const;
		static bool is_like_term(const Monomial &, const Monomial &);//�ж��Ƿ���ͬ����
		void simplifiction();
		Fraction get_coef()const
		{
			return coef;
		}
		Fraction get_value(const std::map<std::string, Fraction> & vtable)const;
		Fraction times()const;
#ifdef CONSOLE_DEBUG
		std::map<std::string, Fraction>  debug()const;
#endif
	};
}