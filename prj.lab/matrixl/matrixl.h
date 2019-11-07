#pragma once
#ifndef MATRIXL_MATRIXL_H
#define MATRIXL_MATRIXL_H

#include <iostream>

class MatrixL
{
public:
	MatrixL() = default;
	MatrixL(const MatrixL& rhs);
	MatrixL(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count);
	~MatrixL();
	MatrixL& operator=(const MatrixL& rhs);

	std::ptrdiff_t row_count() const { return n_row_; }
	std::ptrdiff_t col_count() const { return n_col_; }
	float& at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i);
	const float& at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i) const;
	void print();

private:
	std::ptrdiff_t n_row_{ 0 };
	std::ptrdiff_t n_col_{ 0 };
	float* data_{ nullptr };
	float** start_{ nullptr };
};

#endif