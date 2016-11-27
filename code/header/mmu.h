#ifndef __MMU__H__
#define __MMU__H__
#define SIZE 65536

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef int address_t;

typedef struct hole {
	address_t adr;
	int sz;
	struct hole* next;
	struct hole* prev;
} hole_t;

typedef struct mem {
	bool mem[SIZE];
	hole_t root; // holes list
} mem_t;

// dynamically allocates a mem_t structure and initializes its content
mem_t* initMem();

// allocates space in bytes (bool) using First-Fit, Best-Fit or Worst-Fit
/*address_t myAlloc(mem_t* mp, int sz);

// release memory that has already been allocated previously
void myFree(mem_t* mp, address_t p, int sz);

// assign a value to a byte
void myWrite(mem_t* mp, address_t p, bool val);

// read memory from a byte
byte_t myRead(mem_t* mp, address_t p);*/

#endif