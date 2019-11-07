#include <queue/queue.h>
#include <iostream>

Queue::Queue()
{
	data_ = new float[capacity_];
}

Queue::~Queue()
{
	delete[] data_;
}

Queue::Queue(const Queue& obj) : capacity_(obj.capacity_), size_(obj.size_), data_(new float[capacity_]), iHead(obj.iHead), iTail(obj.iTail)
{
	std::copy(obj.data_, obj.data_ + capacity_, data_);
}


void Queue::push(const float& v)
{
	if (size_ >= capacity_)
	{
		float* temp = new float[size_];
		std::copy(&data_[iTail], data_ + size_, temp);
		std::copy(data_, &data_[iHead], temp + capacity_ - iHead);
		capacity_ *= 2;
		delete[] data_;
		data_ = new float[capacity_];
		std::copy(temp, temp + size_, data_);
		iHead = 0;
		iTail = size_;
	}
	size_ += 1;
	data_[iTail] = v;
	iTail = (iTail + 1) % capacity_;
}

void Queue::pop()
{
	if (!isEmpty())
	{
		size_ -= 1;
		iHead = (iHead + 1) % capacity_;
	}
}

float& Queue::top()
{
	if (!isEmpty())
		return data_[iHead];
}

const float& Queue::top() const
{
	if (isEmpty())
		throw std::logic_error("Queue doesn't contain values");

	return data_[iHead];
}

bool Queue::isEmpty() const
{
	return (0 == size_);
}

Queue& Queue::operator=(const Queue& rhs)
{
	if (this != &rhs)
	{
		iHead = rhs.iHead;
		iTail = rhs.iTail;
		size_ = rhs.size_;
		capacity_ = rhs.capacity_;
		delete[] data_;
		data_ = new float[capacity_];
		std::copy(rhs.data_, rhs.data_ + capacity_, data_);
	}
	return *this;
}