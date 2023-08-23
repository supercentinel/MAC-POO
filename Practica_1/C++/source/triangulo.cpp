#include <iostream>

#include "raylib.h"
#include "triangulo.hh"

Triangulo::Triangulo(int x, int y, Vector2 a, Vector2 b, Vector2 c){
    this->x = x;
    this->y = y;
    this->a = a;
    this->b = b;
    this->c = c;
}

void Triangulo::setX(int x){
    this->x = x;
}

void Triangulo::setY(int y){
    this->y = y;
}

void Triangulo::setA(Vector2 a){
    this->a = a;
}

void Triangulo::setB(Vector2 b){
    this->b = b;
}

void Triangulo::setC(Vector2 c){
    this->c = c;
}
void Triangulo::setColor(Color color){
    this->color = color;
}

void Triangulo::calculateArea() {
    area =
}
