#ifndef DYNARRAY_DYNARRAY_H
#define DYNARRAY_DYNARRAY_H

#include <cstddef>

class DynArray {
public:
	DynArray() = default;
	DynArray(const DynArray& arr);
	DynArray(const std::ptrdiff_t size);
	DynArray& operator=(const DynArray& rhs);
	~DynArray() { delete[] data_; }
	std::ptrdiff_t size() const { return size_; }
	float& operator[](const std::ptrdiff_t i);
	const float& operator[](const std::ptrdiff_t i) const;
	void resize(const std::ptrdiff_t size);
private:
	std::ptrdiff_t capacity_{ 0 };
	std::ptrdiff_t size_{ 0 };
	float* data_{ 0 };

};
#endif // !DYNARRAY_DYNARRAY_H

