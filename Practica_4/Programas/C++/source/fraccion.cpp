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

