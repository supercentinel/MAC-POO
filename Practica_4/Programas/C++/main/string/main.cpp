#include <iostream>

#include "string.hpp"

int main() {

    //Constructors
    String s1;
    String s2(", World!");
    String s3(s2);

    //Getters
    std::cout << s1.getLength() << std::endl;
    //Methods
    //Substrings
    std::cout << s2.substring(2, 5) << std::endl;
    std::cout << s2.substring(2) << std::endl;
    //Case
    std::cout << s2.toLower() << std::endl;
    std::cout << s2.toUpper() << std::endl;
    std::cout << s2.toCapital() << std::endl;
    //Codification
    std::cout << s2.toCaesar() << std::endl;
    //Operator overloading
    //Concatenation
    std::cout << (s2 + s3) << std::endl;
    std::cout << ((s1 + "Hello") + s2) << std::endl;
    std::cout << (s1 += "Hello") << std::endl;
    std::cout << (s1 += s2) << std::endl;
    //Assignment
    std::cout << (s1 = s2) << std::endl;
    //Comparison
    std::cout << (s1 == s2) << std::endl;
    std::cout << (s1 == "Hello, World!") << std::endl;
    std::cout << (s1 != s2) << std::endl;
    std::cout << (s1 != "Hello, World!") << std::endl;
    //I/O
    std::cout << s1 << std::endl;
    std::cin >> s1;
    std::cout << s1 << std::endl;


    return 0;
}
