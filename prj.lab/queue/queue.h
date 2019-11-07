#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <iostream>

class Queue
{
public:
	Queue();
	Queue(const Queue& obj);
	~Queue();
	Queue& operator=(const Queue& rhs);
	bool isEmpty() const;
	void push(const float& v);
	void pop();
	float& top();
	const float& top() const;

private:
	std::ptrdiff_t iTail{ 0 };
	std::ptrdiff_t iHead{ 0 };
	std::ptrdiff_t capacity_{ 8 };
	std::ptrdiff_t size_{ 0 };
	float* data_{ nullptr };
};
#endif // !QUEUE_QUEUE_H

