#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>

class Matriz {
    private:
        // i
        unsigned int rows;
        // j
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
        //Setters
        void setData(unsigned int i, unsigned int j, double value);
        // Methods
        std::string toTeX(char brackets, unsigned int decimals);
        double det();
        Matriz transpose();
        Matriz minor(unsigned int _i, unsigned int _j);
        double cofactor(unsigned int _i, unsigned int _j);
        Matriz cofactorMatrix();
        Matriz adj();
        Matriz inverse();
        // Operator overloading
        // =
        Matriz operator = (const Matriz &otro);
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
        friend std::ostream & operator << (std::ostream &out, const Matriz &m);
        friend std::istream & operator >> (std::istream &in, Matriz &m);
};

#endif
