#include <iostream>
#include <dynarrayt/dynarrayt.h>

int main()
{
	DynArrayT<float> c1 = DynArrayT<float>();
	std::cout << "Default constructor\n";

	DynArrayT<float> c2 = DynArrayT<float>(3);
	std::cout << "Size (3) constructor\n";
	c2[0] = 3.2;
	c2[1] = 4.5;
	c2[2] = -8.13;
	std::cout << "Printing the first array:\n";
	for (int i = 0; i < c2.size(); ++i)
		std::cout << c2[i] << ' ';
	std::cout << "\nTesting out of range:\n";
	try
	{
		c2[3] = 0.76;
	}
	catch (std::out_of_range)
	{
		std::cout << "Index is out of range. Change the size of array\n";
	}

	std::cout << "Copy constructor\n";
	DynArrayT<float> c3 = DynArrayT<float>(c2);
	std::cout << "Printing the second array:\n";
	for (int i = 0; i < c3.size(); ++i)
		std::cout << c3[i] << ' ';
	std::cout << "\nResizing (5)\n";
	c3.resize(5);
	c3[3] = 0.76;
	c3[4] = -5.5;
	for (int i = 0; i < c3.size(); ++i)
		std::cout << c3[i] << ' ';

	std::cout << "\nthe first array = the second array\n";
	c2 = c3;
	std::cout << "Printing the first array:\n";
	for (int i = 0; i < c2.size(); ++i)
		std::cout << c2[i] << ' ';

	std::cout << "\nGetting the size of the second array: " << c3.size() << '\n';
	std::cout << "Testing access: " << c3[4] << " -> ";
	c3[4] = 6.8;
	std::cout << c3[4] << '\n';
}