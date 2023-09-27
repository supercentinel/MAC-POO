#include <iostream>

#include "fraccion.hpp"

//Constructors
Fraccion::Fraccion() {
    this->a = 0;
    this->b = 1;
}

Fraccion::Fraccion(int a, int b) {
    this->a = a;
    this->b = b;
}

//Getters
int Fraccion::getA()  {
    return this->a;
}
int Fraccion::getB()  {
    return this->b;
}

//Setters
void Fraccion::setA(int a) {
    this->a = a;
}

void Fraccion::setB(int b) {
    this->b = b;
}

//Methods
std::string Fraccion::toLatex() {
    std::string result = "\\frac{" + std::to_string(this->a) + "}{" + std::to_string(this->b) + "}";
    return result;
}

void Fraccion::normalize() {
    if (this->b < 0) {
        this->a *= -1;
        this->b *= -1;
    }
}

void Fraccion::reduce() {
    int a = this->a;
    int b = this->b;

    int mcd = 1;

    for (int i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) {
            mcd = i;
        }
    }

    this->a = a / mcd;
    this->b = b / mcd;
}
// To other types
int Fraccion::toInt() {
    Fraccion dummy = *this;
    dummy.reduce();

    if(dummy.b == 1) {
        return dummy.a;
    } else {
        return 0;
    }
}

float Fraccion::toFloat() {
    return (float) this->a / (float) this->b;
}

double Fraccion::toDouble() {
    return (double) this->a / (double) this->b;
}
// Oprerator overloading
// +
Fraccion Fraccion::operator + (const Fraccion &otro) {
    int a = this->a * otro.b + otro.a * this->b;
    int b = this->b * otro.b;

    Fraccion result(a, b);

    result.normalize();

    return result;
}

Fraccion Fraccion::operator + (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    return *this + itof;
}

Fraccion Fraccion::operator += (const Fraccion &otro) {
    *this = *this + otro;

    return *this;
}

Fraccion Fraccion::operator += (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    *this = *this + itof;

    return *this;
}

Fraccion Fraccion::operator ++ () {
    *this += 1;

    return *this;
}

Fraccion Fraccion::operator - (const Fraccion &otro) {
    int a = this->a * otro.b - otro.a * this->b;
    int b = this->b * otro.b;

    Fraccion result(a, b);

    result.normalize();

    return result;
}
// -
Fraccion Fraccion::operator - (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    return *this - itof;
}

Fraccion Fraccion::operator -= (const Fraccion &otro) {
    *this = *this - otro;

    return *this;
}

Fraccion Fraccion::operator -= (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    *this = *this - itof;

    return *this;
}

Fraccion Fraccion::operator -- () {
    *this -= 1;

    return *this;
}
// *
Fraccion Fraccion::operator * (const Fraccion &otro) {
    int a = this->a * otro.a;
    int b = this->b * otro.b;

    Fraccion result(a, b);

    result.normalize();

    return result;
}

Fraccion Fraccion::operator * (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    return *this * itof;
}

Fraccion Fraccion::operator *= (const Fraccion &otro) {
    *this = *this * otro;

    return *this;
}

Fraccion Fraccion::operator *= (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    *this = *this * itof;

    return *this;
}
// /
Fraccion Fraccion::operator / (const Fraccion &otro) {
    int a = this->a * otro.b;
    int b = this->b * otro.a;

    Fraccion result(a, b);

    result.normalize();

    return result;
}

Fraccion Fraccion::operator / (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    return *this / itof;
}

Fraccion Fraccion::operator /= (const Fraccion &otro) {
    *this = *this / otro;

    return *this;
}

Fraccion Fraccion::operator /= (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    *this = *this / itof;

    return *this;
}
// Order operators
bool Fraccion::operator == (const Fraccion &otro) {

    Fraccion dummy1(*this);
    Fraccion dummy2(otro);

    dummy1.normalize();
    dummy2.normalize();

    return (dummy1.a == dummy2.a && dummy1.b == dummy2.b);
}

bool Fraccion::operator == (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    return *this == itof;
}

bool Fraccion::operator != (const Fraccion &otro) {
    return !(*this == otro);
}

bool Fraccion::operator != (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    return *this != itof;
}

bool Fraccion::operator < (const Fraccion &otro) {
    int a = this->a * otro.b;
    int b = this->b * otro.a;

    return a < b;
}

bool Fraccion::operator < (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    return *this < itof;
}

bool Fraccion::operator <= (const Fraccion &otro) {
    if (*this == otro) {
        return true;
    }

    return *this < otro;
}

bool Fraccion::operator <= (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    return *this <= itof;
}

bool Fraccion::operator > (const Fraccion &otro) {
    int a = this->a * otro.b;
    int b = this->b * otro.a;

    return a > b;
}

bool Fraccion::operator > (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    return *this > itof;
}

bool Fraccion::operator >= (const Fraccion &otro) {
    if (*this == otro) {
        return true;
    }

    return *this > otro;
}

bool Fraccion::operator >= (int otro) {
    Fraccion itof = Fraccion(otro, 1);

    return *this >= itof;
}

// I/O
std::ostream & operator << (std::ostream &out, const Fraccion &f) {
    out << f.a << "/" << f.b;

    return out;
}

std::istream & operator >> (std::istream &in, Fraccion &f) {

    std::cout << "a: ";
    in >> f.a;
    std::cout << "b: ";
    in >> f.b;

    return in;
}
