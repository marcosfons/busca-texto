

#include <stdio.h>

#include "hashtable.h"

void main() {
	// Simple program to test functions of the HashTable module
	printf("Inicio Teste HashTable\n");
	
	HashTable table;		
	createHashTable(&table);
	
	hashCode(&table, "teste");
	printf("First ValueHash: %d", hashCode(&table, "teste"));
	
	char *testeString = "teste";
	
	HashItem *value = NULL;
	
	findValue(&table, "teste", &value);
	
	printf("af");
	printf("Existe na tabela: %d\n", value !=  NULL);
	
	
	addItem(&table, testeString, 0, 0);
		
	findValue(&table, "teste", &value);
	printf("Existe na tabela: %d\n", value != NULL);

	printf("\n");
	
}


