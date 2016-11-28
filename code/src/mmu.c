#ifndef __MMU__C__
#define __MMU__C__

#include "../header/mmu.h"

int main() {
	mem_t *mem = initMem();
	
	address_t adr1 = myAlloc(mem, 5);
	address_t adr2 = myAlloc(mem, 10);
	
	address_t adr3 = myAlloc(mem, 100);

	myFree(mem, adr2, 10);
	myFree(mem, adr1, 5);
	
	/*myWrite(mem, adr3, 543); // write on the 1 st byte
	myWrite(mem, adr3+9, 34); // write on the 10th byte
	
	byte_t val1 = myRead(mem, adr3);
	byte_t val2 = myRead(mem, adr3+9);*/
}

mem_t* initMem(){
	mem_t* mp = malloc(sizeof(mem_t));

	bool mem[SIZE] = {false};
	memcpy(mp->mem, mem, sizeof(mp->mem));

	//On init le premier hole_t
	mp->root = NULL;

	return mp;
}

address_t myAlloc(mem_t* mp, int sz){
	address_t adresseDebutAllocation = -1;

	if (mp->root == NULL){
		printf("\nOn initialise le premier noeud\n");
		//Aucun noeud n'est affecté donc on affecte dès le début de la liste
		hole_t* hole = malloc(sizeof(hole_t));
		hole->adr = 0;		
		printf("Adresse: %d affectée\n", hole->adr);
		hole->sz = sz;		
		printf("Taille : %d\n", hole->sz);
		hole->next = NULL;
		hole->prev = NULL;
		mp->root = hole;
		adresseDebutAllocation = 0;

	} else { //Pas la première affectation
		printf("\nOn initialise un des noeuds suivants\n");
		hole_t* hole = mp->root;
		//int firstAdr = hole->sz;
		//On recherche la première adresse libre
		while (hole->next != NULL) {
			hole = hole->next;
		}
		int firstAdr = hole->sz + hole->adr;

		//On affect les valeur et link l'élément
		hole_t* newHole = malloc(sizeof(hole_t));
		newHole->adr = firstAdr;
		printf("Adresse: %d affectée\n",firstAdr);
		newHole->sz = sz;
		printf("Taille : %d\n", newHole->sz);
		newHole->next = NULL;
		newHole->prev = hole;
		hole->next = newHole;

		adresseDebutAllocation = firstAdr;
	}
	printf("On renvoie l'adresse %d\n", adresseDebutAllocation);
	return adresseDebutAllocation;
}

void myFree(mem_t* mp, address_t p, int sz){
	printf("Lancement de myFree\n");
	hole_t* newHole = mp->root;
	while (newHole->adr != p || newHole->next != NULL){
		newHole = newHole->next;
	}
	printf("On sort de la boucle d'itération des noeud\n");

	if (newHole->adr == p && newHole->next == NULL){
		printf("ERROR INVALID POINT\n");
		return;
	}

	newHole->next->prev = newHole->prev;
	newHole->prev->next = newHole->next;

	int cptCleanup = newHole->adr;
	while(cptCleanup < (newHole->adr+newHole->sz)){
		mp->mem[cptCleanup] = false;
		cptCleanup++;
	}


	free(newHole);
}

#endif
