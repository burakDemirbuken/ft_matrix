#include "Vector.hpp"
#include "Matrix.hpp"
#include "mathUtils.hpp"
#include <iostream>

void test_ex00()
{
    std::cout << "\n--- Exercise 00: Add, Subtract and Scale Tests ---" << std::endl;

    // VECTOR TESTS
    std::cout << "\n[ Vector Tests ]" << std::endl;
    try {
        Vector<float> u1({2.0f, 3.0f});
        Vector<float> v1({5.0f, 7.0f});
        u1.add(v1);
        std::cout << "Vector Add:\n" << u1 << std::endl;
        // Expected: [7.0, 10.0]

        Vector<float> u2({2.0f, 3.0f});
        Vector<float> v2({5.0f, 7.0f});
        u2.sub(v2);
        std::cout << "Vector Sub:\n" << u2 << std::endl;
        // Expected: [-3.0, -4.0]

        Vector<float> u3({2.0f, 3.0f});
        u3.scl(2.0f);
        std::cout << "Vector Scl:\n" << u3 << std::endl;
        // Expected: [4.0, 6.0]

        // Exception Test
        Vector<float> err_v1({1.0f, 2.0f});
        Vector<float> err_v2({1.0f, 2.0f, 3.0f});
        std::cout << "Vector Exception Test: ";
        err_v1.add(err_v2);
        std::cout << "FAIL (No exception thrown)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "SUCCESS (Exception caught) -> " << e.what() << std::endl;
    }

    // MATRIX TESTS
    std::cout << "\n[ Matrix Tests ]" << std::endl;
    try {
        Matrix<float> u1({
            {1.0f, 2.0f},
            {3.0f, 4.0f}
        });
        Matrix<float> v1({
            {7.0f, 4.0f},
            {-2.0f, 2.0f}
        });
        u1.add(v1);
        std::cout << "Matrix Add:\n" << u1 << std::endl;
        // Expected: [[8.0, 6.0], [1.0, 6.0]]

        Matrix<float> u2({
            {1.0f, 2.0f},
            {3.0f, 4.0f}
        });
        Matrix<float> v2({
            {7.0f, 4.0f},
            {-2.0f, 2.0f}
        });
        u2.sub(v2);
        std::cout << "Matrix Sub:\n" << u2 << std::endl;
        // Expected: [[-6.0, -2.0], [5.0, 2.0]]

        Matrix<float> u3({
            {1.0f, 2.0f},
            {3.0f, 4.0f}
        });
        u3.scl(2.0f);
        std::cout << "Matrix Scl:\n" << u3 << std::endl;
        // Expected: [[2.0, 4.0], [6.0, 8.0]]

        // Exception Test
        Matrix<float> err_m1({
            {1.0f, 2.0f}
        });
        Matrix<float> err_m2({
            {1.0f, 2.0f},
            {3.0f, 4.0f}
        });
        std::cout << "Matrix Exception Test: ";
        err_m1.sub(err_m2);
        std::cout << "FAIL (No exception thrown)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "SUCCESS (Exception caught) -> " << e.what() << std::endl;
    }
}

void test_ex01()
{
    std::cout << "\n--- Exercise 01: Linear Combination Tests ---" << std::endl;

    // Test 1: Subject PDF Example 1
    try {
        Vector<Vector<float>> v_arr1 = {
            Vector<float>({1.0f, 0.0f, 0.0f}),
            Vector<float>({0.0f, 1.0f, 0.0f}),
            Vector<float>({0.0f, 0.0f, 1.0f})
        };
        Vector<float> c_arr1 = {10.0f, -2.0f, 0.5f};
        
        std::cout << "Test 1 (PDF): " << std::endl;
        std::cout << linear_combination(v_arr1, c_arr1) << std::endl; 
        // Expected: [10.0, -2.0, 0.5]
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 2: Subject PDF Example 2
    try {
        Vector<Vector<float>> v_arr2 = {
            Vector<float>({1.0f, 2.0f, 3.0f}),
            Vector<float>({0.0f, 10.0f, -100.0f})
        };
        Vector<float> c_arr2 = {10.0f, -2.0f};
        
        std::cout << "\nTest 2 (PDF): " << std::endl;
        std::cout << linear_combination(v_arr2, c_arr2) << std::endl; 
        // Expected: [10.0, 0.0, 230.0]
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 3: Exception - Empty Arrays
    try {
        Vector<Vector<float>> v_arr_empty;
        Vector<float> c_arr_empty;
        
        std::cout << "\nTest 3 (Exception - Empty Arrays): " << std::endl;
        linear_combination(v_arr_empty, c_arr_empty);
        std::cout << "FAIL (No exception thrown)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "SUCCESS (Exception caught) -> " << e.what() << std::endl;
    }

    // Test 4: Exception - Vectors and coefficients count mismatch
    try {
        Vector<Vector<float>> v_arr_mismatch = {
            Vector<float>({1.0f, 2.0f})
        };
        Vector<float> c_arr_mismatch = {1.0f, 2.0f};
        
        std::cout << "\nTest 4 (Exception - Vectors and coefficients count mismatch): " << std::endl;
        linear_combination(v_arr_mismatch, c_arr_mismatch);
        std::cout << "FAIL (No exception thrown)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "SUCCESS (Exception caught) -> " << e.what() << std::endl;
    }

    // Test 5: Exception - Inner vectors size mismatch
    try {
        Vector<Vector<float>> v_arr_inner_mismatch = {
            Vector<float>({1.0f, 2.0f, 3.0f}),
            Vector<float>({1.0f, 2.0f})       
        };
        Vector<float> c_arr_inner_mismatch = {1.0f, 2.0f};
        
        std::cout << "\nTest 5 (Exception - Inner vectors size mismatch): " << std::endl;
        linear_combination(v_arr_inner_mismatch, c_arr_inner_mismatch);
        std::cout << "FAIL (No exception thrown)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "SUCCESS (Exception caught) -> " << e.what() << std::endl;
    }
}

void test_ex02()
{
    std::cout << "\n--- Exercise 02: Linear Interpolation Tests ---" << std::endl;

    // SCALAR LERP TESTS
    std::cout << "\n[ Scalar Lerp Tests ]" << std::endl;
    std::cout << "lerp(0.0f, 1.0f, 0.0f)   -> " << lerp(0.0f, 1.0f, 0.0f) << " (Expected: 0)" << std::endl;
    std::cout << "lerp(0.0f, 1.0f, 1.0f)   -> " << lerp(0.0f, 1.0f, 1.0f) << " (Expected: 1)" << std::endl;
    std::cout << "lerp(0.0f, 1.0f, 0.5f)   -> " << lerp(0.0f, 1.0f, 0.5f) << " (Expected: 0.5)" << std::endl;
    std::cout << "lerp(21.0f, 42.0f, 0.3f) -> " << lerp(21.0f, 42.0f, 0.3f) << " (Expected: 27.3)" << std::endl;

    // VECTOR LERP TESTS
    std::cout << "\n[ Vector Lerp Tests ]" << std::endl;
    try {
        Vector<float> v1({2.0f, 1.0f});
        Vector<float> v2({4.0f, 2.0f});
        std::cout << "lerp(Vector([2, 1]), Vector([4, 2]), 0.3f):\n" << lerp(v1, v2, 0.3f) << std::endl;
        // Expected: [2.6, 1.3]

        // Exception Test: vectors of different sizes
        Vector<float> err_v1({1.0f, 2.0f});
        Vector<float> err_v2({1.0f, 2.0f, 3.0f});
        std::cout << "Vector Lerp Exception Test: ";
        lerp(err_v1, err_v2, 0.5f);
        std::cout << "FAIL (No exception thrown)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "SUCCESS (Exception caught) -> " << e.what() << std::endl;
    }

    // MATRIX LERP TESTS
    std::cout << "\n[ Matrix Lerp Tests ]" << std::endl;
    try {
        Matrix<float> m1({
            {2.0f, 1.0f},
            {3.0f, 4.0f}
        });
        Matrix<float> m2({
            {20.0f, 10.0f},
            {30.0f, 40.0f}
        });
        std::cout << "lerp(Matrix([[2, 1], [3, 4]]), Matrix([[20, 10], [30, 40]]), 0.5f):\n" << lerp(m1, m2, 0.5f) << std::endl;
        // Expected: [[11.0, 5.5], [16.5, 22.0]]

        // Exception Test: matrices of different dimensions
        Matrix<float> err_m1({
            {1.0f, 2.0f}
        });
        Matrix<float> err_m2({
            {1.0f, 2.0f},
            {3.0f, 4.0f}
        });
        std::cout << "Matrix Lerp Exception Test: ";
        lerp(err_m1, err_m2, 0.5f);
        std::cout << "FAIL (No exception thrown)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "SUCCESS (Exception caught) -> " << e.what() << std::endl;
    }
}

void test_ex03()
{
	std::cout << "\n--- Exercise 03: Additional Tests ---" << std::endl;

	// Additional tests can be added here for further validation of the Vector and Matrix classes
	// For example, testing operator overloads, copy constructors, assignment operators, etc.
}

void test_ex04()
{
    std::cout << "\n--- Exercise 04: Norm Tests ---" << std::endl;
    
    // Subject Examples
    std::cout << "[ Subject Examples ]" << std::endl;
    Vector<float> u1({0.0f, 0.0f, 0.0f});
    std::cout << u1.norm_1() << ", " << u1.norm() << ", " << u1.norm_inf() << std::endl;
    // Expected: 0, 0, 0
    
    Vector<float> u2({1.0f, 2.0f, 3.0f});
    std::cout << u2.norm_1() << ", " << u2.norm() << ", " << u2.norm_inf() << std::endl;
    // Expected: 6, 3.74165, 3
    
    Vector<float> u3({-1.0f, -2.0f});
    std::cout << u3.norm_1() << ", " << u3.norm() << ", " << u3.norm_inf() << std::endl;
    // Expected: 3, 2.23607, 2

    // Additional Varied Tests
    std::cout << "\n[ Additional Varied Tests ]" << std::endl;
    
    // Additional Test 1: All negative numbers
    Vector<float> u4({-4.0f, -3.0f, -5.0f});
    std::cout << "All negatives:  " << u4.norm_1() << ", " << u4.norm() << ", " << u4.norm_inf() << std::endl;
    
    // Additional Test 2: Floating point numbers
    Vector<float> u5({1.5f, -2.5f, 3.5f});
    std::cout << "Decimals:       " << u5.norm_1() << ", " << u5.norm() << ", " << u5.norm_inf() << std::endl;
    
    // Additional Test 3: Large numbers
    Vector<float> u6({1000.0f, -2000.0f, 3000.0f});
    std::cout << "Large numbers:  " << u6.norm_1() << ", " << u6.norm() << ", " << u6.norm_inf() << std::endl;

    // Additional Test 4: Single element
    Vector<float> u7({-42.0f});
    std::cout << "Single element: " << u7.norm_1() << ", " << u7.norm() << ", " << u7.norm_inf() << std::endl;
}

void test_ex05()
{
    std::cout << "\n--- Exercise 05: Cosine Tests ---" << std::endl;
    
    // Subject Examples
    std::cout << "[ Subject Examples ]" << std::endl;
    
    Vector<float> u1({1.0f, 0.0f});
    Vector<float> v1({1.0f, 0.0f});
    std::cout << "u=[1, 0], v=[1, 0] -> " << angle_cos(u1, v1) << " (Expected: 1.0)" << std::endl;
    
    Vector<float> u2({1.0f, 0.0f});
    Vector<float> v2({0.0f, 1.0f});
    std::cout << "u=[1, 0], v=[0, 1] -> " << angle_cos(u2, v2) << " (Expected: 0.0)" << std::endl;
    
    Vector<float> u3({-1.0f, 1.0f});
    Vector<float> v3({1.0f, -1.0f});
    std::cout << "u=[-1, 1], v=[1, -1] -> " << angle_cos(u3, v3) << " (Expected: -1.0)" << std::endl;
    
    Vector<float> u4({2.0f, 1.0f});
    Vector<float> v4({4.0f, 2.0f});
    std::cout << "u=[2, 1], v=[4, 2] -> " << angle_cos(u4, v4) << " (Expected: 1.0)" << std::endl;
    
    Vector<float> u5({1.0f, 2.0f, 3.0f});
    Vector<float> v5({4.0f, 5.0f, 6.0f});
    std::cout << "u=[1, 2, 3], v=[4, 5, 6] -> " << angle_cos(u5, v5) << " (Expected: 0.974631846)" << std::endl;

    // Exception Tests
    std::cout << "\n[ Exception Tests ]" << std::endl;
    try {
        Vector<float> err_u({1.0f, 2.0f});
        Vector<float> err_v({1.0f, 2.0f, 3.0f});
        std::cout << "Different sizes exception test: ";
        angle_cos(err_u, err_v);
        std::cout << "FAIL (No exception thrown)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "SUCCESS (Exception caught) -> " << e.what() << std::endl;
    }

    try {
        Vector<float> err_u({0.0f, 0.0f});
        Vector<float> err_v({1.0f, 1.0f});
        std::cout << "Zero length exception test: ";
        angle_cos(err_u, err_v);
        std::cout << "FAIL (No exception thrown)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "SUCCESS (Exception caught) -> " << e.what() << std::endl;
    }
}

void test_ex06()
{
    std::cout << "\n--- Exercise 06: Cross Product Tests ---" << std::endl;
    
    // Subject Examples
    std::cout << "[ Subject Examples ]" << std::endl;
    
    Vector<float> u1({0.0f, 0.0f, 1.0f});
    Vector<float> v1({1.0f, 0.0f, 0.0f});
    std::cout << "cross_product([0, 0, 1], [1, 0, 0]):\n" << cross_product(u1, v1) << std::endl;
    // Expected: [0, 1, 0]
    
    Vector<float> u2({1.0f, 2.0f, 3.0f});
    Vector<float> v2({4.0f, 5.0f, 6.0f});
    std::cout << "cross_product([1, 2, 3], [4, 5, 6]):\n" << cross_product(u2, v2) << std::endl;
    // Expected: [-3, 6, -3]

    // Exception Tests
    std::cout << "\n[ Exception Tests ]" << std::endl;
    try {
        Vector<float> err_u({1.0f, 2.0f});
        Vector<float> err_v({1.0f, 2.0f, 3.0f});
        std::cout << "Non-3D vector exception test: ";
        cross_product(err_u, err_v);
        std::cout << "FAIL (No exception thrown)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "SUCCESS (Exception caught) -> " << e.what() << std::endl;
    }
}

int main()
{
	test_ex00();
	test_ex01();
	test_ex02();
	test_ex03();
	test_ex04();
	test_ex05();
	test_ex06();
	return 0;
}
