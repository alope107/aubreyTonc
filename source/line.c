#include "types.h"
#include "memory.h"
#include "graphics.h"
#include "math.h"

void draw_circle(int x, int y, int radius, COLOR color) {
    int minX = MIN(x-radius, 0);
    int minY = MIN(y-radius, 0);
    int maxX = MAX(x+radius, SCREEN_WIDTH-1);
    int maxY = MAX(y+radius, SCREEN_HEIGHT-1);

    for(int ix = minX; ix < maxX; ix++) {
        for(int iy = minY; iy < maxY; iy++) {
            int dx = ix - x;
            int dy = iy - y;

            if (dx*dx + dy*dy <= radius*radius) {
                m3_plot(ix, iy, color);
            }
        }
    }
}

int main () {
    REG_DISPCNT = DCNT_MODE3 | DCNT_BG2;

    int centerX = SCREEN_WIDTH >> 1;
    int centerY = SCREEN_HEIGHT >> 1;

    draw_circle(centerX, centerY, 20, C_YELLOW);

    draw_circle(centerX+15, centerY-10, 5, C_CYAN);
    draw_circle(centerX+15, centerY-10, 2, C_BLACK);

    draw_circle(centerX-15, centerY-10, 5, C_CYAN);
    draw_circle(centerX-15, centerY-10, 2, C_BLACK);

    draw_circle(centerX, centerY+10, 7, C_BLACK);
    draw_circle(centerX, centerY+7, 5, C_YELLOW);

    for(;;) {}

    return 0;
}