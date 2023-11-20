#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "types.h" 
#include "memory.h" 

// Video memory modes
#define DCNT_MODE0     0x0000
#define DCNT_MODE1      0x0001
#define DCNT_MODE2      0x0002
#define DCNT_MODE3      0x0003
#define DCNT_MODE4      0x0004
#define DCNT_MODE5      0x0005
// layers
#define DCNT_BG0        0x0100
#define DCNT_BG1        0x0200
#define DCNT_BG2        0x0400
#define DCNT_BG3        0x0800
#define DCNT_OBJ        0x1000

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160

typedef u16 COLOR;

#define CLR_BLACK   0x0000
#define CLR_RED     0x001F
#define CLR_LIME    0x03E0
#define CLR_YELLOW  0x03FF
#define CLR_BLUE    0x7C00
#define CLR_MAG     0x7C1F
#define CLR_CYAN    0x7FE0
#define CLR_WHITE   0x7FFF

// Generates a 15 bit color.
// Each of red, green and blue must be in the range 0-31 inclusive
INLINE COLOR RGB15(u32 red, u32 green, u32 blue) {
    return (blue << 10) | (green << 5) | red ; 
}

// Pointer to start of video memory
// Video memory is made of a 16 bit COLOR for each pixel
#define vid_mem ((COLOR*)MEM_VRAM)

// Plot a single pixel in mode 3.
INLINE void m3_plot(int x, int y, COLOR clr) {
    vid_mem[x + y*SCREEN_WIDTH] = clr;
}

#endif // GRAPHICS_H