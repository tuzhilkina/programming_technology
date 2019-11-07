#include <iostream>
#include <queue/queue.h>

int main()
{
	std::cout << "Queue()\n";
	Queue t0 = Queue();
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

	std::cout << "Queue(const Queue& obj)\n";
	Queue t1 = Queue(t0);
	std::cout << "Getting the top\n";
	std::cout << t1.top() << '\n';

	std::cout << "operator=(const Queue& rhs)\n";
	Queue t3 = Queue();
	t3 = t1;

	std::cout << "Pushing values\n";
	Queue t2 = Queue();
	t2.push(1);
	t2.push(7);
	std::cout << "IsEmpty(): " << t2.isEmpty() << '\n';
	std::cout << "Popping values\n";
	t2.pop();
	t2.pop();
	std::cout << "IsEmpty(): " << t2.isEmpty() << '\n';
	std::cout << "Getting the top\n";
	std::cout << t2.top() << '\n';
}
