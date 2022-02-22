#include <iostream>
#include "ntlib.h"

/*void display_2x2(u64 arr[2][2]) {
    std::cout << "{\n";
    std::cout << "    " << arr[0][0] << "  " << arr[0][1] << "\n";
    std::cout << "    " << arr[1][0] << "  " << arr[1][1] << "\n";
    std::cout << "}\n";
}*/

int main() {

    /*u64 a[2][2] = {{1, 1}, {1, 0}};
    u64 b[2][2] = {{1, 1}, {1, 0}};
    display_2x2(a);
    mul_matrix2d(a, b);
    display_2x2(a);*/

    std::cout << fib(0, u64_max) << "\n";
    std::cout << fib(1, u64_max) << "\n";
    std::cout << fib(2, u64_max) << "\n";
    std::cout << fib(3, u64_max) << "\n";
    std::cout << fib(4, u64_max) << "\n";
    std::cout << fib(5, u64_max) << "\n";
    std::cout << fib(6, u64_max) << "\n";
    std::cout << fib(7, u64_max) << "\n";
    
    return 0;
}