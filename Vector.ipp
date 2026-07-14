#include "Vector.hpp"
#include <stdexcept>
#include <vector>
#include <math.h>

template<typename T>
Vector<T>::Vector() noexcept : size(0), data(nullptr)
{
}

template<typename T>
Vector<T>::Vector(size_t size) noexcept : size(size), data(std::make_unique<T[]>(size)) 
{
	for (size_t i = 0; i < size; i++)
	{
		data[i] = static_cast<T>(0);
	}
}

template<typename T>
Vector<T>::Vector(size_t size, const T& value) noexcept : size(size), data(std::make_unique<T[]>(size)) 
{
	for (size_t i = 0; i < size; i++)
	{
		data[i] = value;
	}
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> list) noexcept : size(list.size()), data(std::make_unique<T[]>(size))
{
	size_t i = 0;
	for (const T& item : list)
	{
		data[i++] = item;
	}
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other) noexcept : size(other.size), data(std::make_unique<T[]>(size))
{
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
size_t Vector<T>::getSize() const noexcept
{
	return size;
}	

template<typename T>
void	Vector<T>::add(const Vector<T>& other)
{
	if (size != other.size)
		throw std::invalid_argument("Vectors must be of the same size for addition.");
	for (size_t i = 0; i < size; ++i)
		data[i] += other.data[i];
}

template<typename T>
void	Vector<T>::sub(const Vector<T>& other)
{
	if (size != other.size)
		throw std::invalid_argument("Vectors must be of the same size for subtraction.");
	for (size_t i = 0; i < size; ++i)
		data[i] -= other.data[i];
}

template<typename T>
T	Vector<T>::dot(const Vector<T>& other) const
{
	if (size != other.size)
		throw std::invalid_argument("Vectors must be of the same size for dot product.");
	T result = static_cast<T>(0);
	for (size_t i = 0; i < size; ++i)
		result += data[i] * other.data[i];
	return result;
}

template<typename T>
void	Vector<T>::scl(const T& scalar) noexcept
{
	for (size_t i = 0; i < size; ++i)
		data[i] *= scalar;
}

template<typename T>
Vector<T> Vector<T>::operator+(const T& value) noexcept
{
	Vector<T> temp(size, value);
	temp.add(Vector<T>(size, value));
	return temp;
}

template<typename T>
Vector<T> Vector<T>::operator-(const T& value) noexcept
{
	Vector<T> temp(size, value);
	temp.sub(Vector<T>(size, value));
	return temp;
}

template<typename T>
Vector<T> Vector<T>::operator*(const T& value) noexcept
{
	Vector<T> temp(size, value);
	temp.scl(value);
	return temp;
}


template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other)
{
	Vector<T> temp(size);
	temp.add(other);
	return temp;
}

template<typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& other)
{
	Vector<T> temp(size);
	temp.sub(other);
	return temp;
}

template<typename T>
Vector<T> Vector<T>::operator=(const Vector<T>& other)
{
	if (this == &other)
		return *this;
	size = other.size;
	data = std::make_unique<T[]>(size);
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
	return *this;
}

template<typename T>
T& Vector<T>::operator[](size_t index)
{
	if (index >= size)
		throw std::out_of_range("Index out of range.");
	return data[index];
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const
{
	if (index >= size)
		throw std::out_of_range("Index out of range.");
	return data[index];
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vec)
{
	for (size_t i = 0; i < vec.getSize(); ++i)
		os << vec[i] << " ";
	return os;
}

template<typename T>
T Vector<T>::norm_1() const
{
	T result = static_cast<T>(0);
	for (size_t i = 0; i < size; ++i)
		result += std::abs(data[i]);
	return result;
}

template<typename T>
T Vector<T>::norm() const
{
	T result = static_cast<T>(0);
	for (size_t i = 0; i < size; ++i)
		result += data[i] * data[i];
	return std::sqrt(result);
}

template<typename T>
T Vector<T>::norm_inf() const
{
	T result = static_cast<T>(0);
	for (size_t i = 0; i < size; ++i)
	{
		T abs_val = std::abs(data[i]);
		if (abs_val > result)
			result = abs_val;
	}
	return result;
}
