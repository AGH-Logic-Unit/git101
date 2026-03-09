#include <iostream>

int multiply(int a, int b) {
    return a * b;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    // test the multiply function
    std::cout << "2 * 3 is: " << multiply(2, 3) << std::endl;
    return 0;
}