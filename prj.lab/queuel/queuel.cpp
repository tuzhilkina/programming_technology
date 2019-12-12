#include <queuel/queuel.h>


QueueL::QueueL(const QueueL& rhs) {
	if (!rhs.is_empty()) {
		beginning_ = new Node{ rhs.beginning_->data_, nullptr };
		end_ = beginning_;
		Node* thisIterator = beginning_;
		Node* rhsIterator = rhs.beginning_;
		while (rhsIterator->next_ != nullptr) {
			rhsIterator = rhsIterator->next_;
			thisIterator->next_ = new Node{ rhsIterator->data_, nullptr };
			thisIterator = thisIterator->next_;
			if (rhsIterator->next_ == nullptr)
				end_ = thisIterator;
		}
	}
}

QueueL& QueueL::operator=(const QueueL& rhs) {
	if (this != &rhs) {
		while (!is_empty())
			pop();
		QueueL boofer = QueueL(rhs);
		Node* booferbeginning = boofer.beginning_;
		boofer.beginning_ = beginning_;
		beginning_ = booferbeginning;
	}
	return *this;
}

QueueL::~QueueL() {
	while (!is_empty()) {
		pop();
	}
}

void QueueL::push(float value) {
	if (is_empty()) {
		end_ = new Node{ value, nullptr };
		beginning_ = end_;
	}
	else {
		end_->next_ = new Node{ value, nullptr };
		end_ = end_->next_;
	}
}

void QueueL::pop() {
	if (!is_empty()) {
		Node* kill = beginning_;
		beginning_ = beginning_->next_;
		delete kill;
	}
	if (beginning_ == nullptr)
		end_ = nullptr;
}

bool QueueL::is_empty() const {
	return (nullptr == beginning_);
}

float& QueueL::top() {
	if (is_empty())
		throw std::logic_error("QueueL does not contain values");
	return beginning_->data_;
}
const float& QueueL::top() const {
	if (is_empty())
		throw std::logic_error("QueueL does not contain values");
	return beginning_->data_;
}