#ifndef QUEUEA_QUEUEA_H
#define QUEUEA_QUEUEA_H

#include <iostream>
#include <stdexcept>
class QueueA
{
public:
	QueueA() = default;
	QueueA(const QueueA&);
	QueueA& operator=(const QueueA&);
	~QueueA();
	void push(const float value);
	void pop();
	float& top();
	const float& top() const;
	bool is_empty() const;

private:
	std::ptrdiff_t capacity_{ 8 };
	std::ptrdiff_t size_{ 0 };
	std::ptrdiff_t iHead{ 0 };
	std::ptrdiff_t iTail{ 0 };
	float* data_{ nullptr };
};
#endif // !QUEUEA_QUEUEA_H
