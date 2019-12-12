#include <QueueA/QueueA.h>


QueueA::QueueA(const QueueA& obj)
	: capacity_(obj.capacity_)
	, size_(obj.size_)
	, iHead(obj.iHead)
	, iTail(obj.iTail)
{
	if (size_ > 0) {
		data_ = new float[capacity_] {0.0f};
		std::copy(obj.data_, obj.data_ + capacity_, data_);
	}
}

QueueA& QueueA::operator=(const QueueA& obj) {
	if (this != &obj) {
		if (size_ < obj.size_) {
			delete[] data_;
			float* boofer(new float[obj.size_]{ 0.0f });
			data_ = boofer;
		}
		size_ = obj.size_;
		std::copy(obj.data_, obj.data_ + obj.size_, data_);
	}
	return *this;
}

QueueA::~QueueA() {
	delete[] data_;
}

void QueueA::push(const float value) {
	if (iHead == iTail) {
		float* boofer(new float[capacity_ * 2]{ 0.0f });
		if (iTail == 0) 
			std::copy(data_, data_ + size_, boofer); 
		else {
			std::copy(data_ + iHead, data_ + size_, boofer);
			std::copy(data_, data_ + iTail, boofer + size_ - iHead);
		}
		iHead = 0;
		iTail = size_;
		++size_;
		delete[] data_;
		data_ = boofer;
	}
	data_[iTail] = value;
	iTail = (iTail + 1) % size_;
}

void QueueA::pop() {
	if (!is_empty()) {
		iHead = (iHead + 1) % size_;
		if (iHead == iTail) {
			delete[] data_;
			size_ = 0;
			data_ = nullptr;
		}
	}
}

float& QueueA::top() {
	if (is_empty()) {
		throw std::logic_error("");
	}
	return data_[iHead];
}

const float& QueueA::top() const {
	if (is_empty()) {
		throw std::logic_error("");
	}
	return data_[iHead];
}

bool QueueA::is_empty() const {
	return (0 == size_);
}