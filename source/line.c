#include "types.h"
#include "memory.h"
#include "graphics.h"

int main () {
    REG_DISPCNT = DCNT_MODE3 | DCNT_BG2;
    
    unsigned short x;
    for(x = 0; x < SCREEN_WIDTH; x++){
        m3_plot(x, SCREEN_HEIGHT >> 1, x << 10);
    };

    return 0;
}