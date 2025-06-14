#include "bigint.hpp"
#include <iostream>

int main(){
    const bigint a("100000000000000000000000000000000000000000000000000000000000000000000000000000");
    bigint b(21), c, d(1337), e(d);
    bigint       f("99999999999999999999999999999999999999999999999999999999999999999999999999999");

    
    std::cout << "a < f " << (a < f) << std::endl;
    std::cout << "a > f " << (a > f) << std::endl;
    std::cout << "a >= f " << (a >= f) << std::endl;
    std::cout << "a <= f " << (a <= f) << std::endl;
    
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "a+b " << a + b << std::endl;
    std::cout << "c+=a " << (c += a) << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "++b " << ++b << std::endl;
    std::cout << "b++ " << b++ << std::endl;
    std::cout << "b = " << b << std::endl; //added by me for check
    std::cout << "(b << 10) + 42 " << (b << 10) + 42 << std::endl;
    std::cout << "c = b << 10 " << (c = b << 10) << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "c = c >> 10 " << (c = c >> 10) << std::endl;
    std::cout << "c = " << c << std::endl;

    std::cout << "d<<=4 " << (d <<= 4) << std::endl;
    std::cout << "d>>=(const bigint)2 " << (d >>= (const bigint)2) << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "d < a " << (d < a) << std::endl;
    std::cout << "d > a " << (d > a) << std::endl;
    std::cout << "d == a " << (d == a) << std::endl;
    std::cout << "d != a " << (d != a) << std::endl;
    std::cout << "d <= a " << (d <= a) << std::endl;
    std::cout << "d >= a " << (d >= a) << std::endl;
    std::cout << "c = " << c << std::endl;


    return 0;
}
