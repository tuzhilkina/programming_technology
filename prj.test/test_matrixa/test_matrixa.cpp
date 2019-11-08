#include <iostream>
#include <cstddef>
#include <memory>
#include <matrixa/matrixa.h>

int main()
{
	std::cout << "MatrixA()\n";
	MatrixA t0 = MatrixA();
	std::cout << "MatrixA(const MatrixA& rhs)\n";
	MatrixA t1 = MatrixA(2, 3);
	std::cout << "row_count = " << t1.row_count() << '\n';
	std::cout << "col_count = " << t1.col_count() << '\n';
	t1.at(0, 0) = 2;
	t1.at(0, 1) = 4;
	t1.at(0, 2) = 3;
	t1.at(1, 0) = 5;
	t1.at(1, 1) = 8;
	t1.at(1, 2) = 0;
	t1.print();
	std::cout << "MatrixA(const MatrixA& rhs)\n";
	MatrixA t2 = MatrixA(t1);
	t2.at(0, 0) = 7;
	t2.print();
	std::cout << "MatrixA& operator=(const MatrixA& rhs)\n";
	t0 = t2;
	t0.print();
}
