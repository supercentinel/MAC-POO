//elipse class
#ifndef ELIPSE_HH
#define ELIPSE_HH

#include "raylib.h"

class Elipse {
    private:
        Vector2 center;
        double a;
        double b;
        double c;
        double e;
        double area;
        double perimeter;
        Color color;
    public:
        Elipse(Vector2 center, double a, double b, Color color);
        //setters
        void setCenter(Vector2 center);
        void setA(double a);
        void setB(double b);
        void setColor(Color color);
        //getters
        Vector2 getCenter();
        double getA();
        double getB();
        double getC();
        double getE();
        double getArea();
        double getPerimeter();
        Color getColor();
        //methods
        void calculateC();
        void calculateE();
        void calculateArea();
        void calculatePerimeter();
        void print();
        void draw();
        void update();
};
#endif
