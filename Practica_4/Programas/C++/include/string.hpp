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
        // Methods
        // Substring
        String substring(unsigned int start, unsigned int end);
        String substring(unsigned int start);
        // Find
        int find(const char *str);
        int find(const String &otro);
        // Case
        String toLower();
        String toUpper();
        String toCapital();
        // Codification
        String to64();
        String toCaesar(unsigned int key);
        // Getters
        unsigned int getLength();
        // Operator overloading
        // Concatenation
        String operator + (const String &otro);
        String operator + (const char *str);
        // Comparison
        bool operator == (const String &otro);
        bool operator == (const char *str);
        bool operator != (const String &otro);
        bool operator != (const char *str);
};

#endif
