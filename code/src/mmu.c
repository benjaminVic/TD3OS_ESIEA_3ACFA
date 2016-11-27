#ifndef __MMU__C__
#define __MMU__C__

#include "../header/mmu.h"

int main() {
	mem_t *mem = initMem();
	
	address_t adr1 = myAlloc(mem, 5);
	address_t adr2 = myAlloc(mem, 10);
	
	/*address_t adr3 = myAlloc(mem, 100);
	myFree(mem, adr2, 10);
	myFree(mem, adr1, 5);
	
	myWrite(mem, adr3, 543); // write on the 1 st byte
	myWrite(mem, adr3+9, 34); // write on the 10th byte
	
	byte_t val1 = myRead(mem, adr3);
	byte_t val2 = myRead(mem, adr3+9);*/
}

mem_t* initMem(){
	mem_t* mp = malloc(sizeof(mem_t));

	bool mem[SIZE] = {false};
	memcpy(mp->mem, mem, sizeof(mp->mem));

	/*
	printf("%lu\n",sizeof(mp->mem));
	mp->mem = mem;*/

	//On init le premier hole_t
	//TODO
	mp->root = NULL;

	return mp;
}

address_t myAlloc(mem_t* mp, int sz){
	address_t adresseDebutAllocation = -1;

	if (mp->root == NULL){

		//Aucun noeud n'est affecté donc on affecte dès le début de la liste
		hole_t* hole = malloc(sizeof(hole_t));
		hole->adr = 0;
		hole->sz = sz;
		hole->next = NULL;
		hole->prev = NULL;
		mp->root = hole;
		//TODO ADD LOOP AND WRITE WITHIN mp
		adresseDebutAllocation = 0;

	} else { //Pas la première affectation

		hole_t* hole = mp->root;
		int firstAdr = 0;
		//TODO On recherche la première adresse libre
		while (hole->next != NULL) {
			firstAdr = firstAdr + hole->sz;
			hole = hole->next;
		}

		//TODO ADD LOOP AND WRITE WITHIN mp
		hole_t* newHole = malloc(sizeof(hole_t));
		newHole->adr = firstAdr;
		newHole->sz = sz;
		newHole->next = NULL;
		newHole->prev = hole;
		hole->next = newHole;

	}

	return adresseDebutAllocation;
}

#endif
