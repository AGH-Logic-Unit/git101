#include <iostream>

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        return 0; // Return 0 or handle as needed
    }
    return a / b;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    // test the multiply function
    std::cout << "2 * 3 is: " << multiply(2, 3) << std::endl;

    // test the divide function
    std::cout << "6 / 3 is: " << divide(6, 3) << std::endl;
    std::cout << "6 / 0 is: " << divide(6, 0) << std::endl;

    return 0;
}