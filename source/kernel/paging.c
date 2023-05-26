#include "paging.h"

//Declare data aligned with some mark (1 page directory, 1 page table)
//4 gb , 1024 4-byte entries = 4096
uint32_t page_dir[1024] __attribute__((aligned(4096)));
uint32_t page_table_one[1024] __attribute__((aligned(4096)));

void main() {
	//blank the page directory
	for (int i = 0; i < 1024; i++) { //blank all 1024 entries
		page_dir[i] = 0x00000002; //page fault 
	}

	//Create first page table
	for (int i = 0; i < 1024; i++) { 
		page_table_one[i] = (i * 0x1000) | 3; //
	}
	page_dir[0] = ((unsigned int)page_table_one) | 3;

	//loadPageDirectory(page_dir);
	//enablePaging();

}

