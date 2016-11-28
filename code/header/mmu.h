#ifndef __MMU__H__
#define __MMU__H__
#define SIZE 65536

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int address_t;

typedef struct hole {
	address_t adr;
	int sz;
	struct hole* next;
	struct hole* prev;
} hole_t;

typedef struct mem {
	bool mem[SIZE];
	hole_t* root; // holes list
} mem_t;

// dynamically allocates a mem_t structure and initializes its content
mem_t* initMem();

// allocates space in bytes (bool) using First-Fit
address_t myAlloc(mem_t* mp, int sz);

// allocates space in bytes (bool) using Best-Fit

// allocates space in bytes (bool) using Worst-Fit


// release memory that has already been allocated previously
void myFree(mem_t* mp, address_t p, int sz);

// assign a value to a byte
void myWrite(mem_t* mp, address_t p, bool val);

// read memory from a byte
//byte_t myRead(mem_t* mp, address_t p);

#endif