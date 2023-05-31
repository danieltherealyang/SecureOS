#include "paging.h"
#include "kheap.h"

void initialise_paging() {
	//make a page directory
	page_directory_t* kernel_directory = kmalloc_a(sizeof(page_directory_t), 1);
	
	//need to implement frame allocation

	switch_page_directory(kernel_directory); //enable paging
}

void switch_page_directory(page_directory_t *dir) {
	//load dir
	asm volatile("mov %0, %%cr3":: "r"(&dir->tablesPhysical));
  	
	uint32_t cr0;
   	asm volatile("mov %%cr0, %0": "=r"(cr0));
   	cr0 |= 0x80000001; // enable
   	asm volatile("mov %0, %%cr0":: "r"(cr0));	
}

// retrieves ptr to page req'd; if make == 1, create page
page_t *get_page(uint32_t address, int make, page_directory_t *dir);



