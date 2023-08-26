//triangle class
#ifndef TRIANGULO_HH
#define TRIANGULO_HH

#include <iostream>
#include <cmath>

#include "raylib.h"

class Triangulo{
    private:
        Vector2 center;
        Vector2 a;
        Vector2 b;
        Vector2 c;
        double area;
        double perimeter;
        Color color;
    public:
        //constructors
        Triangulo(Vector2 center, Vector2 a, Vector2 b, Vector2 c, Color color);
        //setters
        void setCenter(Vector2 center);
        void setA(Vector2 a);
        void setB(Vector2 b);
        void setC(Vector2 c);
        void calculateArea();
        void calculatePerimeter();
        void setColor(Color color);
        //getters
        Vector2 getCenter();
        Vector2 getA();
        Vector2 getB();
        Vector2 getC();
        Color getColor();
        //methods
        double getArea();
        double getPerimeter();
        void draw();
};

#endif
