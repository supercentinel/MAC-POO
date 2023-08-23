//triangle class
#ifndef TRIANGULO_HH
#define TRIANGULO_HH

#include "raylib.h"

class Triangulo{
    private:
        int x;
        int y;
        Vector2 a;
        Vector2 b;
        Vector2 c;
        double area;
        double perimeter;
        Color color;
    public:
        //constructors
        Triangulo(int x, int y, Vector2 a, Vector2 b, Vector2 c);
        //setters
        void setX(int x);
        void setY(int y);
        void setA(Vector2 a);
        void setB(Vector2 b);
        void setC(Vector2 c);
        void calculateArea(double area);
        void calculatePerimeter(double perimetro);
        void setColor(Color color);
        //getters
        int getX();
        int getY();
        Vector2 getA();
        Vector2 getB();
        Vector2 getC();
        double getArea();
        double getPerimeter();
        void draw();
        Color getColor();
};

#endif
