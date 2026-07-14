#include "mathUtils.hpp"

template<typename T>
Vector<T> linear_combination(const Vector<Vector<T>>& vectors, const Vector<T>& coefficients)
{
	if (vectors.getSize() == 0 || coefficients.getSize() == 0)
		throw std::invalid_argument("Vectors and coefficients cannot be empty.");
	if (vectors.getSize() != coefficients.getSize())
		throw std::invalid_argument("Number of vectors must match number of coefficients.");
	size_t vec_size = vectors[0].getSize();
	for (size_t i = 1; i < vectors.getSize(); ++i)
		if (vectors[i].getSize() != vec_size)
			throw std::invalid_argument("All vectors must be of the same size.");
	Vector<T> result(vec_size);
	for	(size_t i = 0; i < vectors.getSize(); ++i)
		for (size_t j = 0; j < vec_size; ++j)
			result[j] = std::fma(vectors[i][j], coefficients[i], result[j]);
	return result;
}

template<typename T>
T	lerp(T v1, T v2, float t) noexcept
{
	return std::fma(v2 - v1, t, v1);
}

template<typename T>
Vector<T>	lerp(const Vector<T>& v1, const Vector<T>& v2, float t)
{
	if (v1.getSize() != v2.getSize())
		throw std::invalid_argument("Vectors must be of the same size for lerp.");
	Vector<T> result(v1.getSize());
	for (size_t i = 0; i < v1.getSize(); ++i)
		result[i] = lerp(v1[i], v2[i], t);
	return result;
}

template<typename T>
Matrix<T>	lerp(const Matrix<T>& m1, const Matrix<T>& m2, float t)
{
	if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols())
		throw std::invalid_argument("Matrices must be of the same dimensions for lerp.");
	Matrix<T> result(m1.getRows(), m1.getCols());
	for (size_t i = 0; i < m1.getRows(); ++i)
		for (size_t j = 0; j < m1.getCols(); ++j)
			result.putData(i, j, lerp(m1.getData(i, j), m2.getData(i, j), t));
	return result;
}

template<typename T>
T	angle_cos(const Vector<T>& v1, const Vector<T>& v2)
{
	if (v1.getSize() != v2.getSize())
		throw std::invalid_argument("Vectors must be of the same size for angle_cos.");
	T dot_product = v1.dot(v2);
	T norm_product = v1.norm() * v2.norm();
	if (norm_product == static_cast<T>(0))
		throw std::invalid_argument("Cannot compute angle_cos with zero-length vector.");
	return dot_product / norm_product;
}

template<typename T>
Vector<T>	cross_product(const Vector<T>& v1, const Vector<T>& v2)
{
	if (v1.getSize() != 3 || v2.getSize() != 3)
		throw std::invalid_argument("Cross product is only defined for 3D vectors.");
	Vector<T> result(3);
	result[0] = v1[1] * v2[2] - v1[2] * v2[1];
	result[1] = v1[2] * v2[0] - v1[0] * v2[2];
	result[2] = v1[0] * v2[1] - v1[1] * v2[0];
	return result;
}