#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

#include <iosfwd>

//! \brief Комплексные числа.
struct Complex {

	//! \brief Умолчательный конструктор.
	Complex() = default;

	//! \brief Копирующий конструктор.
	Complex(const Complex&) = default;

	//! \brief Конструирование комплексного числа из заданного вещественного.
	//! \param real - вещественная часть комплексного числа
	explicit Complex(const double real);

	//! \brief Конструирование комплексного числа 
	//!    
	//! с заданными вещественной real и мнимой imaginary частями.
	//! \param[in] real - вещественная часть комплексного числа
	//! \param[in] imaginary - мнимая часть комплексного числа
	Complex(const double real, const double imaginary);

	//! \brief Перемещающий конструктор.
	Complex(Complex&&) = default;

	//! \brief Присваивание.
	Complex& operator=(const Complex&) = default;

	//! \brief Перемещающее присваивание.
	Complex& operator=(Complex&&) = default;

	//! \brief Деструктор.
	~Complex() = default;


	//! \brief Унарный минус.
	Complex operator-() const noexcept { return Complex(-re, -im); }

	//! \brief Сравнение комплексных чисел на равенство.
	//!
	//! Два комплексных числа считаются равными, если модуль разности 
	//! вещественных и мнимых частей не превосходит eps = 2 * std::numeric_limits<double>::epsilon()
	bool operator==(const Complex& rhs) const noexcept;

	//! \brief Сравнение комплексных чисел на неравенство. \sa Complex::operator== 
	bool operator!=(const Complex& rhs) const noexcept { return !operator==(rhs); }

	//! \brief Присваивающее сложение с комплексным числом.
	Complex& operator+=(const Complex& rhs) noexcept;

	//! \brief Присваивающее сложение с вещественным числом.
	Complex& operator+=(const double rhs) noexcept { return operator+=(Complex(rhs)); }

	//! \brief Присваивающее вычитание комплексного числа.
	Complex& operator-=(const Complex& rhs) noexcept;

	//! \brief Присваивающее вычитание вещественного числа.
	Complex& operator-=(const double rhs) noexcept { return operator-=(Complex(rhs)); }

	//! \brief Присваивающее умножение на комплексное число.
	Complex& operator*=(const Complex& rhs) noexcept;

	//! \brief Присваивающее умножение на вещественное число.
	Complex& operator*=(const double rhs) noexcept;

	//! \brief Присваивающее деление на комплексное число.
	//! 
	//! Осуществляется путем домножения числителя и знаменателя на комплексно сопряженное с rhs.
	Complex& operator/=(const Complex& rhs);

	//! \brief Присваивающее деление на вещественное число.
	Complex& operator/=(const double rhs);

	//! \brief Форматированный вывод в поток ostrm комплексного числа в виде {re,im}.
	//!
	//! \param[in,out] ostrm - поток
	//! \retval поток
	std::ostream& write_to(std::ostream& ostrm) const;

	//! \brief Форматированный ввод из потока istrm комплексного числа в виде {re,im}.
	//!
	//! \param[in,out] istrm - поток
	//! \retval поток
	std::istream& read_from(std::istream& istrm);

	double re{ 0.0 }; //!< вещественная часть комплексного числа
	double im{ 0.0 }; //!< мнимая часть комплексного числа

	static const char leftBrace{ '{' }; //!< левая скобка форматированного представления
	static const char separator{ ',' }; //!< разделитель форматированного представления
	static const char rightBrace{ '}' }; //!< правая скобка форматированного представления
};

//! \brief Сложение комплексных чисел.
Complex operator+(const Complex& lhs, const Complex& rhs);

//! \brief Сложение комплексного и вещественного чисел.
Complex operator+(const Complex& lhs, const double rhs);

//! \brief Сложение вещественного и комплексного чисел.
Complex operator+(const double lhs, const Complex& rhs);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator-(const double lhs, const Complex& rhs);

//! \brief Умножение комплексного числа на комплексное.
Complex operator*(const Complex& lhs, const Complex& rhs);

//! \brief Умножение комплексного числа на вещественное.
Complex operator*(const Complex& lhs, const double rhs);

//! \brief Умножение вещественного числа на комплексное.
Complex operator*(const double lhs, const Complex& rhs);

//! \brief Деление комплексного числа на комплексное.
Complex operator/(const Complex& lhs, const Complex& rhs);

//! \brief Деление комплексного числа на вещественное.
Complex operator/(const Complex& lhs, const double rhs);

//! \brief Деление вещественного числа на комплексное.
Complex operator/(const double lhs, const Complex& rhs);

//! \brief Форматированный вввод в потока ostrm комплексного числа \se Complex::write_to.
inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
	return rhs.write_to(ostrm);
}

//! \brief Форматированный ввод из потока istrm комплексного числа \se Complex::read_from.
inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
	return rhs.read_from(istrm);
}

#endif
