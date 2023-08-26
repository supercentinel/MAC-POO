#include <iostream>
#include <cmath>

#include "raylib.h"
#include "randomColor.h"
#include "triangulo.hh"

int main() {
    int screenWidth = 1280;
    int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Triangulo");

    SetTargetFPS(60);

    Triangulo t_0 = Triangulo(Vector2{640, 460}, BLUE);

    while (!WindowShouldClose()) {
        //input
        //movement of vertices
        //A
        if (IsKeyDown(KEY_E)) {
            t_0.setA(Vector2{t_0.getA().x, t_0.getA().y - 1});
        }
        if (IsKeyDown(KEY_W)) {
            t_0.setA(Vector2{t_0.getA().x, t_0.getA().y + 1});
        }
        if (IsKeyDown(KEY_Q)) {
            t_0.setA(Vector2{t_0.getA().x - 1, t_0.getA().y});
        }
        if (IsKeyDown(KEY_R)) {
            t_0.setA(Vector2{t_0.getA().x + 1, t_0.getA().y});
        }
        //B
        if (IsKeyDown(KEY_D)) {
            t_0.setB(Vector2{t_0.getB().x, t_0.getB().y - 1});
        }
        if (IsKeyDown(KEY_S)) {
            t_0.setB(Vector2{t_0.getB().x, t_0.getB().y + 1});
        }
        if (IsKeyDown(KEY_A)) {
            t_0.setB(Vector2{t_0.getB().x - 1, t_0.getB().y});
        }
        if (IsKeyDown(KEY_F)) {
            t_0.setB(Vector2{t_0.getB().x + 1, t_0.getB().y});
        }
        //C
        if (IsKeyDown(KEY_C)) {
            t_0.setC(Vector2{t_0.getC().x, t_0.getC().y - 1});
        }
        if (IsKeyDown(KEY_X)) {
            t_0.setC(Vector2{t_0.getC().x, t_0.getC().y + 1});
        }
        if (IsKeyDown(KEY_Z)) {
            t_0.setC(Vector2{t_0.getC().x - 1, t_0.getC().y});
        }
        if (IsKeyDown(KEY_V)) {
            t_0.setC(Vector2{t_0.getC().x + 1, t_0.getC().y});
        }
        //movement of the triangle
        if (IsKeyDown(KEY_UP)) {
            t_0.setA(Vector2{t_0.getA().x, t_0.getA().y - 1});
            t_0.setB(Vector2{t_0.getB().x, t_0.getB().y - 1});
            t_0.setC(Vector2{t_0.getC().x, t_0.getC().y - 1});
        }
        if (IsKeyDown(KEY_DOWN)) {
            t_0.setA(Vector2{t_0.getA().x, t_0.getA().y + 1});
            t_0.setB(Vector2{t_0.getB().x, t_0.getB().y + 1});
            t_0.setC(Vector2{t_0.getC().x, t_0.getC().y + 1});
        }
        if (IsKeyDown(KEY_LEFT)) {
            t_0.setA(Vector2{t_0.getA().x - 1, t_0.getA().y});
            t_0.setB(Vector2{t_0.getB().x - 1, t_0.getB().y});
            t_0.setC(Vector2{t_0.getC().x - 1, t_0.getC().y});
        }
        if (IsKeyDown(KEY_RIGHT)) {
            t_0.setA(Vector2{t_0.getA().x + 1, t_0.getA().y});
            t_0.setB(Vector2{t_0.getB().x + 1, t_0.getB().y});
            t_0.setC(Vector2{t_0.getC().x + 1, t_0.getC().y});
        }
        //change to a random color
        if (IsKeyPressed(KEY_SPACE)) {
            t_0.setColor(getRandomColor());
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        //Instructions
        DrawText("Use the keys to move the triangle.", 10, 10, 20, DARKGRAY);
        DrawText("USE Q W E R to move A vertex. Like in Vim", 10, 30, 20, DARKGRAY);
        DrawText("USE A S D F to move B vertex.", 10, 50, 20, DARKGRAY);
        DrawText("USE Z X C V to move C vertex.", 10, 70, 20, DARKGRAY);
        DrawText("Press SPACE to randomize the color of the triangle.", 10, 90, 20, DARKGRAY);
        t_0.draw();
        //Values
        DrawText("A", t_0.getA().x, t_0.getA().y, 20, DARKGRAY);
        DrawText("B", t_0.getB().x, t_0.getB().y, 20, DARKGRAY);
        DrawText("C", t_0.getC().x, t_0.getC().y, 20, DARKGRAY);

        DrawText(("A: " + std::to_string(t_0.getA().x) + " " + std::to_string(t_0.getA().y)).c_str(), screenWidth-300, 10, 20, DARKGRAY);
        DrawText(("B: " + std::to_string(t_0.getB().x) + " " + std::to_string(t_0.getB().y)).c_str(), screenWidth-300, 30, 20, DARKGRAY);
        DrawText(("C: " + std::to_string(t_0.getC().x) + " " + std::to_string(t_0.getC().y)).c_str(), screenWidth-300, 50, 20, DARKGRAY);
        DrawText(("Area: " + std::to_string(t_0.getArea())).c_str(), screenWidth-300, 70, 20, DARKGRAY);
        DrawText(("Perimeter: " + std::to_string(t_0.getPerimeter())).c_str(), screenWidth-300, 90, 20, DARKGRAY);

        EndDrawing();
    }

    return 0;
}
