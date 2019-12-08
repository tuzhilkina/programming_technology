#include <ortosegm/ortosegm.h>
#include <iostream>


int main()
{
	OrtoSegm default_ = OrtoSegm();
	std::cout << "OrtoSegm default_ = OrtoSegm()\n";
	std::cout << "x = " << default_.x() << "   ";
	std::cout << "y = " << default_.y() << "   ";
	std::cout << "lx = " << default_.lx() << "   ";
	std::cout << "ly = " << default_.ly() << '\n';

	OrtoSegm params = OrtoSegm(1, 3, 6, 0);
	std::cout << "\nOrtoSegm params = OrtoSegm(1, 3, 6, 0)\n";
	std::cout << "x = " << params.x() << "   ";
	std::cout << "y = " << params.y() << "   ";
	std::cout << "lx = " << params.lx() << "   ";
	std::cout << "ly = " << params.ly() << '\n';

	OrtoSegm except = OrtoSegm(1, 3, -6, 0);
	std::cout << "\nOrtoSegm except = OrtoSegm(1, 3, -6, 0);\n";
	std::cout << "x = " << except.x() << "   ";
	std::cout << "y = " << except.y() << "   ";
	std::cout << "lx = " << except.lx() << "   ";
	std::cout << "ly = " << except.ly() << '\n';

	OrtoSegm copy = OrtoSegm(params);
	std::cout << "\nOrtoSegm copy = OrtoSegm(params);\n";
	std::cout << "x = " << copy.x() << "   ";
	std::cout << "y = " << copy.y() << "   ";
	std::cout << "lx = " << copy.lx() << "   ";
	std::cout << "ly = " << copy.ly() << '\n';

	OrtoSegm assign = OrtoSegm(2, 6, 0, 8);
	std::cout << "\nOrtoSegm assign = OrtoSegm(2, 6, 0, 8);\n";
	std::cout << "x = " << assign.x() << "   ";
	std::cout << "y = " << assign.y() << "   ";
	std::cout << "lx = " << assign.lx() << "   ";
	std::cout << "ly = " << assign.ly() << '\n';

	assign = params;
	std::cout << "\nassign = params;\n";
	std::cout << "x = " << assign.x() << "   ";
	std::cout << "y = " << assign.y() << "   ";
	std::cout << "lx = " << assign.lx() << "   ";
	std::cout << "ly = " << assign.ly() << '\n';

	params.move(-1, -3);
	std::cout << "\nparams.move(-1, -3);\n";
	std::cout << "x = " << params.x() << "   ";
	std::cout << "y = " << params.y() << "   ";
	std::cout << "lx = " << params.lx() << "   ";
	std::cout << "ly = " << params.ly() << '\n';

	OrtoSegm base = OrtoSegm(2, 2, 5, 0);
	OrtoSegm line = OrtoSegm(0, 2, 4, 0);
	OrtoSegm dot = OrtoSegm(3, 1, 0, 5);
	OrtoSegm nothing = OrtoSegm(-1, 3, 0, 1);


	OrtoSegm intersect2 = base.intersect(line);
	std::cout << "\nOrtoSegm intersect2 = base.intersect(line);\n";
	std::cout << "x = " << intersect2.x() << "   ";
	std::cout << "y = " << intersect2.y() << "   ";
	std::cout << "lx = " << intersect2.lx() << "   ";
	std::cout << "ly = " << intersect2.ly() << '\n';

	OrtoSegm intersect3 = base.intersect(dot);
	std::cout << "\nOrtoSegm intersect3 = base.intersect(dot);\n";
	std::cout << "x = " << intersect3.x() << "   ";
	std::cout << "y = " << intersect3.y() << "   ";
	std::cout << "lx = " << intersect3.lx() << "   ";
	std::cout << "ly = " << intersect3.ly() << '\n';

	OrtoSegm intersect4 = base.intersect(nothing);
	std::cout << "\nOrtoSegm intersect4 = base.intersect(nothing);\n";
	std::cout << "x = " << intersect4.x() << "   ";
	std::cout << "y = " << intersect4.y() << "   ";
	std::cout << "lx = " << intersect4.lx() << "   ";
	std::cout << "ly = " << intersect4.ly() << '\n';
}

