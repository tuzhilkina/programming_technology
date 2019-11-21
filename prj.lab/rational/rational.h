#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H

#include <iosfwd>

//! \brief Рациональные числа.
class Rational {

public:
	//! \brief Умолчательный конструктор.
	Rational() = default;

	//! \brief Копирующий конструктор.
	Rational(const Rational&) = default;

	//! \brief Конструирование рационального числа из целого.
	//! \param num - числитель рационального числа.
	explicit Rational(const int num);

	//! \brief Конструирование рационального числа 
	//!    
	//! с заданными целой num и целой denum частями.
	//! \param[in] num - числитель числа
	//! \param[in] denum - знаменатель числа
	Rational(const int num, const int denum);

	//! \brief Присваивание.
	Rational& operator=(const Rational&) = default;

	//! \brief Унарный минус.
	Rational operator-() const;

	//! \brief Присваивающее сложение с рациональным числом.
	Rational& operator+=(const Rational& rhs);

	//! \brief Присваивающее вычитание рационального числа.
	Rational& operator-=(const Rational& rhs);

	//! \brief Присваивающее умножение на рациональное число.
	Rational& operator*=(const Rational& rhs);

	//! \brief Присваивающее деление на рациональное число.
	//! 
	//! Осуществляется путем умножения на число, обратное rhs.
	Rational& operator/=(const Rational& rhs);

	//! \brief Сравнение рациональных чисел на равенство.
	//!
	//! Два рациональных числа считаются равными, если равны соответственно числители и знаменатели.
	bool operator==(const Rational& rhs) const;

	//! \brief Сравнение рациональных чисел на неравенство.
	bool operator!=(const Rational& rhs) const;

	//! \brief Сравнение рациональных чисел на меньше. Осуществляется путем приведения к общему знаменателю и сравнением числителей.
	bool operator<(const Rational& rhs) const;

	//! \brief Сравнение рациональных чисел на меньше или равно. Осуществляется путем приведения к общему знаменателю и сравнением числителей.
	bool operator<=(const Rational& rhs) const;

	//! \brief Сравнение рациональных чисел на больше. Осуществляется путем приведения к общему знаменателю и сравнением числителей.
	bool operator>(const Rational& rhs) const;

	//! \brief Сравнение рациональных чисел на больше или равно. Осуществляется путем приведения к общему знаменателю и сравнением числителей.
	bool operator>=(const Rational& rhs) const;

	//! \brief Форматированный ввод из потока istrm комплексного числа в виде {re,im}.
	//!
	//! \param[in,out] istrm - поток
	//! \retval поток
	std::istream& read_from(std::istream& istrm);

	//! \brief Форматированный вывод в поток ostrm комплексного числа в виде {re,im}.
	//!
	//! \param[in,out] ostrm - поток
	//! \retval поток
	std::ostream& write_to(std::ostream& ostrm) const;

private:
	void normalize(); //! \brief Сокращение дроби и вынесение минуса (если имеется) из знаменателя в числитель. 
private:
	int num_{ 0 }; //!< числитель рационального числа
	int denum_{ 1 }; //!< знаменатель рационального числа
	const static char delimiter_{ '/' };
};

//! \brief Форматированный вввод в потока ostrm рационального числа \se Rational::write_to.
std::istream& operator>>(std::istream& istrm, Rational& r);

//! \brief Форматированный ввод из потока istrm комплексного числа \se Complex::read_from.
std::ostream& operator<<(std::ostream& ostrm, const Rational& r);

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);


#endif // !RATIONAL_RATIONAL_H