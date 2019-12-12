#ifndef DYNARRAYT_DYNARRAYT_H
#define DYNARRAYT_DYNARRAYT_H

#include <cstddef>

template<typename T>
class DynArrayT {
public:
	DynArrayT() = default;
	DynArrayT(const DynArrayT& arr);
	DynArrayT(const std::ptrdiff_t size);
	DynArrayT& operator=(const DynArrayT& rhs);
	~DynArrayT() { delete[] data_; }
	std::ptrdiff_t size() const { return size_; }
	T& operator[](const std::ptrdiff_t i);
	const T& operator[](const std::ptrdiff_t i) const;
	void resize(const std::ptrdiff_t size);
private:
	std::ptrdiff_t capacity_{ 0 };
	std::ptrdiff_t size_{ 0 };
	T* data_{ 0 };

};

template<typename T>
DynArrayT<T>::DynArrayT<T>(const DynArrayT<T>& obj) :
	capacity_(obj.capacity_),
	size_(obj.size_),
	data_(new T[capacity_]) {
	std::copy(obj.data_, obj.data_ + obj.size_, data_);
}

template<typename T>
DynArrayT<T>::DynArrayT<T>(const ptrdiff_t size) : capacity_(size), size_(size) {
	if (size < 0)
		throw std::invalid_argument("Change the size of array");
	data_ = new T[capacity_]{ 0 };
}

template<typename T>
DynArrayT<T>& DynArrayT<T>::operator=(const DynArrayT<T>& obj) {
	if (this != &obj) {
		delete[] data_;
		capacity_ = obj.capacity_;
		size_ = obj.size_;
		data_ = new T[capacity_]{ 0 };
		std::copy(obj.data_, obj.data_ + obj.size_, data_);
	}
	return *this;
}

template<typename T>
T& DynArrayT<T>::operator[] (const ptrdiff_t i) {
	if (i < 0 || size_ <= i)
		throw std::out_of_range("Index is out of range");
	return data_[i];
}

template<typename T>
const T& DynArrayT<T>::operator[] (const ptrdiff_t i) const {
	if (i < 0 || size_ <= i)
		throw std::out_of_range("Index is out of range");
	return data_[i];
}

template<typename T>
void DynArrayT<T>::resize(const ptrdiff_t new_size) {
	if (new_size < 0)
		throw std::invalid_argument("The size of array can not be negative");
	else if (new_size > capacity_) {
		T* buffer = new T[size_];
		std::copy(data_, data_ + size_, buffer);
		delete[] data_;
		capacity_ = new_size;
		data_ = new T[capacity_]{ 0 };
		std::copy(buffer, buffer + size_, data_);
		size_ = new_size;
		delete[] buffer;
	}
	else {
		size_ = new_size;
	}
}
#endif // !DYNARRAYT_DYNARRAYT_H

