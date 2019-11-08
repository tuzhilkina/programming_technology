#include <stack/stack.h>
#include <iostream>

Stack::Stack(const Stack& rhs)
{
	std::ptrdiff_t size(10);
	float* data_(nullptr);
	data_ = new float[size];
	std::ptrdiff_t count(0);
	Node* current = rhs.head;
	while (current->next != nullptr)
	{
		if (count >= size)
		{
			float* temp = new float[size * 2];
			std::copy(data_, data_ + size, temp);
			delete[] data_;
			data_ = new float[size * 2];
			std::copy(temp, temp + size, data_);
			size *= 2;
			delete[] temp;
		}
		data_[count] = current->data;
		++count;
		current = current->next;
	}
	data_[count] = current->data;
	for (ptrdiff_t i(count); i >= 0; --i)
		push(data_[i]);
}

Stack& Stack::operator=(const Stack& rhs)
{
	if (this != &rhs)
	{
		while (!isEmpty())
			pop();

		std::ptrdiff_t size(10);
		float* data_(nullptr);
		data_ = new float[size];
		std::ptrdiff_t count(0);
		Node* current = rhs.head;
		while (current->next != nullptr)
		{
			if (count >= size)
			{
				float* temp = new float[size * 2];
				std::copy(data_, data_ + size, temp);
				delete[] data_;
				data_ = new float[size * 2];
				std::copy(temp, temp + size, data_);
				size *= 2;
				delete[] temp;
			}
			data_[count] = current->data;
			++count;
			current = current->next;
		}
		data_[count] = current->data;
		for (ptrdiff_t i(count); i >= 0; --i)
			push(data_[i]);
	}
	return *this;
}

Stack::~Stack()
{
	while (!isEmpty())
		pop();
}

void Stack::push(const float& rhs)
{
	head = new Node{ rhs, head };
}

void Stack::pop()
{
	if (!isEmpty())
	{
		Node* kill = head;
		head = head->next;
		delete kill;
	}
}

bool Stack::isEmpty()
{
	return (nullptr == head);
}

float& Stack::top()
{
	if (isEmpty())
		throw std::logic_error("Stack does not contain values");
	return head->data;
}

void Stack::print() const
{
	std::ptrdiff_t count(0);
	Node* current = head;
	while (current->next != nullptr)
	{
		std::cout << current->data;
		++count;
		current = current->next;
	}
	std::cout << current->data << '\n';
}

