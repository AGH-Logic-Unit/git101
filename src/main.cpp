#include <iostream>

int add(int x, int y) {
    return x + y;
}

int main() {
    std::cout << "Hello, Calculator!" << std::endl;

    // test the add function
    std::cout << "2 + 3 = " << add(2, 3) << std::endl;
    return 0;
}