#include <iostream>
#include <matrixl/matrixl.h>

int main()
{
	std::cout << "MatrixL()\n";
	MatrixL t0 = MatrixL();
	std::cout << "MatrixL(const MatrixL& rhs)\n";
	MatrixL t1 = MatrixL(2, 3);
	std::cout << "row_count = " << t1.row_count() << '\n';
	std::cout << "col_count = " << t1.col_count() << '\n';
	t1.at(0, 0) = 2;
	t1.at(0, 1) = 4;
	t1.at(0, 2) = 3;
	t1.at(1, 0) = 5;
	t1.at(1, 1) = 8;
	t1.at(1, 2) = 0;
	t1.print();
	std::cout << "MatrixL(const MatrixL& rhs)\n";
	MatrixL t2 = MatrixL(t1);
	std::cout << "at(0, 0) = 7\n";
	t2.at(0, 0) = 7;
	t2.print();
	std::cout << "MatrixL& operator=(const MatrixL& rhs)\n";
	t0 = t2;
	t0.print();
}