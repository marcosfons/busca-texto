#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

void createHashTable(HashTable *table) {
	table->size = 323;
	table->items = (HashItem**) malloc(table->size * sizeof(HashItem*));
	
	// Solve windows problems, each pointer is NULL in the beginning
	for(int i = 0; i < table->size; i++)
		table->items[i] = NULL;
}


HashItem *createHashItem(int key, char *word, int row, int col) {
	HashItem *pointer = malloc(sizeof(HashItem));
	pointer->word = malloc(sizeof(char) * strlen(word));
	strcpy(pointer->word, word);
	pointer->key = key;
	pointer->row = row;
	pointer->col = col;
	pointer->nextItem = NULL;
	return pointer;
}

void addItem(HashTable *table, char *word, int row, int col) {
	int key = hashCode(table, word);

	HashItem *lastPointer = table->items[key];
	
	// Add in the table
	if(lastPointer == NULL) {
		table->items[key] = (HashItem*) createHashItem(key, word, row, col);
		return;
	}
	
	// Inhere add in the linked list
	while (lastPointer->nextItem != NULL) {
		lastPointer = lastPointer->nextItem;
	}
	
	lastPointer->nextItem = createHashItem(key, word, row, col);
}

int hashCode(HashTable *table, char *word) {
	int count = 0;
	int curr = 0;
	int pot = 1;
	// Assumes it's just a word
	while(word[curr] != '\0') {
		count += (int) word[curr];
		curr += 1;
	}	
	return count % table->size;
}

HashItem *findValue(HashTable *table, char *word, HashItem *item) {
	if(item == NULL) {
		int key = hashCode(table, word);
		item = table->items[key];

		if(item == NULL) return NULL;	
		printList(item);
		printf("\n");
		if(strcmp(word, item->word) == 0) {
			return item;
		}
	}

	if(item->nextItem != NULL) {
	
		if(strcmp(word, item->nextItem->word) == 0) {
			item = item->nextItem;
		} else {
			item = findValue(table, word, item->nextItem);
		} 

	} else {
		item = NULL;
	}

	return item;
}

void printHash(HashTable *table) {
	printf("\nTamanho total: %d, não printando os nulos\n", table->size);
	printf("Formato: (palavra, linha, coluna)\n");
	for(int i = 0; i < table->size; i++) {
		if(table->items[i] != NULL) {
			printf("Key: %d  ", i);
			printList(table->items[i]);
			printf("\n");
		}
	}
}

void printList(HashItem *item) {
	printf("(%s, l: %d, c: %d)", item->word, item->row, item->col);
	if(item->nextItem != NULL) {
		printf(" -> ");
		printList(item->nextItem);
	}
}

void freeTable(HashTable *table) {
	for(int i = 0; i < table->size; i++) {
		if(table->items[i] != NULL) {
			freeList(table->items[i]);
		}
	}
	free(table->items);
}

void freeList(HashItem *item) {
	if(item->nextItem != NULL) {
		freeList(item->nextItem);
	}
	free(item);
}




