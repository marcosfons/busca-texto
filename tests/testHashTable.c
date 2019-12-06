

#include <stdio.h>

#include "../hashtable/hashtable.h"

void main() {
	// Simple program to test functions of the HashTable module
	printf("Inicio Teste HashTable\n");
	
	HashTable table;		
	createHashTable(&table);
	
	char *test = "teste";
	
	printf("%s ValueHash: %d\n", test, hashCode(&table, test));
	
	HashItem *value = NULL;
	
	findValue(&table, test, &value);
	
	printf("Existe na tabela: %d\n", value !=  NULL);
	
	
	addItem(&table, test, 0, 0);

	findValue(&table, test, &value);
	printf("Existe na tabela: %d Proximo: %d\n", value != NULL, value->nextItem != NULL);

	addItem(&table, test, 1, 1);
	findValue(&table, test, &value);
	printf("Existe na tabela: %d Proximo: %d\n", value != NULL, value->nextItem != NULL);

	addItem(&table, "Abacate", 5, 5);
	addItem(&table, "Aleatório", 8, 8);
	addItem(&table, "Aleatório", 12, 12);
	addItem(&table, "Aleatório", 20, 25);


	printHash(&table);

	printf("\n");
	
}


