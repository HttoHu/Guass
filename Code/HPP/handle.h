#pragma once
#ifndef HANDLE_H
#define HANDLE_H
#include <string>
namespace Htto
{
	class Handle
	{
	public:
		static int INT_GCD(int n, int m);//��ù�����
		static int INT_MAX_FACTOR(int n);//�������ƽ��������
		 template<typename T>static T ABS(T a) { if (a > 0) { return a; } else return -a; }//�����ֵ
		template<typename T>static T Pow(const T & rhs, unsigned int lhs)
		{
			T ret = rhs;
			for (int i = 1;i < lhs;i++)
			{
				ret = ret*rhs;
			}
			return ret;
		}//�����ֵ
		static bool isEqual(int n, float f);
	};
	class StringTools
	{
	public:
		static float string_to_float(std::string str);
		static bool isNumber_int(std::string str);
		static bool isNumber(std::string str);
		static int isSingleNumber(char ch);
		static std::string get_rid_of_parentheses(std::string parameter);//ȥ�����š�
		static std::string get_parentheses_model(std::string parameter);
		static std::string get_match_content(std::string parameter, int n = 1);
		static int get_end_index(std::string str, unsigned index);//�Ǹ���̫���ˣ�ʲôtuple���˰�
		static std::string get_number_by_index(std::string str, unsigned index);
	};
}
#endif
