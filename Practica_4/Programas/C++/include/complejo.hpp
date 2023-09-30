#ifndef COMPLEJO_HPP
#define COMPLEJO_HPP

#include <iostream>

class Complejo {
    private:
        double a;
        double b;
        double theta;
        double r;
    public:
        // Constructors
        Complejo();
        Complejo(double a, double b);
        Complejo(double r, double theta, bool polar);
        // Getters
        double getA();
        double getB();
        double getTheta();
        double getR();
        // Setters
        void setA(double a);
        void setB(double b);
        void setTheta(double theta);
        void setR(double r);
        // Methods
        void calculatePolar();
        void calculateCartesian();
        void printPolar();
        void printCartesian();
        void printExponential();
        double magnitude();
        Complejo conjugate();
        double arg();
        double re();
        double im();
        std::string toTeX(char form);
        // Operator overloading
        Complejo operator + (const Complejo &otro);
        Complejo operator += (const Complejo &otro);
        // -
        Complejo operator - (const Complejo &otro);
        Complejo operator -= (const Complejo &otro);
        // *
        Complejo operator * (const Complejo &otro);
        Complejo operator *= (const Complejo &otro);
        // /
        Complejo operator / (const Complejo &otro);
        Complejo operator /= (const Complejo &otro);
        // ^
        Complejo operator ^ (const int &n);
        // order
        bool operator == (const Complejo &otro);
        bool operator != (const Complejo &otro);
        // I/O
        friend std::ostream & operator << (std::ostream &out, const Complejo &f);
        friend std::istream & operator >> (std::istream &in, Complejo &f);
};

#endif
