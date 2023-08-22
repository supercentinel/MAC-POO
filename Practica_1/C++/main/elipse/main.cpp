#include <iostream>
#include <cmath>

#include "raylib.h"
#include "elipse.hh"

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Elipse");
    SetTargetFPS(60);

    Elipse e_0 = Elipse(100, 100, 250.00, 50.00);
    e_0.setColor((Color){161, 0, 24, 255});

    e_0.print();

    while (!WindowShouldClose()) {
        BeginDrawing();

        if (IsKeyDown(KEY_UP)) {
            e_0.setY(e_0.getY() - 1);
        }

        if (IsKeyDown(KEY_DOWN)) {
            e_0.setY(e_0.getY() + 1);
        }

        if (IsKeyDown(KEY_LEFT)) {
            e_0.setX(e_0.getX() - 1);
        }

        if (IsKeyDown(KEY_RIGHT)) {
            e_0.setX(e_0.getX() + 1);
        }

        if (IsKeyDown(KEY_W)) {
            e_0.setB(e_0.getB() + 1);
            e_0.update();
        }

        if (IsKeyDown(KEY_S)) {
            e_0.setB(e_0.getB() - 1);
            e_0.update();
        }

        if (IsKeyDown(KEY_A)) {
            e_0.setA(e_0.getA() + 1);
            e_0.update();
        }

        if (IsKeyDown(KEY_D)) {
            e_0.setA(e_0.getA() - 1);
            e_0.update();
        }

        ClearBackground(RAYWHITE);
        //Instructions
        DrawText("Use the arrow keys to move the elipse", 10, 10, 20, DARKGRAY);
        DrawText("Use W and S to change the B value", 10, 30, 20, DARKGRAY);
        DrawText("Use A and D to change the A value", 10, 50, 20, DARKGRAY);

        //Values
        //Area
        DrawText("Area: ", screenWidth-200, 10, 20,  DARKGRAY);
        DrawText(std::to_string(e_0.getArea()).c_str(), screenWidth-200, 30, 20,  DARKGRAY);
        //Perimeter
        DrawText("Perimeter: ", screenWidth-200, 50, 20,  DARKGRAY);
        DrawText(std::to_string(e_0.getPerimeter()).c_str(), screenWidth-200, 70, 20,  DARKGRAY);
        //C
        DrawText("C: ", screenWidth-200, 90, 20,  DARKGRAY);
        DrawText(std::to_string(e_0.getC()).c_str(), screenWidth-200, 110, 20,  DARKGRAY);
        //E
        DrawText("E: ", screenWidth-200, 130, 20,  DARKGRAY);
        DrawText(std::to_string(e_0.getE()).c_str(), screenWidth-200, 150, 20,  DARKGRAY);
        //Position

        DrawText("Position: ", screenWidth-200, 170, 20,  DARKGRAY);
        //X
        DrawText("X: ", screenWidth-200, 190, 20,  DARKGRAY);
        DrawText(std::to_string(e_0.getX()).c_str(), screenWidth-180, 190, 20,  DARKGRAY);
        //Y
        DrawText("Y: ", screenWidth-200, 210, 20,  DARKGRAY);
        DrawText(std::to_string(e_0.getY()).c_str(), screenWidth-180, 210, 20,  DARKGRAY);

        if(IsKeyDown(KEY_M)) {
            e_0.print();
        }

        e_0.draw();

        EndDrawing();
    }

    return 0;
}
