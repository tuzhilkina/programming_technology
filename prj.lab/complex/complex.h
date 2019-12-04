#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

#include <iosfwd>

//! \brief ����������� �����.
struct Complex {

	//! \brief ������������� �����������.
	Complex() = default;

	//! \brief ���������� �����������.
	Complex(const Complex&) = default;

	//! \brief ��������������� ������������ ����� �� ��������� �������������.
	//! \param real - ������������ ����� ������������ �����
	explicit Complex(const double real);

	//! \brief ��������������� ������������ ����� 
	//!    
	//! � ��������� ������������ real � ������ imaginary �������.
	//! \param[in] real - ������������ ����� ������������ �����
	//! \param[in] imaginary - ������ ����� ������������ �����
	Complex(const double real, const double imaginary);

	//! \brief ������������ �����������.
	Complex(Complex&&) = default;

	//! \brief ������������.
	Complex& operator=(const Complex&) = default;

	//! \brief ������������ ������������.
	Complex& operator=(Complex&&) = default;

	//! \brief ����������.
	~Complex() = default;


	//! \brief ������� �����.
	Complex operator-() const noexcept { return Complex(-re, -im); }

	//! \brief ��������� ����������� ����� �� ���������.
	//!
	//! ��� ����������� ����� ��������� �������, ���� ������ �������� 
	//! ������������ � ������ ������ �� ����������� eps = 2 * std::numeric_limits<double>::epsilon()
	bool operator==(const Complex& rhs) const noexcept;

	//! \brief ��������� ����������� ����� �� �����������. \sa Complex::operator== 
	bool operator!=(const Complex& rhs) const noexcept { return !operator==(rhs); }

	//! \brief ������������� �������� � ����������� ������.
	Complex& operator+=(const Complex& rhs) noexcept;

	//! \brief ������������� �������� � ������������ ������.
	Complex& operator+=(const double rhs) noexcept { return operator+=(Complex(rhs)); }

	//! \brief ������������� ��������� ������������ �����.
	Complex& operator-=(const Complex& rhs) noexcept;

	//! \brief ������������� ��������� ������������� �����.
	Complex& operator-=(const double rhs) noexcept { return operator-=(Complex(rhs)); }

	//! \brief ������������� ��������� �� ����������� �����.
	Complex& operator*=(const Complex& rhs) noexcept;

	//! \brief ������������� ��������� �� ������������ �����.
	Complex& operator*=(const double rhs) noexcept;

	//! \brief ������������� ������� �� ����������� �����.
	//! 
	//! �������������� ����� ���������� ��������� � ����������� �� ���������� ����������� � rhs.
	Complex& operator/=(const Complex& rhs);

	//! \brief ������������� ������� �� ������������ �����.
	Complex& operator/=(const double rhs);

	//! \brief ��������������� ����� � ����� ostrm ������������ ����� � ���� {re,im}.
	//!
	//! \param[in,out] ostrm - �����
	//! \retval �����
	std::ostream& write_to(std::ostream& ostrm) const;

	//! \brief ��������������� ���� �� ������ istrm ������������ ����� � ���� {re,im}.
	//!
	//! \param[in,out] istrm - �����
	//! \retval �����
	std::istream& read_from(std::istream& istrm);

	double re{ 0.0 }; //!< ������������ ����� ������������ �����
	double im{ 0.0 }; //!< ������ ����� ������������ �����

	static const char leftBrace{ '{' }; //!< ����� ������ ���������������� �������������
	static const char separator{ ',' }; //!< ����������� ���������������� �������������
	static const char rightBrace{ '}' }; //!< ������ ������ ���������������� �������������
};

//! \brief �������� ����������� �����.
Complex operator+(const Complex& lhs, const Complex& rhs);

//! \brief �������� ������������ � ������������� �����.
Complex operator+(const Complex& lhs, const double rhs);

//! \brief �������� ������������� � ������������ �����.
Complex operator+(const double lhs, const Complex& rhs);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator-(const double lhs, const Complex& rhs);

//! \brief ��������� ������������ ����� �� �����������.
Complex operator*(const Complex& lhs, const Complex& rhs);

//! \brief ��������� ������������ ����� �� ������������.
Complex operator*(const Complex& lhs, const double rhs);

//! \brief ��������� ������������� ����� �� �����������.
Complex operator*(const double lhs, const Complex& rhs);

//! \brief ������� ������������ ����� �� �����������.
Complex operator/(const Complex& lhs, const Complex& rhs);

//! \brief ������� ������������ ����� �� ������������.
Complex operator/(const Complex& lhs, const double rhs);

//! \brief ������� ������������� ����� �� �����������.
Complex operator/(const double lhs, const Complex& rhs);

//! \brief ��������������� ����� � ������ ostrm ������������ ����� \se Complex::write_to.
inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
	return rhs.write_to(ostrm);
}

//! \brief ��������������� ���� �� ������ istrm ������������ ����� \se Complex::read_from.
inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
	return rhs.read_from(istrm);
}

#endif
