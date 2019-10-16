#include <long_int/long_int.h>
#include <iostream>
#include <vector>
#include <string>

//условие, останавливающее цикл деления
bool signToStop(std::vector<int> n10, std::vector<int> base10)
{
	bool result(0);
	if (n10.size() < base10.size()) result = 1;
	else if (n10.size() == base10.size())
		for (int i = 0; i < n10.size(); i++)
		{
			if (n10[i] < base10[i])
			{
				result = 1;
				break;
			}
		}
	return result;
}

longInt::longInt(const std::string str)
{
	std::vector<int> n10;
	std::vector<int> base10;

	//представление основания системы счисления в вектор<int> 
	std::string t = std::to_string(base);
	for (int i = 0; i < t.length(); ++i)
	{
		std::string temp = "";
		temp += t[i];
		base10.push_back(atoi(temp.c_str()));
	}

	//представление строки, подданой в качетсве аргумента в конструктор, в вектор<int> 
	for (int i = 0; i < str.length(); ++i)
	{
		std::string temp = "";
		temp += str[i];
		n10.push_back(atoi(temp.c_str()));
	}

	//1 итерация следующего цикла делит десятичный вектор на основание системы счисления, остаток от деления вставляет в конец результирующего вектора
	while (!signToStop(n10, base10))
	{
		long long int chastnoe(0);
		long long int ostatok(0);

		for (int i = 0; i < n10.size(); ++i) //делит десятичный вектор на основание base-тичной системы счисления
		{
			chastnoe = (ostatok * 10 + n10[i]) / base;
			ostatok = (ostatok * 10 + n10[i]) % base;
			n10[i] = chastnoe;
		}

		nbase.push_back(ostatok); //формирование разряда в base-тичной системе

		//следующие циклы избавляются от незначащих нулей в старших разрядах
		int count_0(0);
		for (int i = 0; i < n10.size(); ++i)
			if (n10[i] == 0) ++count_0;
		for (int i = 0; i < n10.size() - count_0; ++i)
			n10[i] = n10[i + count_0];
		for (int i = 0; i < count_0; ++i)
			n10.pop_back();
	}

	//конечный результат деления - вектор n10 - необходимо представить в виде uint32_t и вставить в конец вектора nbase
	std::reverse(n10.begin(), n10.end());
	int result(0);
	for (int i = 0; i < n10.size(); ++i)
	{
		int degree(1);
		for (int j = 0; j < i; ++j)
			degree *= 10;
		result += n10[i] * degree;
	}
	nbase.push_back(result);

	std::reverse(nbase.begin(), nbase.end());
}