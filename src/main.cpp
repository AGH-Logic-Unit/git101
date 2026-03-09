#include <iostream>

int sub(int a, int b) {
    return a - b;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    
    // test the sub function
    std::cout << "5 - 3 = " << sub(5, 3) << std::endl;
    return 0;
}