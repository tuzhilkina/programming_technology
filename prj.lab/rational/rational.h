#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H

#include <iosfwd>

class Rational {
public:
	Rational() = default;
	Rational(const Rational&) = default;
	explicit Rational(const int num);
	Rational(const int num, const int denum);
	Rational& operator=(const Rational&) = default;

	Rational operator-() const;
	Rational& operator+=(const Rational& rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator/=(const Rational& rhs);

	bool operator==(const Rational& rhs) const;
	bool operator!=(const Rational& rhs) const;
	bool operator<(const Rational& rhs) const;
	bool operator<=(const Rational& rhs) const;
	bool operator>(const Rational& rhs) const;
	bool operator>=(const Rational& rhs) const;

	std::istream& read_from(std::istream& istrm);
	std::ostream& write_to(std::ostream& ostrm) const;

private:
	void normalize();
private:
	int num_{ 0 };
	int denum_{ 1 };
	const static char delimiter_{ '/' };
};

std::istream& operator>>(std::istream& istrm, Rational& r);
std::ostream& operator<<(std::ostream& ostrm, const Rational& r);

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);


#endif // !RATIONAL_RATIONAL_H