#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H

#include <iosfwd>

//! \brief ������������ �����.
class Rational {

public:
	//! \brief ������������� �����������.
	Rational() = default;

	//! \brief ���������� �����������.
	Rational(const Rational&) = default;

	//! \brief ��������������� ������������� ����� �� ������.
	//! \param num - ��������� ������������� �����.
	explicit Rational(const int num);

	//! \brief ��������������� ������������� ����� 
	//!    
	//! � ��������� ����� num � ����� denum �������.
	//! \param[in] num - ��������� �����
	//! \param[in] denum - ����������� �����
	Rational(const int num, const int denum);

	//! \brief ������������.
	Rational& operator=(const Rational&) = default;

	//! \brief ������� �����.
	Rational operator-() const;

	//! \brief ������������� �������� � ������������ ������.
	Rational& operator+=(const Rational& rhs);

	//! \brief ������������� ��������� ������������� �����.
	Rational& operator-=(const Rational& rhs);

	//! \brief ������������� ��������� �� ������������ �����.
	Rational& operator*=(const Rational& rhs);

	//! \brief ������������� ������� �� ������������ �����.
	//! 
	//! �������������� ����� ��������� �� �����, �������� rhs.
	Rational& operator/=(const Rational& rhs);

	//! \brief ��������� ������������ ����� �� ���������.
	//!
	//! ��� ������������ ����� ��������� �������, ���� ����� �������������� ��������� � �����������.
	bool operator==(const Rational& rhs) const;

	//! \brief ��������� ������������ ����� �� �����������.
	bool operator!=(const Rational& rhs) const;

	//! \brief ��������� ������������ ����� �� ������. �������������� ����� ���������� � ������ ����������� � ���������� ����������.
	bool operator<(const Rational& rhs) const;

	//! \brief ��������� ������������ ����� �� ������ ��� �����. �������������� ����� ���������� � ������ ����������� � ���������� ����������.
	bool operator<=(const Rational& rhs) const;

	//! \brief ��������� ������������ ����� �� ������. �������������� ����� ���������� � ������ ����������� � ���������� ����������.
	bool operator>(const Rational& rhs) const;

	//! \brief ��������� ������������ ����� �� ������ ��� �����. �������������� ����� ���������� � ������ ����������� � ���������� ����������.
	bool operator>=(const Rational& rhs) const;

	//! \brief ��������������� ���� �� ������ istrm ������������ ����� � ���� {re,im}.
	//!
	//! \param[in,out] istrm - �����
	//! \retval �����
	std::istream& read_from(std::istream& istrm);

	//! \brief ��������������� ����� � ����� ostrm ������������ ����� � ���� {re,im}.
	//!
	//! \param[in,out] ostrm - �����
	//! \retval �����
	std::ostream& write_to(std::ostream& ostrm) const;

private:
	void normalize(); //! \brief ���������� ����� � ��������� ������ (���� �������) �� ����������� � ���������. 
private:
	int num_{ 0 }; //!< ��������� ������������� �����
	int denum_{ 1 }; //!< ����������� ������������� �����
	const static char delimiter_{ '/' };
};

//! \brief ��������������� ����� � ������ ostrm ������������� ����� \se Rational::write_to.
std::istream& operator>>(std::istream& istrm, Rational& r);

//! \brief ��������������� ���� �� ������ istrm ������������ ����� \se Complex::read_from.
std::ostream& operator<<(std::ostream& ostrm, const Rational& r);

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);


#endif // !RATIONAL_RATIONAL_H