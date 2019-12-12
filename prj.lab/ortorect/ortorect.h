#pragma once
#ifndef ORTORECT_ORTORECT_H
#define ORTORECT_ORTORECT_H

class OrtoRect {
public:
	OrtoRect() = default;
	~OrtoRect() = default;
	OrtoRect(const OrtoRect& rhs) = default;
	OrtoRect& operator=(const OrtoRect& rhs) = default;
	OrtoRect(const float& x, const float& y, const float& lx, const float& ly);

	void move(const float& x, const float& y);
	OrtoRect intersect(const OrtoRect& rhs);

	float x() const { return x_; };
	float y() const { return y_; };
	float wide() const { return lx_; };
	float height() const { return ly_; };

private:
	float x_{ 0 };
	float y_{ 0 };
	float lx_{ 0 };
	float ly_{ 0 };
};

#endif