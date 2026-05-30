#include "Vector.hpp"
#include "Matrix.hpp"
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
        std::vector<Vector<float>> v_arr1 = {
            Vector<float>({1.0f, 0.0f, 0.0f}),
            Vector<float>({0.0f, 1.0f, 0.0f}),
            Vector<float>({0.0f, 0.0f, 1.0f})
        };
        std::vector<float> c_arr1 = {10.0f, -2.0f, 0.5f};
        
        std::cout << "Test 1 (PDF): " << std::endl;
        std::cout << linear_combination(v_arr1, c_arr1) << std::endl; 
        // Expected: [10.0, -2.0, 0.5]
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 2: Subject PDF Example 2
    try {
        std::vector<Vector<float>> v_arr2 = {
            Vector<float>({1.0f, 2.0f, 3.0f}),
            Vector<float>({0.0f, 10.0f, -100.0f})
        };
        std::vector<float> c_arr2 = {10.0f, -2.0f};
        
        std::cout << "\nTest 2 (PDF): " << std::endl;
        std::cout << linear_combination(v_arr2, c_arr2) << std::endl; 
        // Expected: [10.0, 0.0, 230.0]
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 3: Exception - Empty Arrays
    try {
        std::vector<Vector<float>> v_arr_empty;
        std::vector<float> c_arr_empty;
        
        std::cout << "\nTest 3 (Exception - Empty Arrays): " << std::endl;
        linear_combination(v_arr_empty, c_arr_empty);
        std::cout << "FAIL (No exception thrown)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "SUCCESS (Exception caught) -> " << e.what() << std::endl;
    }

    // Test 4: Exception - Vectors and coefficients count mismatch
    try {
        std::vector<Vector<float>> v_arr_mismatch = {
            Vector<float>({1.0f, 2.0f})
        };
        std::vector<float> c_arr_mismatch = {1.0f, 2.0f};
        
        std::cout << "\nTest 4 (Exception - Vectors and coefficients count mismatch): " << std::endl;
        linear_combination(v_arr_mismatch, c_arr_mismatch);
        std::cout << "FAIL (No exception thrown)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "SUCCESS (Exception caught) -> " << e.what() << std::endl;
    }

    // Test 5: Exception - Inner vectors size mismatch
    try {
        std::vector<Vector<float>> v_arr_inner_mismatch = {
            Vector<float>({1.0f, 2.0f, 3.0f}),
            Vector<float>({1.0f, 2.0f})       
        };
        std::vector<float> c_arr_inner_mismatch = {1.0f, 2.0f};
        
        std::cout << "\nTest 5 (Exception - Inner vectors size mismatch): " << std::endl;
        linear_combination(v_arr_inner_mismatch, c_arr_inner_mismatch);
        std::cout << "FAIL (No exception thrown)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "SUCCESS (Exception caught) -> " << e.what() << std::endl;
    }
}

int main(int argc, char const *argv[])
{

	test_ex00();
	test_ex01();

	return 0;
}






