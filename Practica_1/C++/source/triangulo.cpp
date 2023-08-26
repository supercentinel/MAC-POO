#include <iostream>
#include <cmath>

#include "raylib.h"
#include "triangulo.hh"

Triangulo::Triangulo(Vector2 center , Color color){
    this->center = center;
    this->a = Vector2{center.x, center.y - 50};
    this->b = Vector2{center.x - 55, center.y + 50};
    this->c = Vector2{center.x + 55, center.y + 50};
    this->color = color;
    calculateArea();
    calculatePerimeter();
}
//setters
void Triangulo::setCenter(Vector2 center){
    this->center = center;
}

void Triangulo::setA(Vector2 a){
    this->a = a;
    update();
}

void Triangulo::setB(Vector2 b){
    this->b = b;
    update();
}

void Triangulo::setC(Vector2 c){
    this->c = c;
    update();
}
void Triangulo::setColor(Color color){
    this->color = color;
}
//getters
Vector2 Triangulo::getCenter(){
    return center;
}

Vector2 Triangulo::getA(){
    return a;
}

Vector2 Triangulo::getB(){
    return b;
}

Vector2 Triangulo::getC(){
    return c;
}

double Triangulo::getArea(){
    return area;
}

double Triangulo::getPerimeter(){
    return perimeter;
}

Color Triangulo::getColor(){
    return color;
}
//methods
void Triangulo::draw(){
    DrawTriangle(a, b, c, color);
}

void Triangulo::calculateArea() {
    area = abs((a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y))/2);
}

void Triangulo::calculatePerimeter() {
    perimeter = sqrt(pow((b.x-a.x),2)+pow((b.y-a.y),2)) + sqrt(pow((c.x-b.x),2)+pow((c.y-b.y),2)) + sqrt(pow((c.x-a.x),2)+pow((c.y-a.y),2));
}

void Triangulo::update(){
    calculateArea();
    calculatePerimeter();
}
