#include <iostream>
#include <istream>

#include "string.hpp"

// Constructors
String::String() {
    this->length = 0;
    this->data = (char*) calloc(1, sizeof(char));

    if (this->data == NULL) {
        std::cout << "Error: Memory allocation failed." << std::endl;
    }

    this->data[0] = '\0';
}

String::String(const char *str) {
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        continue;
    }

    this->length = i;
    this->data = (char*) calloc(this->length + 1, sizeof(char));

    if (this->data == NULL) {
        std::cout << "Error: Memory allocation failed." << std::endl;
    }

    for (i = 0; str[i] != '\0'; i++) {
        this->data[i] = str[i];
    }

    this->data[i] = '\0';
}

String::String(const String &otro) {
    int i = 0;

    this->length = otro.length;
    this->data = (char*) calloc(this->length + 1, sizeof(char));

    if (this->data == NULL) {
        std::cout << "Error: Memory allocation failed." << std::endl;
    }

    for(i = 0; otro.data[i] != '\0'; i++) {
        this->data[i] = otro.data[i];
    }

    this->data[this->length] = '\0';
}

// Destructor
String::~String() {
    this->length = 0;
    free(this->data);
}

// Getters
unsigned int String::getLength() {
    return this->length;
}

// Methods
// Substrings
String String::substring(unsigned int start, unsigned int end) {
    if(start > end) {
        std::cout << "Error: Start index is greater than end index." << std::endl;
    }

    if(end > this->length) {
        std::cout << "Error: End index is greater than string length." << std::endl;
    }

    int newLength = end - start;
    char *newData = (char*) calloc(newLength + 1, sizeof(char));

    for(int i = 0; i < newLength; i++) {
        newData[i] = this->data[start + i];
    }

    newData[newLength] = '\0';

    String newString(newData);
    free(newData);

    return newString;
}

String String::substring(unsigned int start) {
    return this->substring(start, this->length);
}
// Case conversion
String String::toLower() {
    char *newData = (char*) calloc(this->length + 1, sizeof(char));

    for(int i = 0; this->data[i] != '\0'; i++) {
        if(this->data[i] >= 'A' && this->data[i] <= 'Z') {
            newData[i] = this->data[i] + 32;
        } else {
            newData[i] = this->data[i];
        }
    }

    newData[this->length] = '\0';

    String newString(newData);
    free(newData);

    return newString;
}

String String::toUpper() {
    char *newData = (char*) calloc(this->length + 1, sizeof(char));

    for(int i = 0; this->data[i] != '\0'; i++) {
        if(this->data[i] >= 'a' && this->data[i] <= 'z') {
            newData[i] = this->data[i] - 32;
        } else {
            newData[i] = this->data[i];
        }
    }

    newData[this->length] = '\0';

    String newString(newData);
    free(newData);

    return newString;
}

String String::toCapital() {
    char *newData = (char*) calloc(this->length + 1, sizeof(char));

    for(int i = 0; this->data[i] != '\0'; i++) {
        if(i == 0 || this->data[i - 1] == ' ') {
            if(this->data[i] >= 'a' && this->data[i] <= 'z') {
                newData[i] = this->data[i] - 32;
            } else {
                newData[i] = this->data[i];
            }
        } else {
            if(this->data[i] >= 'A' && this->data[i] <= 'Z') {
                newData[i] = this->data[i] + 32;
            } else {
                newData[i] = this->data[i];
            }
        }
    }

    newData[this->length] = '\0';

    String newString(newData);
    free(newData);

    return newString;
}
// Cypher
String String::toCaesar() {
    char *buffer = (char*) calloc(this->length + 1, sizeof(char));

    for(int i = 0; this->data[i] != '\0'; i++) {
        if(this->data[i] >= 'a' && this->data[i] <= 'z') {
            buffer[i] = this->data[i] + 3;

            if(buffer[i] > 'z') {
                buffer[i] = buffer[i] - 'z' + 'a' - 1;
            }
        } else if(this->data[i] >= 'A' && this->data[i] <= 'Z') {
            buffer[i] = this->data[i] + 3;

            if(buffer[i] > 'Z') {
                buffer[i] = buffer[i] - 'Z' + 'A' - 1;
            }
        } else {
            buffer[i] = this->data[i];
        }
    }

    buffer[this->length] = '\0';
    String caesarString(buffer);
    free(buffer);

    return caesarString;
}

// Cocatenation
String String::operator + (const String &otro) {
    int newLength = this->length + otro.length;

    char *newData = (char*) calloc(newLength + 1, sizeof(char));

    if (newData == NULL) {
        std::cout << "Error: Memory allocation failed." << std::endl;
    }

    for (int i = 0; this->data[i] != '\0'; i++) {
        newData[i] = this->data[i];
    }

    for (int i = 0; otro.data[i] != '\0'; i++) {
        newData[this->length + i] = otro.data[i];
    }

    newData[newLength] = '\0';

    String newString(newData);

    free(newData);

    return newString;
}

String String::operator + (const char *str) {
    String newString(str);

    return (*this + newString);
}

String String::operator += (const String &otro) {
    int newLength = this->length + otro.length;
    this->data = (char*) realloc(this->data, newLength + 1);

    if (this->data == NULL) {
        std::cout << "Error: Memory allocation failed." << std::endl;
    }

    for (int i = 0; otro.data[i] != '\0'; i++) {
        this->data[this->length + i] = otro.data[i];
    }

    this->length = newLength;
    this->data[newLength] = '\0';

    return *this;
}

String String::operator += (const char *str) {
    String newString(str);

    return (*this += newString);
}
// Assignment
String String::operator = (const String &otro) {
    this->length = otro.length;
    this->data = (char*) realloc(this->data, this->length + 1);

    if (this->data == NULL) {
        std::cout << "Error: Memory allocation failed." << std::endl;
    }

    for (int i = 0; otro.data[i] != '\0'; i++) {
        this->data[i] = otro.data[i];
    }

    this->data[this->length] = '\0';

    return *this;
}

// Comparation
bool String::operator == (const String &otro) {
    if (this->length != otro.length) {
        return false;
    }

    for (int i = 0; this->data[i] != '\0'; i++) {
        if (this->data[i] != otro.data[i]) {
            return false;
        }
    }

    return true;
}

bool String::operator == (const char *str) {
    String newString(str);

    return (*this == newString);
}

bool String::operator != (const String &otro) {
    return !(*this == otro);
}

bool String::operator != (const char *str) {
    String newString(str);

    return (*this != newString);
}

// I/O
std::ostream& operator << (std::ostream &out, const String &str) {
    out << str.data;
    return out;
}

std::istream& operator >> (std::istream &in, String &str) {
    // Creates a defined size buffer
    char *buffer = (char*) calloc(100, sizeof(char));

    if (buffer == NULL) {
        std::cout << "Error: Memory allocation failed." << std::endl;
    }

    // Is readed from the input stream
    in >> buffer;

    // Resets the string
    str.length = 0;
    free(str.data);

    // Calculaters the length of the buffer string
    for (str.length = 0; buffer[str.length] != '\0'; str.length++) {
        continue;
    }

    // Allocates memory for the string
    str.data = (char*) calloc(str.length + 1, sizeof(char));

    if (str.data == NULL) {
        std::cout << "Error: Memory allocation failed." << std::endl;
    }

    // Copies the buffer string to the string
    for (int i = 0; buffer[i] != '\0'; i++) {
        str.data[i] = buffer[i];
    }

    // Terminates the string
    str.data[str.length] = '\0';

    // Frees the buffer
    free(buffer);

    return in;
}
