#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

#include <iostream>

struct Complex {
	Complex() = default;
	Complex(const Complex&) = default;
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);
	~Complex() = default;
	Complex& operator=(const Complex&) = default;

	Complex(Complex&&) = default;
	Complex& operator=(Complex&&) = default;

	Complex operator-() const { return Complex(-re, -im); }

	bool operator==(const Complex& rhs) const;
	bool operator!=(const Complex& rhs) const { return !operator==(rhs); }
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs);
	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs);

	std::ostream& write_to(std::ostream& ostrm) const;
	std::istream& read_from(std::istream& istrm);

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double rhs);
Complex operator+(const double lhs, const Complex& rhs);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator-(const double lhs, const Complex& rhs);

Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator*(const double lhs, const Complex& rhs);

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double rhs);
Complex operator/(const double lhs, const Complex& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
	return rhs.write_to(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
	return rhs.read_from(istrm);
}
#endif // !COMPLEX_COMPLEX_H
