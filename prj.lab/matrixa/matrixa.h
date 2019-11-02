#pragma once
#ifndef MATRIXA_MATRIXA_H
#define MATRIXA_MATRIXA_H

#include <iostream>
#include <cstddef>
#include <memory>


class MatrixA
{
public:
	MatrixA() = default; //ready
	MatrixA(const MatrixA& rhs); //ready
	MatrixA(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count); //ready
	~MatrixA() = default; //ready
	MatrixA& operator=(const MatrixA& rhs);

	//MatrixA(MatrixA&&) = default;
	//MatrixA& operator=(MatrixA&&) = default;

	std::ptrdiff_t row_count() const { return n_row_; } //ready
	std::ptrdiff_t col_count() const { return n_col_; } //ready
	float& at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i); //ready
	const float& at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i) const; //ready
	void print();


private:
	std::ptrdiff_t n_row_{ 0 };
	std::ptrdiff_t n_col_{ 0 };
	std::unique_ptr<float[]> data_;

};

#endif