#include "types.h"
#include "memory.h"
#include "graphics.h"

int main () {
    REG_DISPCNT = DCNT_MODE3 | DCNT_BG2;
    
    u32 x, y;
    for (y = 0; y < SCREEN_HEIGHT; y++) {
        for(x = 0; x < SCREEN_WIDTH; x++){
            m3_plot(x, y, x*x + y*y);
        };
    }

    return 0;
}