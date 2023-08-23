#include <iostream>

#include "raylib.h"

int main() {
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTriangle((Vector2){100,10}, (Vector2){10, 200} , (Vector2){200, 100}, VIOLET);


        EndDrawing();
    }



    return 0;
}
