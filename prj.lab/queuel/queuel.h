#ifndef QUEUEL_QUEUEL_H
#define QUEUEL_QUEUEL_H

#include <iostream>
#include <stdexcept>
class QueueL
{
public:
	QueueL() = default;
	QueueL(const QueueL&);
	QueueL& operator=(const QueueL&);
	~QueueL();
	void push(const float value);
	void pop();
	float& top();
	const float& top() const;
	bool is_empty() const;

private:
	struct Node
	{
		float data_{ 0.0f };
		Node* next_{ nullptr };
	};
	Node* end_{ nullptr };
	Node* beginning_{ nullptr };
};
#endif 
