#include <stackl/stackl.h>

StackL::StackL(const StackL& rhs) {
	if (!rhs.is_empty()) {
		head_ = new Node{ rhs.head_->data_, nullptr };
		Node* rhsIterator = rhs.head_;
		Node* thisIterator = head_;
		while (rhsIterator->next_ != nullptr) {
			rhsIterator = rhsIterator->next_;
			thisIterator->next_ = new Node{ rhsIterator->data_, nullptr };
			if (thisIterator->next_ != nullptr) {
				thisIterator = thisIterator->next_;
			}
		}
	}
}

StackL& StackL::operator=(const StackL& rhs) {
	if (&rhs == this) { return *this; }
	StackL boofer(rhs);
	Node* booferHead = boofer.head_;
	boofer.head_ = head_;
	head_ = booferHead;
	return (*this);
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

