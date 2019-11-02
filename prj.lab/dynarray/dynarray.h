#ifndef DYNARRAY_DYNARRAY_H
#define DYNARRAY_DYNARRAY_H

#include <iostream>

class dynArray
{
public:
	dynArray() = default;
	dynArray(const ptrdiff_t size);
	dynArray(const dynArray& obj);
	~dynArray();
	dynArray& operator=(const dynArray& obj);
	ptrdiff_t size() const;
	float& operator[] (const ptrdiff_t i);
	const float& operator[] (const ptrdiff_t i) const;
	void resize(const ptrdiff_t new_size);

private:
	ptrdiff_t capacity_{ 0 };
	ptrdiff_t size_{ 0 };
	float* data_{ nullptr };
};

#endif // !DYNARRAY_DYNARRAY_H

