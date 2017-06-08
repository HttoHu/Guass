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
	class Monomial
	{
	private:
		friend class Polynomial;
		Fraction coef;//ϵ��
		std::map<std::string, Fraction> variableTable;
	public:
		Monomial() = default;
		Monomial(std::string str);
		Monomial(const Monomial& M):variableTable(M.variableTable),coef(M.coef){}
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
		std::string name()const;
		static bool is_like_term(const Monomial &,const Monomial &);//�ж��Ƿ���ͬ����
		void simplifiction();
		Fraction times()const;
		std::map<std::string, Fraction>  debug()const;
	};
}