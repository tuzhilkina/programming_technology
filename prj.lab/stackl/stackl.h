#pragma once
#ifndef STAKL_STAKL_H
#define STAKL_STAKL_H

#include <memory>

class StackL {
public:
	StackL() = default;
	StackL(const StackL& rhs);
	StackL& operator=(const StackL& rhs);
	~StackL();
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
	Node* head_{ nullptr };
};

#endif