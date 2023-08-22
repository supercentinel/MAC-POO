#include <iostream>
#include <raylib.h>

class Circulo {
    private:
        double radius;
        double x;
        double y;
        double area;
        double perimeter;
    public:
    Circulo(double r) {
        this->x = 0.0;
        this->y = 0.0;
        this->radius= r;
        setArea();
    }

    double getRadius() {
        return this->radius;
    }

    void setRadius(double r) {
        this->radius = r;
        setArea();
        setPerimeter();
    }

    double getPerimeter() {
        return this->perimeter;
    }

    void setPerimeter() {
        this->perimeter = 2 * PI * this->radius;
    }

    double getArea() {
        return this->area;
    }

    void setArea() {
        this->area = PI * this->radius * this->radius;
    }

    void print() {
        std::cout << "radius: " << this->radius << std::endl;
        std::cout << "area: " << this->area << std::endl;
        std::cout << "x: " << this->x << std::endl;
        std::cout << "y: " << this->y << std::endl;
    }

    void setPosition(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double getX () {
        return this->x;
    }

    double getY () {
        return this->y;
    }

    void draw() {
        DrawCircle(this->x, this->y, this->radius, RED);
    }
};

int main(void) {
    Circulo a = Circulo(35.0);

    a.print();

    InitWindow(800, 600, "Circulo");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_RIGHT)) {
            a.setPosition(a.getX() + 1, a.getY());
        }

        if (IsKeyDown(KEY_LEFT)) {
            a.setPosition(a.getX() - 1, a.getY());
        }

        if (IsKeyDown(KEY_UP)) {
            a.setPosition(a.getX(), a.getY() - 1);
        }

        if (IsKeyDown(KEY_DOWN)) {
            a.setPosition(a.getX(), a.getY() + 1);
        }

        if(IsKeyDown(KEY_A)) {
            a.setRadius(a.getRadius() + 1);
        }

        if(IsKeyDown(KEY_S)) {
            a.setRadius(a.getRadius() - 1);
        }

        BeginDrawing();
            DrawText("Area: ", 10, 10, 20, WHITE);
            DrawText(std::to_string(a.getArea()).c_str(), 100, 10, 20, WHITE);

            ClearBackground(BLACK);
            a.draw();
        EndDrawing();
    }

    return 0;
}
