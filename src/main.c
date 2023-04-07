#include <stdio.h>
#include <SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL Window",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH,
                                          SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Texture* texture = SDL_CreateTexture(renderer,
                                              SDL_PIXELFORMAT_RGBA8888,
                                              SDL_TEXTUREACCESS_STREAMING,
                                              SCREEN_WIDTH, SCREEN_HEIGHT);
    int pixels[SCREEN_WIDTH * SCREEN_HEIGHT];
    int rect_width = 200;
    int rect_height = 100;
    int rect_x = (SCREEN_WIDTH - rect_width) / 2;
    int rect_y = (SCREEN_HEIGHT - rect_height) / 2;
    int rect_right = rect_x + rect_width;
    int rect_bottom = rect_y + rect_height;
    int red = 0xFF0000FF;
    int white = 0xFFFFFFFF;

    while (1) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                SDL_Quit();
                return 0;
            }
        }

        // Update pixel array
        for (int y = 0; y < SCREEN_HEIGHT; y++) {
            for (int x = 0; x < SCREEN_WIDTH; x++) {
                int i = y * SCREEN_WIDTH + x;
                if (x >= rect_x && x < rect_right && y >= rect_y && y < rect_bottom) {
                    pixels[i] = red;  // Inside rectangle
                } else {
                    pixels[i] = white;  // Outside rectangle
                }
            }
        }

        // Update texture with pixel array
        SDL_UpdateTexture(texture, NULL, pixels, SCREEN_WIDTH * sizeof(Uint32));

        // Render texture to screen
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
}
