#include <iostream>
#include "Fixed.hpp"

/*
int main(void)
{
    Fixed a(42);
    
    Fixed const b(Fixed(5.05f) * Fixed(2));
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    std::cout << Fixed::min(a, b) << std::endl;
    
    return 0;
}
*/

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    std::cout << "===== CONSTRUCTORS TESTS =====" << std::endl;
    std::cout << "Default constructor:" << std::endl;
    Fixed a;
    std::cout << "a = " << a << std::endl;
    
    std::cout << "\nInt constructor:" << std::endl;
    Fixed b(42);
    std::cout << "b = " << b << std::endl;
    
    std::cout << "\nFloat constructor:" << std::endl;
    Fixed c(42.42f);
    std::cout << "c = " << c << std::endl;
    
    std::cout << "\nCopy constructor:" << std::endl;
    Fixed d(c);
    std::cout << "d = " << d << std::endl;
    
    std::cout << "\n===== CONVERSION TESTS =====" << std::endl;
    std::cout << "toFloat():" << std::endl;
    std::cout << "c.toFloat() = " << c.toFloat() << std::endl;
    
    std::cout << "\ntoInt():" << std::endl;
    std::cout << "c.toInt() = " << c.toInt() << std::endl;
    
    std::cout << "\n===== COMPARISON OPERATORS TESTS =====" << std::endl;
    Fixed x(10.5f);
    Fixed y(10.5f);
    Fixed z(20.0f);
    
    std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
    std::cout << "x > y: " << (x > y) << std::endl;
    std::cout << "x < z: " << (x < z) << std::endl;
    std::cout << "x >= y: " << (x >= y) << std::endl;
    std::cout << "z <= x: " << (z <= x) << std::endl;
    std::cout << "x == y: " << (x == y) << std::endl;
    std::cout << "x != z: " << (x != z) << std::endl;
    
    std::cout << "\n===== ARITHMETIC OPERATORS TESTS =====" << std::endl;
    std::cout << "x + z = " << (x + z) << std::endl;
    std::cout << "z - x = " << (z - x) << std::endl;
    std::cout << "x * z = " << (x * z) << std::endl;
    std::cout << "z / x = " << (z / x) << std::endl;
    
    // Testing division by zero
    Fixed zero;
    std::cout << "Division by zero test:" << std::endl;
    std::cout << "x / zero = " << (x / zero) << std::endl;
    
    std::cout << "\n===== INCREMENT/DECREMENT OPERATORS TESTS =====" << std::endl;
    Fixed inc(5.5f);
    std::cout << "Initial inc = " << inc << std::endl;
    
    std::cout << "Pre-increment: ++inc = " << ++inc << std::endl;
    std::cout << "After pre-increment: inc = " << inc << std::endl;
    
    std::cout << "Post-increment: inc++ = " << inc++ << std::endl;
    std::cout << "After post-increment: inc = " << inc << std::endl;
    
    std::cout << "Pre-decrement: --inc = " << --inc << std::endl;
    std::cout << "After pre-decrement: inc = " << inc << std::endl;
    
    std::cout << "Post-decrement: inc-- = " << inc-- << std::endl;
    std::cout << "After post-decrement: inc = " << inc << std::endl;
    
    std::cout << "\n===== MIN/MAX FUNCTIONS TESTS =====" << std::endl;
    Fixed p(15.75f);
    Fixed q(25.25f);
    std::cout << "p = " << p << ", q = " << q << std::endl;
    
    std::cout << "min(p, q) = " << Fixed::min(p, q) << std::endl;
    std::cout << "max(p, q) = " << Fixed::max(p, q) << std::endl;
    
    const Fixed r(15.75f);
    const Fixed s(25.25f);
    std::cout << "const r = " << r << ", const s = " << s << std::endl;
    
    std::cout << "min(const r, const s) = " << Fixed::min(r, s) << std::endl;
    std::cout << "max(const r, const s) = " << Fixed::max(r, s) << std::endl;
    
    std::cout << "\n===== ASSIGNMENT OPERATOR TEST =====" << std::endl;
    Fixed assign;
    std::cout << "Before assignment: assign = " << assign << std::endl;
    assign = p;
    std::cout << "After assignment: assign = " << assign << std::endl;
    return 0;
}
