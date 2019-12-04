#include <stackl/stackl.h>
#include <iostream>

StackL::StackL(const StackL& rhs) {
	std::ptrdiff_t size(10);
	float* data__(nullptr);
	data__ = new float[size];
	std::ptrdiff_t count(0);
	Node* current = rhs.head_;
	while (current->next_ != nullptr)
	{
		if (count >= size)
		{
			float* temp = new float[size * 2];
			std::copy(data__, data__ + size, temp);
			delete[] data__;
			data__ = new float[size * 2];
			std::copy(temp, temp + size, data__);
			size *= 2;
			delete[] temp;
		}
		data__[count] = current->data_;
		++count;
		current = current->next_;
	}
	data__[count] = current->data_;
	for (ptrdiff_t i(count); i >= 0; --i)
		push(data__[i]);
}

StackL& StackL::operator=(const StackL& rhs) {
	if (this != &rhs)
	{
		while (!is_empty())
			pop();

		std::ptrdiff_t size(10);
		float* data__(nullptr);
		data__ = new float[size];
		std::ptrdiff_t count(0);
		Node* current = rhs.head_;
		if (rhs.head_ != nullptr) {
			while (current->next_ != nullptr)
			{
				if (count >= size)
				{
					float* temp = new float[size * 2];
					std::copy(data__, data__ + size, temp);
					delete[] data__;
					data__ = new float[size * 2];
					std::copy(temp, temp + size, data__);
					size *= 2;
					delete[] temp;
				}
				data__[count] = current->data_;
				++count;
				current = current->next_;
			}
			data__[count] = current->data_;
			for (ptrdiff_t i(count); i >= 0; --i)
				push(data__[i]);
		}
	}
	return *this;
}

StackL::~StackL() {
	while (!is_empty())
		pop();
}

void StackL::push(const float value) {
	head_ = new Node{ value, head_ };
}

void StackL::pop() {
	if (!is_empty())
	{
		Node* kill = head_;
		head_ = head_->next_;
		delete kill;
	}
}

float& StackL::top() {
	if (is_empty())
		throw std::logic_error("StackL does not contain values");
	return head_->data_;
}

const float& StackL::top() const {
	if (is_empty())
		throw std::logic_error("StackL does not contain values");
	return head_->data_;
}

bool StackL::is_empty() const {
	return (nullptr == head_);
}

