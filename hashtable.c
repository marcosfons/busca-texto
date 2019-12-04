#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

void createHashTable(HashTable *table) {
	table->size = 157;
	table->items = (HashItem**)  malloc(table->size * sizeof(HashItem*));
	
	// Solve windows problems, each pointer is NULL in the beginning
	for(int i = 0; i < table->size; i++)
		table->items[i] = NULL;
}

void createHashTableWithText(HashTable *table, char **text) {
	createHashTable(table);
	
	// Store the currentPosition of the cursor
	int currPosition = 0;
	int row = 0;
	int col = 0;

	char *nextWord;
	do {
		nextWord = findNextWord(text, &currPosition, &row, &col);
	} while (nextWord != NULL); {
		addItem(table, nextWord, row, col);
	}
}

char *findNextWord(char **text, int *currPosition, int *row, int *col) {
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
	
	// Assumes it's just a word
	while(word[curr] != '\0') {
		count += (int) word[curr];
		curr += 1;
	}	
	return count % table->size;
}

void findValue(HashTable *table, char *word, HashItem **item) {
	int key = hashCode(table, word);
	
	*item = table->items[key];
}

void printHash(HashTable *table) {
	printf("\nTamanho total: %d, não printando os nulos\n", table->size);
	printf("Formato: (palavra, linha, coluna)\n");
	for(int i = 0; i < table->size; i++) {
		if(table->items[i] != NULL) {
			printf("Key: %d\n\t", i);
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




