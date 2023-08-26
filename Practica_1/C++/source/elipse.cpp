#include "elipse.hh"
#include <iostream>
#include <cmath>
#include "raylib.h"

Elipse::Elipse(int x, int y, double a, double b, Color color) {
    this->x = x;
    this->y = y;
    this->a = a;
    this->b = b;
    this->color = color;
    calculateC();
    calculateE();
    calculateArea();
    calculatePerimeter();
}

void Elipse::setX(int x) {
    this->x = x;
}

void Elipse::setY(int y) {
    this->y = y;
}

int Elipse::getX() {
    return x;
}

int Elipse::getY() {
    return y;
}

void Elipse::setA(double a) {
    this->a = a;
}

void Elipse::setB(double b) {
    this->b = b;
}

void Elipse::calculateC() {
    c = sqrt((a * a) - (b * b));
}

void Elipse::calculateE() {
    e = c / a;
}

double Elipse::getA() {
    return a;
}

double Elipse::getB() {
    return b;
}

double Elipse::getC() {
    return c;
}

double Elipse::getE() {
    return e;
}

void Elipse::calculateArea() {
    area = M_PI * a * b;
}

void Elipse::calculatePerimeter() {
    perimeter = 2 * M_PI * sqrt((a * a + b * b) / 2);
}

double Elipse::getArea() {
    return area;
}

double Elipse::getPerimeter() {
    return perimeter;
}

void Elipse::setColor(Color color) {
    this->color = color;
}

Color Elipse::getColor() {
    return color;
}

void Elipse::print() {
    std::cout << "Elipse: " << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "area: " << area << std::endl;
    std::cout << "perimeter: " << perimeter << std::endl;
    std::cout << "color: " << color.r << ", " << color.g << ", " << color.b << ", " << color.a << std::endl;
}

void Elipse::draw() {
    DrawEllipse(x, y, a, b, color);
}

void Elipse::update() {
    calculateC();
    calculateE();
    calculateArea();
    calculatePerimeter();
}
