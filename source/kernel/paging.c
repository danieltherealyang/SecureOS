#include "paging.h"

uint32_t page_directory[1024] __attribute__((aligned(4096)));
uint32_t first_page_table[1024] __attribute__((aligned(4096)));

void enable_paging() {
	for (int i = 0; i < 1024; i++) {
		page_directory[i] = 0x00000002;
	}
	for (int i = 0; i < 1024; i++) {
		first_page_table[i] = (i * 0x1000) | 3;
	}
	page_directory[0] = ((unsigned int)first_page_table) | 3;
	// __asm__ (
	// 	"mov eax, %0\n"
 	// 	"mov cr3, eax\n"
 	// 	"mov eax, cr0\n"
 	// 	"or eax, 0x80000001\n"
 	// 	"mov cr0, eax\n"
	// 	:
	// 	: "r" (page_directory)
	// );
}
//Declare data aligned with some mark (1 page directory, 1 page table)
//4 gb , 1024 4-byte entries = 4096
// uint32_t page_dir[1024] __attribute__((aligned(4096)));
// uint32_t page_table_one[1024] __attribute__((aligned(4096)));

// void load_page() {
// 	//blank the page directory
// 	for (int i = 0; i < 1024; i++) { //blank all 1024 entries
// 		page_dir[i] = 0x00000002; //page fault 
// 	}

// 	//Create first page table
// 	for (int i = 0; i < 1024; i++) { 
// 		page_table_one[i] = (i * 0x1000) | 3; //
// 	}
// 	page_dir[0] = ((unsigned int)page_table_one) | 3;

// 	//loadPageDirectory(page_dir);
// 	//enablePaging();

// }

