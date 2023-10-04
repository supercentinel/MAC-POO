#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>

class Matriz {
    private:
        unsigned int rows;
        unsigned int cols;
        double **data;
    public:
        // Constructors
        Matriz();
        Matriz(unsigned int rows, unsigned int cols);
        Matriz(const Matriz &otro);
        Matriz(std::string filename);
        // Destructor
        ~Matriz();
        // Getters
        unsigned int getRows();
        unsigned int getCols();
        // Methods
        std::string toTeX(char brackets, unsigned int decimals);
        double det();
        Matriz transpose();
        Matriz minor();
        double cofactor(unsigned int i, unsigned int j);
        Matriz adjoint();
        Matriz inverse();
        // Operator overloading
        // +
        Matriz operator + (const Matriz &otro);
        Matriz operator += (const Matriz &otro);
        // -
        Matriz operator - (const Matriz &otro);
        Matriz operator -= (const Matriz &otro);
        // *
        Matriz operator * (const Matriz &otro);
        Matriz operator * (const double &escalar);
        Matriz operator *= (const Matriz &otro);
        Matriz operator *= (const double &escalar);
        // I/O
        friend std::ostream & operator << (std::ostream &out, const Matriz &f);
        friend std::istream & operator >> (std::istream &in, Matriz &f);
};

#endif
