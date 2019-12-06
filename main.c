#include <stdio.h>

#include "hashtable/hashtable.h"
#include "reader/reader.h"

void main() {
	
	// Initialize the Reader variables
	openFile("texto.txt");
	char *word;
	int row, col, sizeWord;
	row = col = sizeWord = 0;

	// Initialize the HashTable variables
	HashTable table;
	createHashTable(&table);

	while((word = findNextWord(&row, &col, &sizeWord)) != NULL) {
		addItem(&table, word, row, col - sizeWord - 2);		
	}

	printHash(&table);
	closeFile();

}
