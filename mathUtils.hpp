#ifndef	MATH_UTILS_HPP
#define	MATH_UTILS_HPP

#include "Vector.hpp"
#include "Matrix.hpp"
#include <math.h>

template<typename T>
Vector<T> linear_combination(const Vector<Vector<T>>& vectors, const Vector<T>& coefficients);


template<typename T>
Vector<T>	lerp(const Vector<T>& v1, const Vector<T>& v2, float t);

template<typename T>
Matrix<T>	lerp(const Matrix<T>& m1, const Matrix<T>& m2, float t);

template<typename T>
T			lerp(T v1, T v2, float t) noexcept;

template<typename T>
T			angle_cos(const Vector<T>& v1, const Vector<T>& v2);

template<typename T>
Vector<T>	cross_product(const Vector<T>& v1, const Vector<T>& v2);

#include "mathUtils.ipp"

#endif	// MATH_UTILS_HPP
