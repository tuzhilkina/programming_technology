#include <rational/rational.h>

#include <iostream>
#include <exception>
#include <sstream>


Rational::Rational(const int num) : Rational(num, 1) {
}

Rational::Rational(const int num, const int denum)	: num_(num), denum_(denum) {
	if (0 == denum_) {
		throw std::invalid_argument("Rational ctor - zero denuminator.");
	}
	normalize();
}

Rational Rational::operator-() const {
	return Rational(-num_, denum_);
}

Rational& Rational::operator+=(const Rational& rhs) {
	num_ *= rhs.denum_;
	num_ += rhs.num_ * denum_;
	denum_ *= rhs.denum_;
	normalize();
	return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
	num_ *= rhs.denum_;
	num_ -= rhs.num_ * denum_;
	denum_ *= rhs.denum_;
	normalize();
	return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
	num_ *= rhs.num_;
	denum_ *= rhs.denum_;
	normalize();
	return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
	num_ *= rhs.denum_;
	denum_ *= rhs.num_;
	normalize();
	return *this;
}

bool Rational::operator==(const Rational& rhs) const {
	return num_ == rhs.num_ && denum_ == rhs.denum_;
}

bool Rational::operator!=(const Rational& rhs) const {
	return !operator==(rhs);
}

bool Rational::operator<(const Rational& rhs) const {
	return { !operator>(rhs) && !operator==(rhs) };
}

bool Rational::operator<=(const Rational& rhs) const {
	return { operator<(rhs) || operator==(rhs) };
}

bool Rational::operator>(const Rational& rhs) const {
	int temp = num_;
	temp *= rhs.denum_;
	return (temp > rhs.num_ * denum_);
}

bool Rational::operator>=(const Rational& rhs) const {
	return { operator>(rhs) || operator==(rhs) };
}

std::istream& Rational::read_from(std::istream& istrm) {
	char delimiter('0');
	int num(0);
	int denum(1);

	istrm >> num >> delimiter >> denum;
	if (!istrm.bad()) {
		if ((Rational::delimiter_ == delimiter) && (denum > 0)) {
			num_ = num;
			denum_ = denum;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}

std::ostream& Rational::write_to(std::ostream& ostrm) const {
	ostrm << num_ << delimiter_ << denum_;
	return ostrm;
}

void Rational::normalize()
{
	if (denum_ == 0) {
		throw std::invalid_argument("Zero denumenator in Rational");
	}
	else {
		int p = abs(num_);
		int q = abs(denum_);
		while (p != 0 && q != 0)
		{
			if (p > q)
			{
				p %= q;
			}
			else
			{
				q %= p;
			}
		}
		num_ = num_ / (p + q);
		denum_ = denum_ / (p + q);


		if (((num_ < 0) && (denum_ < 0)) || (denum_ < 0)) {
			num_ = -num_;
			denum_ = -denum_;
		}
	}
}

std::istream& operator>>(std::istream& istrm, Rational& r) {
	return r.read_from(istrm);
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& r) {
	return r.write_to(ostrm);
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
	Rational result = Rational(lhs);
	result += rhs;
	return result;
}
Rational operator-(const Rational& lhs, const Rational& rhs) {
	Rational result = Rational(lhs);
	result -= rhs;
	return result;
}
Rational operator*(const Rational& lhs, const Rational& rhs) {
	Rational result = Rational(lhs);
	result *= rhs;
	return result;
}
Rational operator/(const Rational& lhs, const Rational& rhs) {
	Rational result = Rational(lhs);
	result /= rhs;
	return result;
}
