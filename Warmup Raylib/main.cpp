#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#include "Button.h"
#include <time.h>
#include <iostream>

int main(int argc, char* argv[])
{
    int screenWidth = 800;
    int screenHeight = 450;
    srand(time(0));
    InitWindow(screenWidth, screenHeight, "Raylib Warmup Button");
    SetTargetFPS(60);

    Button* btn = new Button("A GRANDMA", { 10, 10, 300, 200 }, Fade(GOLD, 0.6));
    btn->OnClick([]() {
        std::cout << "Hello World" << std::endl;
        });

    btn->OnHover([](Rectangle rectangle) {
        DrawRectangleRec(rectangle, Fade(GRAY, 0.4));
        });

    // Lets you override drawing.
    //btn->OnDraw([](Rectangle rectangle) {
    //    DrawRectangleRec(rectangle, Fade(BLUE, 0.4));
    //    });

    while (!WindowShouldClose())
    {
        btn->Update();

        BeginDrawing();
            ClearBackground(RAYWHITE);

            btn->Draw();
        EndDrawing();
    }

    delete btn;

    CloseWindow();
    return 0;
}