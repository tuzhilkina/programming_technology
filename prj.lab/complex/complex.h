#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

#include <iostream>

struct Complex
{
	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char rightBrace{ '}' };
	static const char comma{ ',' };

	Complex() {}
	explicit Complex(const double rhs);
	Complex(const double real, const double imaginary);

	bool operator==(const Complex& rhs) const;
	bool operator!=(const Complex& rhs) const;
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs);
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs);
	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs);

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);
};


bool testParse(const std::string& str);

Complex operator+(const Complex& rhs, const Complex& lhs);
Complex operator-(const Complex& rhs, const Complex& lhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs);
inline std::istream& operator>>(std::istream& istrm, Complex& rhs);

#endif // !COMPLEX_COMPLEX_H
