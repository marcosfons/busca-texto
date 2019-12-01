#include <stdlib.h>
#include <stdio.h>

#include "hashtable.h"

void createHashTable(HashTable *table) {
	table->size = 157;
	table->items = malloc(157 * sizeof(HashItem));
	HashItem item = {-1, -1, -1, NULL};
	for(int i = 0; i < table->size; i++) {
		table->items[i] = item;
	}
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

void addItem(HashTable *table, char *word, int row, int col) {
	int key = hashCode(table, word);

	HashItem item = {key, row, col, NULL};

	printf("Ainda ta certo\n");
	HashItem *lastPointer = table->items[key].nextItem;

	printf("Chegou aqui?\n");
	while (lastPointer != NULL) {
		printf("Entrou aqui\n");
		lastPointer = lastPointer->nextItem;
	}

	*(lastPointer) = item;
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
	
	*item = &(table->items[key]);
}





















