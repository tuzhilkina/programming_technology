#include <iostream>
#include <QueueA/QueueA.h>

int main()
{

	QueueA q;
	QueueA q_copy(q);
	std::cout << q_copy.is_empty() << '\n';

	q.push(9);
	std::cout << !q.is_empty() << '\n';
	QueueA q_copy_1(q);
	std::cout << !q_copy_1.is_empty() << '\n';
	q.pop();
	std::cout << q.is_empty() << '\n';

	std::cout << "QueueA()\n";
	QueueA t0 = QueueA();
	std::cout << "Pushing values\n";
	t0.push(1);
	t0.push(1);
	t0.push(0);
	t0.push(3);
	t0.push(1);
	t0.push(1);
	t0.push(2);
	t0.push(0);
	std::cout << "Popping values\n";
	t0.pop();
	t0.pop();
	std::cout << "Pushing values\n";
	t0.push(1);
	t0.push(9);
	t0.push(2);
	t0.push(1);
	t0.push(5);
	t0.push(2);

	std::cout << "QueueA(const QueueA& obj)\n";
	QueueA t1 = QueueA(t0);
	std::cout << "Getting the top\n";
	std::cout << t1.top() << '\n';

	std::cout << "operator=(const QueueA& rhs)\n";
	QueueA t3 = QueueA();
	t3 = t1;

	std::cout << "Pushing values\n";
	QueueA t2 = QueueA();
	t2.push(1);
	t2.push(7);
	std::cout << "IsEmpty(): " << t2.is_empty() << '\n';
	std::cout << "Popping values\n";
	t2.pop();
	t2.pop();
	std::cout << "IsEmpty(): " << t2.is_empty() << '\n';
	std::cout << "Getting the top\n";
	std::cout << t2.top() << '\n';
}
