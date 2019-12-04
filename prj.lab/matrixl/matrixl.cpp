#include <matrixl/matrixl.h>
#include <iostream>

MatrixL::MatrixL(const std::ptrdiff_t row_count, const std::ptrdiff_t col_count) : n_row_(row_count), n_col_(col_count)
{
	if ((row_count < 0) && (col_count < 0))
		throw std::invalid_argument("Change the size of matrix");
	data_ = new float[n_row_ * n_col_];
	start_ = new float* [n_row_];
	std::ptrdiff_t index(0);
	for (int i = 0; i < n_row_; ++i)
	{
		start_[i] = &(data_[i * n_col_]);
		++index;
	}
}

MatrixL::MatrixL(const MatrixL& rhs) : n_row_(rhs.n_row_), n_col_(rhs.n_col_),
data_(new float[n_row_ * n_col_]), start_(new float* [n_row_])
{
	std::copy(rhs.data_, rhs.data_ + rhs.n_row_ * rhs.n_col_, data_);
	std::copy(rhs.start_, rhs.start_ + rhs.n_row_, start_);
}

MatrixL::~MatrixL()
{
	delete[] data_;
	delete[] start_;
}

float& MatrixL::at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i)
{
	if ((row_i >= n_col_) || (col_i >= n_col_))
	{
		throw std::out_of_range("");
	}
	return *(start_[row_i] + col_i);
}
const float& MatrixL::at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i) const
{
	if ((row_i >= n_col_) || (col_i >= n_col_))
	{
		throw std::out_of_range("");
	}
	return *(start_[row_i] + col_i);
}

MatrixL& MatrixL::operator=(const MatrixL& rhs)
{
	if (this != &rhs)
	{
		delete[] data_;
		delete[] start_;
		n_row_ = rhs.n_row_;
		n_col_ = rhs.n_col_;
		data_ = new float[n_row_ * n_col_];
		start_ = new float* [n_row_];
		std::copy(rhs.data_, rhs.data_ + rhs.n_row_ * rhs.n_col_, data_);
		std::copy(rhs.start_, rhs.start_ + rhs.n_row_, start_);
	}
	return *this;
}

void MatrixL::print()
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
