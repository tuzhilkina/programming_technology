#include <ortorect/ortorect.h>
#include <iostream>


int main()
{
	OrtoRect default_ = OrtoRect();
	std::cout << "OrtoRect default_ = OrtoRect()\n";
	std::cout << "x = " << default_.x() << "   ";
	std::cout << "y = " << default_.y() << "   ";
	std::cout << "wide = " << default_.wide() << "   ";
	std::cout << "height = " << default_.height() << '\n';

	OrtoRect params = OrtoRect(1, 3, 6, 7);
	std::cout << "\nOrtoRect params = OrtoRect(1, 3, 6, 7)\n";
	std::cout << "x = " << params.x() << "   ";
	std::cout << "y = " << params.y() << "   ";
	std::cout << "wide = " << params.wide() << "   ";
	std::cout << "height = " << params.height() << '\n';

	std::cout << "\nOrtoRect except = OrtoRect(1, 3, -6, -7);\n";
	try {
		OrtoRect except = OrtoRect(1, 3, -6, -7);
		std::cout << "x = " << except.x() << "   ";
		std::cout << "y = " << except.y() << "   ";
		std::cout << "wide = " << except.wide() << "   ";
		std::cout << "height = " << except.height() << '\n';
	}
	catch (std::invalid_argument) {
		std::cout << "Wide and height can not be negative\n";
	}

	OrtoRect copy = OrtoRect(params);
	std::cout << "\nOrtoRect copy = OrtoRect(params);\n";
	std::cout << "x = " << copy.x() << "   ";
	std::cout << "y = " << copy.y() << "   ";
	std::cout << "wide = " << copy.wide() << "   ";
	std::cout << "height = " << copy.height() << '\n';

	OrtoRect assign = OrtoRect(2, 6, 3, 8);
	std::cout << "\nOrtoRect assign = OrtoRect(2, 6, 3, 8);\n";
	std::cout << "x = " << assign.x() << "   ";
	std::cout << "y = " << assign.y() << "   ";
	std::cout << "wide = " << assign.wide() << "   ";
	std::cout << "height = " << assign.height() << '\n';

	assign = params;
	std::cout << "\nassign = params;\n";
	std::cout << "x = " << assign.x() << "   ";
	std::cout << "y = " << assign.y() << "   ";
	std::cout << "wide = " << assign.wide() << "   ";
	std::cout << "height = " << assign.height() << '\n';

	params.move(-1, -3);
	std::cout << "\nparams.move(-1, -3);\n";
	std::cout << "x = " << params.x() << "   ";
	std::cout << "y = " << params.y() << "   ";
	std::cout << "wide = " << params.wide() << "   ";
	std::cout << "height = " << params.height() << '\n';

	OrtoRect base = OrtoRect(1, 1, 3, 2);
	OrtoRect rect = OrtoRect(3, 2, 2, 4);
	OrtoRect line = OrtoRect(2, -3, 4, 4);
	OrtoRect dot = OrtoRect(0, 3, 1, 1);
	OrtoRect nothing = OrtoRect(0, -1, 1, 1);

	OrtoRect intersect1 = base.intersect(rect);
	std::cout << "\nOrtoRect intersect1 = base.intersect(rect);\n";
	std::cout << "x = " << intersect1.x() << "   ";
	std::cout << "y = " << intersect1.y() << "   ";
	std::cout << "wide = " << intersect1.wide() << "   ";
	std::cout << "height = " << intersect1.height() << '\n';

	OrtoRect intersect2 = base.intersect(line);
	std::cout << "\nOrtoRect intersect2 = base.intersect(line);\n";
	std::cout << "x = " << intersect2.x() << "   ";
	std::cout << "y = " << intersect2.y() << "   ";
	std::cout << "wide = " << intersect2.wide() << "   ";
	std::cout << "height = " << intersect2.height() << '\n';

	OrtoRect intersect3 = base.intersect(dot);
	std::cout << "\nOrtoRect intersect3 = base.intersect(dot);\n";
	std::cout << "x = " << intersect3.x() << "   ";
	std::cout << "y = " << intersect3.y() << "   ";
	std::cout << "wide = " << intersect3.wide() << "   ";
	std::cout << "height = " << intersect3.height() << '\n';

	OrtoRect intersect4 = base.intersect(nothing);
	std::cout << "\nOrtoRect intersect4 = base.intersect(nothing);\n";
	std::cout << "x = " << intersect4.x() << "   ";
	std::cout << "y = " << intersect4.y() << "   ";
	std::cout << "wide = " << intersect4.wide() << "   ";
	std::cout << "height = " << intersect4.height() << '\n';
}

