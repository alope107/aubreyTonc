int main () {
    *(unsigned int*)0x04000000 = 0x0403;
    
    unsigned short x;
    for(x = 0; x < 240; x++){
        ((unsigned short*)0x06000000)[x+80*240] = x << 10;
    };

    return 0;
}