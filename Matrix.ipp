#include "Matrix.hpp"

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) noexcept: rows(rows), cols(cols), data(std::make_unique<T[]>(rows * cols))
{
	fillData(0);
}

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols, const T& value) noexcept: rows(rows), cols(cols), data(std::make_unique<T[]>(rows * cols))
{
	fillData(value);
}

template<typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> list): rows(list.size()), cols(list.begin()->size()), data(std::make_unique<T[]>(rows * cols))
{
	for (size_t i = 0; i < rows; ++i)
	{
		const auto& row = *(list.begin() + i);
		if (row.size() != cols)
			throw std::invalid_argument("All rows must have the same number of columns.");
		for (size_t j = 0; j < cols; ++j)
			putData(i, j, row.begin()[j]);
	}
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other) noexcept: rows(other.rows), cols(other.cols), data(std::make_unique<T[]>(rows * cols))
{
	for (size_t i = 0; i < rows * cols; ++i)
		data[i] = other.data[i];
}

template<typename T>
size_t Matrix<T>::getRows() const noexcept
{
	return rows;
}

template<typename T>
size_t Matrix<T>::getCols() const noexcept
{
	return cols;
}

template<typename T>
void Matrix<T>::putData(size_t row, size_t col, const T& value)
{
	if (row >= rows || col >= cols)
		throw std::out_of_range("Row or column index out of range.");
	data[row + (col * this->rows)] = value;
}

template<typename T>
const T& Matrix<T>::getData(size_t row, size_t col) const
{
	if (row >= rows || col >= cols)
		throw std::out_of_range("Row or column index out of range.");
	return data[row + (col * this->rows)];
}

template<typename T>
void	Matrix<T>::fillData(const T& value)
{
	for (size_t i = 0; i < rows * cols; ++i)
		data[i] = value;
}

template<typename T>
void	Matrix<T>::add(const Matrix<T>& other)
{
	if (rows != other.rows || cols != other.cols)
		throw std::invalid_argument("Matrices must be of the same dimensions for addition.");
	for (size_t i = 0; i < rows * cols; ++i)
		data[i] += other.data[i];
}

template<typename T>
void	Matrix<T>::sub(const Matrix<T>& other)
{
	if (rows != other.rows || cols != other.cols)
		throw std::invalid_argument("Matrices must be of the same dimensions for subtraction.");
	for (size_t i = 0; i < rows *cols; ++i)
		data[i] -= other.data[i];
}

template<typename T>
void	Matrix<T>::scl(const T& scalar) noexcept
{
	for (size_t i = 0; i < rows * cols; ++i)
		data[i] *= scalar;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const T& value) noexcept
{
	Matrix<T> temp(*this);
	temp.add(Matrix<T>(rows, cols, value));
	return temp;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const T& value) noexcept
{
	Matrix<T> temp(*this);
	temp.sub(Matrix<T>(rows, cols, value));
	return temp;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T& value) noexcept
{
	Matrix<T> temp(*this);
	temp.scl(value);
	return temp;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other)
{
	Matrix<T> temp(*this);
	temp.add(other);
	return temp;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other)
{
	Matrix<T> temp(*this);
	temp.sub(other);
	return temp;
}

template<typename T>
Matrix<T> Matrix<T>::operator=(const Matrix<T>& other)
{
	if (this == &other)
		return *this;
	rows = other.rows;
	cols = other.cols;
	data = std::make_unique<T[]>(rows * cols);
	for (size_t i = 0; i < rows * cols; ++i)
		data[i] = other.data[i];
	return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat)
{
	for (size_t i = 0; i < mat.getRows(); ++i)
	{
		for (size_t j = 0; j < mat.getCols(); ++j)
			os << mat.getData(i, j) << " ";
		os << std::endl;
	}
	return os;
}
