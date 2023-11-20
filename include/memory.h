#ifndef MEMORY_H
#define MEMORY_H

#include "types.h"

#define MEM_IO 0x04000000
#define MEM_VRAM 0x06000000

// Display control register
// USed for setting display modes and background layers.
#define REG_DISPCNT *((volatile u32*)(MEM_IO+0x0000))

#endif // MEMORY_H