#ifndef __MMU__C__
#define __MMU__C__

#include "../header/mmu.h"

hole::hole()
{
	address_ t adr = 
	int sz = 
	struct hole *next =
	struct hole *prev =
}

int main() {
	mem_t *mem = initMem();
	
	address_t adr1 = myAlloc(mem, 5);
	address_t adr2 = myAlloc(mem, 10);
	
	address_t adr3 = myAlloc(mem, 100);
	myFree(mem, adr2, 10);
	myFree(mem, adr1, 5);
	
	myWrite(mem, adr3, 543); // write on the 1 st byte
	myWrite(mem, adr3+9, 34); // write on the 10th byte
	
	byte_t val1 = myRead(mem, adr3);
	byte_t val2 = myRead(mem, adr3+9);
}

#endif
