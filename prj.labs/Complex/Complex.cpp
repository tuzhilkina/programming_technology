#include <iostream>
#include <sstream>
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

Complex::Complex(const double rhs) : Complex(rhs, 0.0)
{
}
Complex::Complex(const double real, const double imaginary) : re(real), im(imaginary)
{
}
bool Complex::operator==(const Complex& rhs) const
{
	return (re == rhs.re) && (im == rhs.im);
}
bool Complex::operator!=(const Complex& rhs) const
{
	return !operator==(rhs);
}
Complex& Complex::operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}
Complex& Complex::operator+=(const double rhs)
{
	return operator+=(Complex(rhs));
}
Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}
Complex& Complex::operator-=(const double rhs)
{
	return operator-=(Complex(rhs));
}
Complex& Complex::operator*=(const Complex& rhs)
{
	re = re * rhs.re - im * rhs.im;
	im = re * rhs.im + im * rhs.re;
	return *this;
}
Complex& Complex::operator*=(const double rhs)
{
	return operator*=(Complex(rhs));
}

Complex operator+(const Complex& rhs, const Complex& lhs)
{
	Complex sum(rhs);
	sum += lhs;
	return sum;
}
Complex operator-(const Complex& rhs, const Complex& lhs)
{
	Complex sum(rhs);
	sum -= lhs;
	return sum;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << re << comma << im << rightBrace;
	return ostrm;
}
std::istream& Complex::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaginary(0);
	char rightBrace(0);

	istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
	if (istrm.good())
	{
		if ((Complex::leftBrace == leftBrace) && (Complex::comma == comma) && (Complex::rightBrace == rightBrace))
		{
			re = real;
			im = imaginary;
		}
		else
			istrm.setstate(std::ios_base::failbit);
	}
	return istrm;

}

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
	return rhs.writeTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm);
}

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good())
		cout << "Read success: " << str << " -> " << z << endl;
	else
		cout << "Read error: " << str << " -> " << z << endl;
	return istrm.good();

}

int main()
{
	using namespace std;

	Complex z;
	z += Complex(8.0);
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9");
	return 0;
}