#ifndef	MATRIX_HPP
#define	MATRIX_HPP

#include <cstddef>
#include <initializer_list>
#include <ostream>
#include <memory>
#include "Vector.hpp"

template<typename T>
class Matrix
{
	private:
		size_t	rows;
		size_t	cols;
		std::unique_ptr<T[]> data;

	public:

		Matrix(size_t rows, size_t cols) noexcept;
		Matrix(size_t rows, size_t cols, const T& value) noexcept;
		Matrix(std::initializer_list<std::initializer_list<T>> list);
		Matrix(const Matrix<T>& other) noexcept;
		~Matrix() = default;

		size_t getRows() const noexcept;
		size_t getCols() const noexcept;
		
		void		putData(size_t row, size_t col, const T& value);
		const T		&getData(size_t row, size_t col) const;
		void		fillData(const T& value);

		void	add(const Matrix<T>& other);
		void	sub(const Matrix<T>& other);
		void	scl(const T& scalar) noexcept;

		Matrix<T> operator+(const T& value) noexcept;
		Matrix<T> operator-(const T& value) noexcept;
		Matrix<T> operator*(const T& value) noexcept;

		Matrix<T> operator+(const Matrix<T>& other);
		Matrix<T> operator-(const Matrix<T>& other);

		Matrix<T> operator=(const Matrix<T>& other);

};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat);

#include "Matrix.ipp"

#endif	// MATRIX_HPP