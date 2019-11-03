#include <dynarray/dynarray.h>
#include <iostream>

dynArray::dynArray(const ptrdiff_t size) : capacity_(size), size_(size)
{
	if (size < 0)
		throw std::invalid_argument("Change the size of array");
	data_ = new float[capacity_];
}

dynArray::~dynArray()
{
	delete[] data_;
}

dynArray::dynArray(const dynArray& obj) :
	capacity_(obj.capacity_),
	size_(obj.size_),
	data_(new float[capacity_])
{
	std::copy(obj.data_, obj.data_ + obj.size_, data_);
}

dynArray& dynArray::operator=(const dynArray& obj)
{
	if (this != &obj)
	{
		delete[] data_;
		capacity_ = obj.capacity_;
		size_ = obj.size_;
		data_ = new float[capacity_];
		std::copy(obj.data_, obj.data_ + obj.size_, data_);
	}
	return *this;
}

float& dynArray::operator[] (const ptrdiff_t i)
{
	if (i < 0 || size_ <= i)
		throw std::out_of_range("Index is out of range");
	return data_[i];
}

const float& dynArray::operator[] (const ptrdiff_t i) const
{
	if (i < 0 || size_ <= i)
		throw std::out_of_range("Index is out of range");
	return data_[i];
}

ptrdiff_t dynArray::size() const
{
	return size_;
}

void dynArray::resize(const ptrdiff_t new_size)
{
	if (new_size < 0)
		throw std::invalid_argument("The size of array can not be negative");
	else if (new_size > capacity_)
	{
		float* buffer = new float[size_];
		std::copy(data_, data_ + size_, buffer);
		delete[] data_;
		capacity_ = new_size;
		data_ = new float[capacity_];
		std::copy(buffer, buffer + size_, data_);
		size_ = new_size;
		delete[] buffer;
	}
	else
	{
		size_ = new_size;
	}
}
