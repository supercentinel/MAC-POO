#include "elipse.hh"
#include <iostream>
#include <cmath>
#include "raylib.h"

//constructor
Elipse::Elipse(Vector2 center, double a, double b, Color color) {
    this->center = center;
    this->a = a;
    this->b = b;
    this->color = color;
    calculateC();
    calculateE();
    calculateArea();
    calculatePerimeter();
}
//getters
Vector2 Elipse::getCenter() {
    return center;
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

Color Elipse::getColor() {
    return color;
}

double Elipse::getArea() {
    return area;
}

double Elipse::getPerimeter() {
    return perimeter;
}
//setters
void Elipse::setCenter(Vector2 center) {
    this->center = center;
}

void Elipse::setA(double a) {
    this->a = a;
}

void Elipse::setB(double b) {
    this->b = b;
}

void Elipse::setColor(Color color) {
    this->color = color;
}
//methods
void Elipse::calculateC() {
    if (a < b) {
        c = sqrt((b * b) - (a * a));
    } else {
        c = sqrt((a * a) - (b * b));
    }
}

void Elipse::calculateE() {
    if (c > a) {
        e = a / c;
    } else {
        e = c / a;
    }
}

void Elipse::calculateArea() {
    area = M_PI * a * b;
}

void Elipse::calculatePerimeter() {
    perimeter = 2 * M_PI * sqrt((a * a + b * b) / 2);
}
void Elipse::print() {
    std::cout << "Elipse: " << std::endl;
    std::cout << "x: " << center.x << std::endl;
    std::cout << "y: " << center.y << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "area: " << area << std::endl;
    std::cout << "perimeter: " << perimeter << std::endl;
    std::cout << "color: " << color.r << ", " << color.g << ", " << color.b << ", " << color.a << std::endl;
}

void Elipse::draw() {
    DrawEllipse(center.x, center.y, a, b, color);
}

void Elipse::update() {
    calculateC();
    calculateE();
    calculateArea();
    calculatePerimeter();
}
