#ifndef LONG_INT_LONG_INT_H
#define LONG_INT_LONG_INT_H

#include <iostream>
#include <vector>

struct longInt
{
	std::vector<uint32_t> nbase; //вектор, содержащий число в base-тичной системе
	long long int base{ 4294967296 }; //основание системы счисления

	longInt(const std::string str);

};

//условие, останавливающее цикл деления
bool signToStop(std::vector<int> n10, std::vector<int> base10);

#endif // !LONG_INT_LONG_INT_H