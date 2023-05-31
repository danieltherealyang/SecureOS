#include "kheap.h"

uint32_t placement_address; //pointer to some free memory

uint32_t kmalloc_a(uint32_t size, int align) {
    if (align ==1 && (placement_address & 0xFFFF000)) //align the page
    {
        placement_address &= 0xFFFF000;
        placement_address += 0x1000;
    }
    uint32_t tmp = placement_address;
    placement_address += size;
    return tmp;
}