#include <rational/rational.h>
#include <iostream>
#include <sstream>
#include <stdexcept>

void Rational::Sample()
{
	if (down == 0)
	{
		std::cout << "ffffffffffffffff";
		throw std::invalid_argument("Zero denumenator in Rational");
	}
	else
	{
		int a = abs(up);
		int b = abs(down);
		while (a != b)
		{
			if (a > b) a -= b;
			else b -= a;
		}
		up = up / a;
		down = down / a;

		if (((up < 0) && (down < 0)) || (down < 0))
		{
			up = -up;
			down = -down;
		}
	}
}

Rational::Rational(const int _up, const int _down) : up(_up), down(_down)
{
	Sample();
}
Rational::Rational(const int rhs) : Rational(rhs, 1) {}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << up << slash << down << rightBrace;
	return ostrm;
}
inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}

std::istream& Rational::readFrom(std::istream& istrm)
{
	char _slash(0);
	int _up(0);
	int _down(1);
	char leftbrace(0);
	char rightbrace(0);

	istrm >> leftbrace >> _up >> _slash >> _down >> rightbrace;
	if (istrm.good())
	{
		if ((Rational::slash == _slash) && (Rational::leftBrace == leftbrace) && (Rational::rightBrace == rightbrace) && (_down != 0))
		{
			up = _up;
			down = _down;
			Sample();
		}
		else
			istrm.setstate(std::ios_base::failbit);
	}
	return istrm;
}
inline std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}
bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Rational z;
	istrm >> z;
	if (istrm.good())
		cout << "Read success: " << str << " -> " << z << endl;
	else
		cout << "Read error: " << str << " -> " << z << endl;
	return istrm.good();
}


bool Rational::operator==(Rational rhs)
{
	Sample();
	rhs.Sample();
	return { (up == rhs.up) && (down == rhs.down) };
}
bool Rational::operator!=(Rational rhs)
{
	return !operator==(rhs);
}
bool Rational::operator>(Rational rhs)
{
	Sample();
	rhs.Sample();
	int temp = up;
	temp *= rhs.down;
	rhs.up *= down;
	return (temp > rhs.up);
}
bool Rational::operator<(Rational rhs)
{
	return { !operator>(rhs) && !operator==(rhs) };
}
bool Rational::operator>=(Rational rhs)
{
	return { operator>(rhs) || operator==(rhs) };
}
bool Rational::operator<=(Rational rhs)
{
	return { operator<(rhs) || operator==(rhs) };
}
Rational& Rational::operator+=(Rational rhs)
{
	up *= rhs.down;
	rhs.up *= down;
	up += rhs.up;
	down *= rhs.down;
	Sample();
	return *this;
}
Rational& Rational::operator-=(Rational rhs)
{
	up *= rhs.down;
	rhs.up *= down;
	up -= rhs.up;
	down *= rhs.down;
	Sample();
	return *this;
}
Rational& Rational::operator*=(Rational rhs)
{
	up *= rhs.up;
	down *= rhs.down;
	Sample();
	return *this;
}
Rational& Rational::operator/=(Rational rhs)
{
	up *= rhs.down;
	down *= rhs.up;
	Sample();
	return *this;
}

Rational operator+(Rational lhs, Rational rhs)
{
	return lhs += rhs;
}
Rational operator-(Rational lhs, Rational rhs)
{
	return lhs -= rhs;
}
Rational operator*(Rational lhs, Rational rhs)
{
	return lhs *= rhs;
}
Rational operator/(Rational lhs, Rational rhs)
{
	return lhs /= rhs;
}