#include <iostream>

#include "matriz.hpp"

int main(void) {

    //Constructors
    Matriz m1;
    Matriz m2(3, 3);
    Matriz m3(m2);

    //Getters
    std::cout << "m1 rows: " << m1.getRows() << std::endl;
    std::cout << "m1 cols: " << m1.getCols() << std::endl;
    //Methods
    std::cout << "m2 to TeX\n" << m2.toTeX('(', 5);

    return 0;
}
