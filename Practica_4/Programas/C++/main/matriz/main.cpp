#include <iostream>
#include <iterator>
#include <ostream>

#include "matriz.hpp"

int main(void) {

    //Constructors
    Matriz m1;
    Matriz m2(3, 3);
    Matriz m3(m2);

    //Getters
    std::cout << "m1 rows: " << m1.getRows() << std::endl;
    std::cout << "m1 cols: " << m1.getCols() << std::endl;
    std::cout << std::endl;
    //Setters
    m2.setData(0, 1, 1.5);
    m2.setData(1, 0, 2.5);
    m2.setData(1, 1, 3.5);
    m2.setData(2, 2, 5.2);

    //Methods
    std::cout << "m2 to TeX\n" << m2.toTeX('(', 5);
    std::cout << std::endl;
    //Operator overloading
    // I/O
    std::cout << "m2\n" << m2 << std::endl;
    std::cout << "read m1" << std::endl;
    /* std::cin >> m1; */
    std::cout << "m1\n" << m1 << std::endl;
    std::cout << "det(m2): " << m2.det() << std::endl;
    std::cout << "m2 trasposed\n" << m2.transpose() << std::endl;
    std::cout << "m_21\n" << m2.minor(2, 1) << std::endl;
    std::cout << "A_{2,1}: " << m2.cofactor(2, 1) << std::endl;
    std::cout << "Cofactor matrix\n" << m2.cofactorMatrix() << std::endl;
    std::cout << "Adj matrix\n" << m2.adj() << std::endl;
    std::cout << "m2 inverse\n" << m2.inverse() << std::endl;

    //Operator overloading
    // =
    std::cout << "m1 = m2\n"<< (m1 = m2) << std::endl;
    // +
    std::cout << "m1 + m2\n" << (m1 + m2) << std::endl;
    std::cout << "m1 += m2\n" << (m1 += m2) << std::endl;
    // -
    // std::cout << "m1 - m2\n" << (m1 - m2) << std::endl;
    // std::cout << "m1 -= m2\n" << (m1 -= m2) << std::endl;
    // *
    std::cout << "m1 * m2\n" << (m1 * m2) << std::endl;
    std::cout << "m1 * 2.5\n" << (m1 * 2.5) << std::endl;
    std::cout << "m1 *= m2\n" << (m1 *= m2) << std::endl;
    std::cout << "m1 *= 2.5\n" << (m1 *= 2.5) << std::endl;


    return 0;
}
