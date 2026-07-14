#ifndef	VECTOR_HPP
#define	VECTOR_HPP

#include <cstddef>
#include <initializer_list>
#include <ostream>
#include <memory>

template<typename T>
class Vector
{
	private:

		size_t				size;
		std::unique_ptr<T[]>	data;

	public:
		Vector() noexcept;
		Vector(size_t	size) noexcept;
		Vector(size_t	size, const T& value) noexcept;
		Vector(std::initializer_list<T> list) noexcept;
		Vector(const Vector<T>& other) noexcept;
		~Vector() = default;

		size_t getSize() const noexcept;

		void	add(const Vector<T>& other);
		void	sub(const Vector<T>& other);
		void	scl(const T& scalar) noexcept;

		T	dot(const Vector<T>& other) const;

		Vector<T> operator+(const T& value) noexcept;
		Vector<T> operator-(const T& value) noexcept;
		Vector<T> operator*(const T& value) noexcept;

		Vector<T> operator+(const Vector<T>& other);
		Vector<T> operator-(const Vector<T>& other);

		Vector<T> operator=(const Vector<T>& other);

		T& operator[](size_t index);
		const T& operator[](size_t index) const;

		T	norm_1() const;
		T	norm() const;
		T	norm_inf() const;

};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vec);

#include "Vector.ipp"
#endif	// VECTOR_HPP