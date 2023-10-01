#include <cmath>
#include <iostream>

#include "complejo.hpp"


// Constructors
Complejo::Complejo() {
    this->a = 0;
    this->b = 0;
    this->theta = 0;
    this->r = 0;
}

Complejo::Complejo(double a, double b) {
    this->a = a;
    this->b = b;
    this->calculatePolar();
}

Complejo::Complejo(double r, double theta, bool polar) {
    this->r = r;
    this->theta = theta;
    this->calculateCartesian();
}

// Getters
double Complejo::getA() {
    return this->a;
}

double Complejo::getB() {
    return this->b;
}

double Complejo::getTheta() {
    return this->theta;
}

double Complejo::getR() {
    return this->r;
}

// Setters
void Complejo::setA(double a) {
    this->a = a;
    this->calculatePolar();
}

void Complejo::setB(double b) {
    this->b = b;
    this->calculatePolar();
}

void Complejo::setTheta(double theta) {
    this->theta = theta;
    this->calculateCartesian();
}

void Complejo::setR(double r) {
    this->r = r;
    this->calculateCartesian();
}

// Methods
void Complejo::calculatePolar() {
    this->r = this->magnitude();
    this->theta = this->arg();
}

void Complejo::calculateCartesian() {
    this->a = this->r * cos(this->theta);
    this->b = this->r * sin(this->theta);
}

void Complejo::printPolar() {
    std::cout << this->r << "cos(" << this->theta << ") + " << this->r << "sin(" << this->theta << ")i" << std::endl;
}

void Complejo::printCartesian() {
    std::cout << this->a << " + " << this->b << "i" << std::endl;
}

void Complejo::printExponential() {
    std::cout << this->r << "e^(" << this->theta << "i)" << std::endl;
}

double Complejo::magnitude() {
    return sqrt(pow(this->a, 2) + pow(this->b, 2));
}

Complejo Complejo::conjugate() {
    return Complejo(this->a, -this->b);
}

double Complejo::arg() {
    return atan(this->b / this->a);
}

std::string Complejo::toTeX(char form) {
    switch(form) {
        case 'c':
            return std::to_string(this->a) +
                " + " +
                std::to_string(this->b) + "i";
        break;
        case 'p':
            return std::to_string(this->r) +
                "\\cos(" +
                std::to_string(this->theta) + ") + " +
                std::to_string(this->r) +
                "i\\sin(" +
                std::to_string(this->theta) + ")";
        break;
        case 'e':
            return std::to_string(this->r) +
                "e^{" +
                std::to_string(this->theta) + "i}";
        default:
            return "";
        break;
    }
}
// Operator overloading
// +
Complejo Complejo::operator + (const Complejo &otro) {
    return Complejo(this->a + otro.a, this->b + otro.b);
}

Complejo Complejo::operator += (const Complejo &otro) {
    *this = *this + otro;
    this->calculatePolar();


    return *this;
}

// -
Complejo Complejo::operator - (const Complejo &otro) {
    return Complejo(this->a - otro.a, this->b - otro.b);
}

Complejo Complejo::operator -= (const Complejo &otro) {
    *this = *this - otro;
    this->calculatePolar();

    return *this;
}

// *
Complejo Complejo::operator * (const Complejo &otro) {
    double a = (this->a * otro.a) - (this->b * otro.b);
    double b = (this->a * otro.b) + (this->b * otro.a);

    return Complejo(a, b);
}

Complejo Complejo::operator *= (const Complejo &otro) {
    *this = *this * otro;
    this->calculatePolar();

    return *this;
}

// /
Complejo Complejo::operator / (Complejo &otro) {
    Complejo _conj = otro.conjugate();
    Complejo _num = *this * _conj;
    Complejo _den = otro * _conj;
    double den = _den.a - _den.b;

    double a = _num.a/den;
    double b = _num.b/den;

    return Complejo(a, b);
}

Complejo Complejo::operator /= (Complejo &otro) {
    *this = *this / otro;
    this->calculatePolar();

    return *this;
}
// ^
Complejo Complejo::operator ^ (int n) {
    Complejo z = *this;

    z.setTheta(z.getTheta() * n);
    z.calculateCartesian();

    return z;
}
// Comparators
bool Complejo::operator == (const Complejo &otro) {
    return (this->a == otro.a) && (this->b == otro.b);
}

bool Complejo::operator != (const Complejo &otro) {
    return !(*this == otro);
}

// I/O
std::ostream& operator << (std::ostream &out, const Complejo &c) {
    out << "a: " << c.a << std::endl;
    out << "b: " << c.b << std::endl;
    out << "theta: " << c.theta << std::endl;
    out << "r: " << c.r << std::endl;

    return out;
}

std::istream& operator >> (std::istream &in, Complejo &c) {
    std::cout << "a: ";
    in >> c.a;
    std::cout << "b: ";
    in >> c.b;

    c.calculatePolar();

    return in;
}
