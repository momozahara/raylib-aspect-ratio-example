#include <raylib.h>

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1280, 720, "Window");

    RenderTexture2D texture = LoadRenderTexture(1920, 1080);

    while (!WindowShouldClose())
    {
        BeginTextureMode(texture);
            ClearBackground(RAYWHITE);
            DrawText("Hello World!", 50, 50, 40, LIGHTGRAY);
        EndTextureMode();
        
        BeginDrawing();
            ClearBackground(BLACK);
            
            float x = (float)GetScreenWidth() / 1920.f;
            float y = (float)GetScreenHeight() / 1080.f;

            if (x > y)
            {
                x = y;
            }
            if (y > x)
            {
                y = x;
            }

            float outWidth = 1920.f * x;
            float outHeight = 1080.f * y;

            float posx = ((float)GetScreenWidth() - outWidth) / 2.f;
            float posy = ((float)GetScreenHeight() - outHeight) / 2.f;
            DrawTexturePro(texture.texture,
                            { 0, 0, (float)texture.texture.width, -(float)texture.texture.height },
                            { posx, posy, outWidth, outHeight },
                            { 0, 0 },
                            0.f,
                            WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
