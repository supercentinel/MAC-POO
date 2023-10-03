#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>

class String {
    private:
        unsigned int length;
        char *data;
    public:
        // Constructors
        String();
        String(const char *str);
        String(const String &otro);
        // Destructor
        ~String();
        // Getters
        unsigned int getLength();
        // Methods
        // Substring
        String substring(unsigned int start, unsigned int end);
        String substring(unsigned int start);
        // Case
        String toLower();
        String toUpper();
        String toCapital();
        // Codification
        String toCaesar();
        // Operator overloading
        // Concatenation
        String operator + (const String &otro);
        String operator + (const char *str);
        String operator += (const String &otro);
        String operator += (const char *str);
        // Assignment
        String operator = (const String &otro);
        // Comparison
        bool operator == (const String &otro);
        bool operator == (const char *str);
        bool operator != (const String &otro);
        bool operator != (const char *str);
        // I/O
        friend std::ostream& operator << (std::ostream &out, const String &str);
        friend std::istream& operator >> (std::istream &in, String &str);
};

#endif
