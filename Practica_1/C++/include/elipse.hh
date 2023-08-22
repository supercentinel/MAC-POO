//elipse class
#ifndef ELIPSE_HH
#define ELIPSE_HH

#include "raylib.h"

class Elipse {
    private:
        int x;
        int y;
        double a;
        double b;
        double c;
        double e;
        double area;
        double perimeter;
        Color color;
    public:
        Elipse(int x, int y, double a, double b);
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();
        void setA(double a);
        void setB(double b);
        void calculateC();
        void calculateE();
        double getA();
        double getB();
        double getC();
        double getE();
        void calculateArea();
        void calculatePerimeter();
        double getArea();
        double getPerimeter();
        void setColor(Color color);
        Color getColor();
        void print();
        void draw();
};
#endif

