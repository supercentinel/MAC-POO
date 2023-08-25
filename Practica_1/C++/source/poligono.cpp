#include "poligono.hh"
#include <iostream>
#include "raylib.h"

// Constructor
Poligono::Poligono(Vector2 center, int sides, int radius, Color color) {
    this->center = center;
    this->sides = sides;
    this->radius = radius;
    this->color = color;
    this->rotation = 0.0;
    calculatePerimeter();
    calculateArea();
}

//getters
Vector2 Poligono::getCenter() {
    return center;
}

int Poligono::getRadius() {
    return radius;
}

int Poligono::getSides() {
    return sides;
}

double Poligono::getArea() {
    return area;
}

double Poligono::getPerimeter() {
    return perimeter;
}

float Poligono::getRotation() {
    return rotation;
}

Color Poligono::getColor() {
    return color;
}

//setters
void Poligono::setCenter(Vector2 center) {
    this->center = center;
}

void Poligono::setRadius(int radius) {
    this->radius = radius;
    update();
}

void Poligono::setSides(int sides) {
    this->sides = sides;
    update();
}

void Poligono::setRotation(float rotation) {
    this->rotation = rotation;
}

void Poligono::setColor(Color color) {
    this->color = color;
}

//methods
void Poligono::calculateArea() {
    double apothem = radius * cos(PI / sides);
    area = 0.5 * apothem * perimeter;
}

void Poligono::calculatePerimeter() {
    double sideLength = 2 * radius * sin(PI / sides);
    perimeter = sides * sideLength;
}

void Poligono::print() {
    std::cout << "Center: (" << center.x << ", " << center.y << ")" << std::endl;
    std::cout << "Radius: " << radius << std::endl;
    std::cout << "Sides: " << sides << std::endl;
    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;
}

void Poligono::draw() {
    DrawPoly(center, sides, radius, rotation, color);
}

void Poligono::update() {
    calculatePerimeter();
    calculateArea();
}
