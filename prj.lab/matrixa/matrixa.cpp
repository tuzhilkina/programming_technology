#include <matrixa/matrixa.h>
#include <iostream>
#include <cstddef>
#include <memory>

MatrixA::MatrixA(const MatrixA& rhs) : n_row_(rhs.n_row_), n_col_(rhs.n_col_)
{
	data_ = std::make_unique<float[]>(n_row_ * n_col_);
	for (int i = 0; i < n_row_ * n_col_; ++i)
		data_[i] = rhs.data_[i];
}
MatrixA::MatrixA(const std::ptrdiff_t row_count, const std::ptrdiff_t col_count) : n_row_(row_count), n_col_(col_count)
{
	if ((row_count < 0) && (col_count < 0))
		throw std::invalid_argument("Change the size of matrix");
	data_ = std::make_unique<float[]>(n_row_ * n_col_);
}

float& MatrixA::at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i)
{
	if ((row_i >= n_col_) || (col_i >= n_col_))
	{
		throw std::out_of_range("");
	}
	return data_[row_i * n_col_ + col_i];
}
const float& MatrixA::at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i) const
{
	if ((row_i >= n_col_) || (col_i >= n_col_))
	{
		throw std::out_of_range("");
	}
	return data_[row_i * n_col_ + col_i];
}

MatrixA& MatrixA::operator=(const MatrixA& rhs)
{
	n_row_ = rhs.n_row_;
	n_col_ = rhs.n_col_;
	data_ = std::make_unique<float[]>(n_row_ * n_col_);
	for (int i = 0; i < n_row_ * n_col_; ++i)
		data_[i] = rhs.data_[i];
	return *this;
}

void MatrixA::print()
{
	for (ptrdiff_t i(0); i < n_row_; i += 1)
	{
		for (ptrdiff_t j(0); j < n_col_; j += 1)
		{
			std::cout << at(i, j) << " ";
		}
		std::cout << "\n";
	}
}
