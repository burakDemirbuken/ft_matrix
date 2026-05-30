#include "Vector.hpp"
#include "Matrix.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
	// exercise 00 tests
	std::cout << "Exercise 00 tests:" << std::endl;
	{
		Vector<int> v1(3, 2);
		std::cout << "Vector v1: " << v1 << std::endl << std::endl;

		
		Vector<int> v2{1, 2, 3};
		std::cout << "Vector v2: " << v2 << std::endl;
		v1.add(v2);
		std::cout << "v1 + v2: " << v1 << std::endl;
		v1.sub(v2);
		std::cout << "v1 - v2: " << v1 << std::endl;
		v1.scl(3);
		std::cout << "v1 * 3: " << v1 << std::endl << std::endl;
		
		Vector<int> v3(2);
		std::cout << "Vector v3: " << v3 << std::endl;
		v3 = v3 + 5;
		std::cout << "v3 + 5: " << v3 << std::endl << std::endl;
		
		Vector<int> v4{10, 20, 30};
		std::cout << "v4: " << v4 << std::endl;
		v4 = v4 - 5;
		std::cout << "v4 - 5: " << v4 << std::endl << std::endl;
		
		Vector<int> v5(v4);
		std::cout << "v5 (copy of v4): " << v5 << std::endl << std::endl;
		
		Vector<int> v6{20, 30, 40};
		std::cout << "v6 (copy of v5): " << v6 << std::endl;
		v6 = v5;
		std::cout << "v6 (assigned from v5): " << v6 << std::endl << std::endl;
	}
	
	{
		Matrix<int> m1(2, 3, 1);
		std::cout << "Matrix m1: " << std::endl << m1 << std::endl << std::endl;

		Matrix<int> m2{{1, 2, 3}, {4, 5, 6}};
		std::cout << "Matrix m2: " << std::endl << m2 << std::endl;
		m1.add(m2);
		std::cout << "m1 + m2: " << std::endl << m1 << std::endl;
		m1.sub(m2);
		std::cout << "m1 - m2: " << std::endl << m1 << std::endl;
		m1.scl(2);
		std::cout << "m1 * 2: " << std::endl << m1 << std::endl << std::endl;

		Matrix<int> m3(2, 3);
		std::cout << "Matrix m3: " << std::endl << m3 << std::endl;
		m3 = m3 + 5;
		std::cout << "m3 + 5: " << std::endl << m3 << std::endl << std::endl;
		
		Matrix<int> m4{{10, 20, 30}, {40, 50, 60}};
		std::cout << "Matrix m4: " << std::endl << m4 << std::endl;
		m4 = m4 - 5;
		std::cout << "m4 - 5: " << std::endl << m4 << std::endl << std::endl;

		Matrix<int> m5(m4);
		std::cout << "Matrix m5 (copy of m4): " << std::endl << m5 << std::endl << std::endl;

		Matrix<int> m6{{20, 30, 40}, {50, 60, 70}};
		std::cout << "Matrix m6 (copy of m5): " << std::endl << m6 << std::endl;
		m6 = m5;
		std::cout << "Matrix m6 (assigned from m5): " << std::endl << m6 << std::endl << std::endl;

	}
	
	return 0;
}






