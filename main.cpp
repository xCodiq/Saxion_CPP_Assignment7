/**
 * Name : Elmar Blume
 * Student Number: 516099
 */

#include <iostream>
#include "rational/rational.h"

int main() {

    rational a{6, 1};
    rational b{2, 1};

    std::cout << a.to_string() << std::endl;
    std::cout << b.to_string() << std::endl;

    auto r = a / b;

    std::cout << r << std::endl;

    return 0;
}
