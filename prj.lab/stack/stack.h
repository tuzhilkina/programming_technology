#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <iostream>

class Stack
{
public:
	Stack() = default;
	Stack(const Stack& rhs);
	Stack& operator=(const Stack& rhs);
	~Stack();

	void push(const float& rhs);
	void pop();
	bool isEmpty();
	float& top();
	const float& top() const;
	void print() const;

private:
	struct Node
	{
		float data{ 0.0f };
		Node* next{ nullptr };
	};
	Node* head{ nullptr };
};


#endif // !STACK_STACK_H

