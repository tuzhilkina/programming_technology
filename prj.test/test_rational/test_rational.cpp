#include <iostream>
#include <rational/rational.h>

int main()
{
	testParse("{3/15}");
	try
	{
		testParse("{7/0}");
	}
	catch (std::invalid_argument)
	{

	}

	testParse("{9/-4}");
	testParse("{-9/-15}");
	testParse("-6/-17}");
	std::cout << '\n';

	Rational a = Rational(2, 5);
	Rational b = Rational(3, 8);
	Rational c = Rational(-14, 9);
	Rational d = Rational(-1, 7);
	std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n' << '\n';
	std::cout << a << " == " << b << " : " << (a == b) << '\n';
	std::cout << a << " != " << b << " : " << (a != b) << '\n' << '\n';
	std::cout << a << " >  " << b << " : " << (a > b) << '\n';
	std::cout << a << " <  " << b << " : " << (a < b) << '\n';
	std::cout << a << " >= " << b << " : " << (a >= b) << '\n';
	std::cout << a << " <= " << b << " : " << (a <= b) << '\n' << '\n';
	std::cout << a << " += " << b << " = ";
	std::cout << (a += b) << '\n';
	std::cout << b << " -= " << c << " = ";
	std::cout << (b -= c) << '\n';
	std::cout << c << " *= " << d << " = ";
	std::cout << (c *= d) << '\n';
	std::cout << d << " /= " << a << " = ";
	std::cout << (d /= a) << '\n' << '\n';
	a = Rational(2, 5);
	b = Rational(3, 8);
	c = Rational(-14, 9);
	d = Rational(-1, 7);
	std::cout << a << " + " << b << " = " << (a + b) << '\n';
	std::cout << a << " - " << b << " = " << (a - b) << '\n';
	std::cout << a << " * " << b << " = " << (a * b) << '\n';
	std::cout << a << " / " << b << " = " << (a / b) << '\n';
}