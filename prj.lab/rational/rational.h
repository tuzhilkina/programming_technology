#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H

#include <iostream>

struct Rational
{
	int up{ 0 };
	int down{ 1 };
	static const char leftBrace{ '{' };
	static const char rightBrace{ '}' };
	static const char slash{ '/' };

	Rational() {}
	explicit Rational(const int rhs);
	Rational(const int _up, const int _down);

	void Sample();
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	bool operator==(Rational rhs);
	bool operator!=(Rational rhs);
	bool operator>(Rational rhs);
	bool operator<(Rational rhs);
	bool operator>=(Rational rhs);
	bool operator<=(Rational rhs);

	Rational& operator+=(Rational rhs);
	Rational& operator-=(Rational rhs);
	Rational& operator*=(Rational rhs);
	Rational& operator/=(Rational rhs);
};

Rational operator+(Rational lhs, Rational rhs);
Rational operator-(Rational lhs, Rational rhs);
Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);

bool testParse(const std::string& str);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
inline std::istream& operator>>(std::istream& istrm, Rational& rhs);


#endif // !RATIONAL_RATIONAL_H