#include <iostream>
#include <stack/stack.h>

int main()
{
	std::cout << "Stack()\n";
	Stack test = Stack();
	std::cout << "isEmpty(): " << test.isEmpty() << '\n';
	std::cout << "Pushing values\n";
	test.push(5);
	test.push(7);
	test.push(1);
	test.push(8);
	test.push(3);
	test.push(6);
	test.push(0);
	test.push(4);
	test.push(1);
	test.push(1);
	test.push(2);
	test.push(0);
	test.push(1);
	test.push(9);
	test.print();

	std::cout << "Stack(const Stack& rhs)\n";
	Stack t1 = Stack(test);
	t1.print();

	std::cout << "Pushing values: 7, 3\n";
	t1.push(7);
	t1.push(3);

	std::cout << "Stack& operator=(const Stack& rhs)\n";
	test = t1;
	test.print();

	std::cout << "Popping 3 values\n";
	test.pop();
	test.pop();
	test.pop();
	test.print();

	std::cout << "Getting the top\n";
	std::cout << test.top() << '\n';
	std::cout << "isEmpty(): " << test.isEmpty() << '\n';

	std::cout << "Destructing\n";
	test.~Stack();
}

