#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

void createHashTable(HashTable *table) {
	table->size = 157;
	table->items = (HashItem**)  malloc(table->size * sizeof(HashItem*));
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

HashItem *addHashItem(int key, char *word, int row, int col, HashItem *next) {
	HashItem *pointer = malloc(sizeof(HashItem));
	pointer->word = malloc(sizeof(char) * strlen(word));
	strcpy(pointer->word, word);
	pointer->key = key;
	pointer->row = row;
	pointer->col = col;
	pointer->nextItem = next;
	return pointer;
}

void setHashItem(HashItem *pointer, int key, char *word, int row, int col) {
	pointer->word = malloc(sizeof(char) * strlen(word));
	strcpy(pointer->word, word);
	pointer->key = key;
	pointer->row = row;
	pointer->col = col;
	pointer->nextItem = NULL;
}

void addItem(HashTable *table, char *word, int row, int col) {
	int key = hashCode(table, word);

	printf("Ainda ta certo\n");
	HashItem *lastPointer = table->items[key];
		
	printf("Chegou aqui?\n");
	while (lastPointer != NULL) {
		printf("Entrou aqui\n");
		lastPointer = lastPointer->nextItem;
	}
	
	if(lastPointer == NULL) printf("E null\n");
	lastPointer = (HashItem*)  malloc(sizeof(HashItem));
	
	setHashItem(lastPointer, key, word, row, col);

	if(table->items[key] == NULL) table->items[key] = lastPointer;
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





















