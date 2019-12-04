#pragma once
#ifndef ORTOSEGM_ORTOSEGM_H
#define ORTOSEGM_ORTOSEGM_H

class OrtoSegm {
public:
	OrtoSegm() = default;
	~OrtoSegm() = default;
	OrtoSegm(const OrtoSegm& rhs) = default;
	OrtoSegm& operator=(const OrtoSegm& rhs) = default;
	OrtoSegm(const float& x, const float& y, const float& lx, const float& ly);

	void move(const float& x, const float& y);
	OrtoSegm intersect(const OrtoSegm& rhs);

	float x() const { return x_; };
	float y() const { return y_; };
	float lx() const { return lx_; };
	float ly() const { return ly_; };

private:
	float x_{ 0 };
	float y_{ 0 };
	float lx_{ 0 };
	float ly_{ 0 };
};

#endif