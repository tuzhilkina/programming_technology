#include <complex/complex.h>
#include <iostream>
#include <sstream>
#include <limits>

constexpr double eps = 2 * std::numeric_limits<double>::epsilon();

Complex::Complex(const double real)
	: Complex(real, 0.0) {
}


Complex::Complex(const double real, const double imaginary)
	: re(real), im(imaginary) {
}

bool Complex::operator==(const Complex& rhs) const {
	return std::abs(re - rhs.re) < eps && std::abs(im - rhs.im) < eps;
}


Complex& Complex::operator+=(const Complex& rhs) {
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
	operator=(Complex(re * rhs.re - im * rhs.im, re * rhs.im + im * rhs.re));
	return *this;
}

Complex& Complex::operator*=(const double rhs) {
	re *= rhs;
	im *= rhs;
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
	if (rhs == Complex(0.0, 0.0)) {
		throw std::logic_error("Complex::operator/= - divizion to zero.");
	}
	const auto conj = Complex(rhs.re, -rhs.im);
	operator*=(conj);
	const double denum = (rhs * conj).re;
	re /= denum;
	im /= denum;
	return *this;
}

Complex& Complex::operator/=(const double rhs) {
	if (std::abs(rhs) < eps) {
		throw std::logic_error("Complex::operator/= - divizion by zero.");
	}
	re /= rhs;
	im /= rhs;
	return *this;
}

std::ostream& Complex::write_to(std::ostream& ostrm) const {
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}


std::istream& Complex::read_from(std::istream& istrm) {
	char leftBrace = '0';
	double real = 0.0;
	char comma = '0';
	double imaganary = 0.0;
	char rightBrace = 0;
	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) &&
			(Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaganary;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}


Complex operator+(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs) += rhs;
}


Complex operator+(const Complex& lhs, const double rhs) {
	return Complex(lhs) += Complex(rhs);
}


Complex operator+(const double lhs, const Complex& rhs) {
	return Complex(lhs) += rhs;
}


Complex operator-(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs) -= rhs;
}


Complex operator-(const Complex& lhs, const double rhs) {
	return Complex(lhs) -= Complex(rhs);
}


Complex operator-(const double lhs, const Complex& rhs) {
	return Complex(lhs) -= rhs;
}


Complex operator*(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs) *= rhs;
}


Complex operator*(const Complex& lhs, const double rhs) {
	return Complex(lhs) *= rhs;
}


Complex operator*(const double lhs, const Complex& rhs) {
	return Complex(lhs) *= rhs;
}


Complex operator/(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs) /= rhs;
}


Complex operator/(const Complex& lhs, const double rhs) {
	return Complex(lhs.re / rhs, lhs.im / rhs);
}


Complex operator/(const double lhs, const Complex& rhs) {
	return Complex(lhs) /= rhs;
}