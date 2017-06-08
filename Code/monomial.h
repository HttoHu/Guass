/*单项式类
版本:1.01
日期:17-5-17
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
		Fraction coef;//系数
		std::map<std::string, Fraction> variableTable;
	public:
		Monomial() = default;
		Monomial(std::string str);
		Monomial(const Monomial& M):variableTable(M.variableTable),coef(M.coef){}
		Monomial & operator=(const Monomial & M)
		{
			variableTable = M.variableTable;
			coef = M.coef;
			return *this;//伟大的Sccot Meray(模糊记忆~） 教导我们 copying or copying-assigned operator要返回一个引用.
		}
		bool operator!=(const Monomial & M)const;
		Monomial operator* (const Monomial &M)const;
		Monomial operator/ (const Monomial & M)const;
		bool operator==(const Monomial & M)const;
		bool operator < (const Monomial & M)const;
		bool operator >(const Monomial & M)const;
		std::string ToString()const;
		std::string name()const;
		static bool is_like_term(const Monomial &,const Monomial &);//判断是否是同类项
		void simplifiction();
		Fraction times()const;
		std::map<std::string, Fraction>  debug()const;
	};
}