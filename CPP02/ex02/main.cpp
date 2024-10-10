#include "Fixed.hpp"

#include <iostream>


// int main(void) {
//     Fixed a(10);
//     Fixed b(20);
//     Fixed const c(42.42f);

//     // 比較演算子のテスト
//     {
//         std::cout << "比較演算子のテスト" << std::endl;
//         Fixed a(10);
//         Fixed b(20);
//         std::cout << "a: " << a << ", b: " << b << std::endl;
//         std::cout << "a < b: " << ((a < b) ? "true" : "false") << std::endl;
//         std::cout << "a > b: " << ((a > b) ? "true" : "false") << std::endl;
//         std::cout << "a <= b: " << ((a <= b) ? "true" : "false") << std::endl;
//         std::cout << "a >= b: " << ((a >= b) ? "true" : "false") << std::endl;
//         std::cout << "a == b: " << ((a == b) ? "true" : "false") << std::endl;
//         std::cout << "a != b: " << ((a != b) ? "true" : "false") << std::endl;
//     }

//     // 四則演算子のテスト
//     {
//         std::cout << "--- 四則演算子 ---" << std::endl;
//         Fixed a(10);
//         Fixed b(20);
//         std::cout << "a: " << a << ", b: " << b << std::endl;

//         std::cout << "a + b: " << (a + b) << std::endl;
//         std::cout << "a - b: " << (a - b) << std::endl;
//         std::cout << "a * b: " << (a * b) << std::endl;
//         std::cout << "a / b: " << (a / b) << std::endl;
//     }

//     // インクリメント/デクリメント演算子のテスト
//     {
//         std::cout << "--- インクリメント/デクリメント演算子 ---" << std::endl;
//         Fixed a(10);
//         std::cout << "a: " << a << std::endl;
//         std::cout << "++a: " << ++a << std::endl;
//         std::cout << "a++: " << a++ << std::endl;
//         std::cout << "a: " << a << std::endl;
//         std::cout << "--a: " << --a << std::endl;
//         std::cout << "a--: " << a-- << std::endl;
//         std::cout << "a: " << a << std::endl;

//     }
//     {
//         // min/max関数のテスト
//         std::cout << "--- min/max関数 ---" << std::endl;
//         Fixed a(3.5f);
//         Fixed b(5.2f);
//         std::cout << "a: " << a << ", b: " << b << std::endl;
//         Fixed &min = Fixed::min(a, b);
//         Fixed &max = Fixed::max(a, b);
//         std::cout << "min(a, b): " << min << std::endl;
//         std::cout << "max(a, b): " << max << std::endl;

//         const Fixed c(3.5f);
//         const Fixed d(5.2f);
//         std::cout << "const c: " << c << ", const d: " << d << std::endl;
//         const Fixed &min2 = Fixed::min(c, d);
//         const Fixed &max2 = Fixed::max(c, d);
//         std::cout << "const min(c, d): " << min2 << std::endl;
//         std::cout << "const max(c, d): " << max2 << std::endl;
//     }
//     return 0;
// }

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;

    std::cout << a << std::endl;
    
    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;
    
    return 0;
}

// ビット数を確認
// #include <climits>
// int main() {
//     std::cout << "int is " << sizeof(int) * CHAR_BIT << " bits.\n";
//     std::cout << "float is " << sizeof(float) * CHAR_BIT << " bits.\n"; 
//     std::cout << "long is " << sizeof(long) * CHAR_BIT << " bits.\n";
//     std::cout << "long long is " << sizeof(long long) * CHAR_BIT << " bits.\n";
//     std::cout << "int64_t is " << sizeof(int64_t) * CHAR_BIT << " bits.\n"; 
//     return 0;
// }
