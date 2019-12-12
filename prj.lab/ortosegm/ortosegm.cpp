#include <iostream>
#include <limits>
#include <ortosegm/ortosegm.h>

OrtoSegm::OrtoSegm(const float& x, const float& y, const float& lx, const float& ly) : x_(x), y_(y), lx_(lx), ly_(ly) {
	if (lx_ != 0 && ly_ != 0)
		throw std::invalid_argument("");
	if (lx_ < 0) {
		x_ += lx_;
		lx_ = -lx_;
	}
	if (ly_ < 0) {
		y_ += ly_;
		ly_ = -ly_;
	}
}

void OrtoSegm::move(const float& x, const float& y) {
	x_ = x;
	y_ = y;
}

OrtoSegm OrtoSegm::intersect(const OrtoSegm& rhs) {
	float left = x_ > rhs.x_ ? x_ : rhs.x_;
	float bottom = y_ > rhs.y_ ? y_ : rhs.y_;
	float right = x_ + lx_ < rhs.x_ + rhs.lx_ ? x_ + lx_ : rhs.x_ + rhs.lx_;
	float top = y_ + ly_ < rhs.y_ + rhs.ly_ ? y_ + ly_ : rhs.y_ + rhs.ly_;

	OrtoSegm result;
	
	if (left > right || bottom > top) {
		constexpr double value = std::numeric_limits<double>::lowest();
		result = OrtoSegm(0, 0, value, 0);
	}
	else result = OrtoSegm(left, bottom, right - left, top - bottom);
	return result;
}