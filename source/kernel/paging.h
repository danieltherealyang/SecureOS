//did you know that enabling paging is extremely easy .

#ifndef PAGING_H
#define PAGING_H

//#include "common.h"
//#include "isr.h"
#include <stdint.h>

/*page directory entry (4 kb)
    1) P: bit set <=> page present in physical memory
    2) R/W: flag set <=> page is read/write (read only otherwise)
    3) U/S: set bit <=> accessible by all (supervisor only otherwise)
    4) A: set bit <=> PDF/PTW was read (not otherwise)
    5) D: set bit <=> page has been written to*/

typedef struct page
{
   uint32_t p          : 1;  
   uint32_t rw         : 1;  
   uint32_t us         : 1;   
   uint32_t pwt        : 1;
   uint32_t pcd        : 1;
   uint32_t a          : 1;  
   uint32_t d          : 1;
   uint32_t pat        : 1; 
   uint32_t g          : 1;
   uint32_t avl        : 3;   
   uint32_t frame      : 20;  
} page_t;

//page table's entries are pages, 4mb = 1024*4kb
typedef struct page_table
{
    page_t table[1024];
} page_table_t;

//page directory's entries point to page tables, 4gb = 1024*4mb
typedef struct page_directory
{
  //Format of a Linear Address: 0-11 offset, 12-21 page, 22-31 dir 
  
  //Each entry:
  page_table_t *tables[1024]; //each points to a page table
  uint32_t tablesPhysical[1024]; //the physical addresses of the ptrs above, loaded into cr3
  uint32_t physicalAddr; //address of tablesPhysical

} page_directory_t;

void setup_page();

void initialise_paging();

void switch_page_directory(page_directory_t *dir); //loading into cr3

// retrieves ptr to page req'd; if make == 1, create page
page_t *get_page(uint32_t address, int make, page_directory_t *dir);

#endif