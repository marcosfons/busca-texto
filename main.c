#include <stdio.h>
#include <string.h>

#include "hashtable/hashtable.h"
#include "reader/reader.h"
#include "printer/printer.h"

void searchValue(HashTable *table, char **rows, int row) {
	char word[50];
	printf("Procurar: ");
	fgets(word, 50, stdin);
	

	HashItem *item = NULL; 
	
	word[strlen(word) - 1] = '\0';
	printf("\n");
	findValue(table, word, &item);
	for(int i = 0; i < row; i++) {
		if(item != NULL) {
			if(item->row == i) {
				printLineWithMarkedWord(rows[item->row], item->word, item->col, item->row + 1);
				findValue(table, word, &item);
			} else {
				printLine(rows[i], i + 1);
			}
		} else {
			printLine(rows[i], i + 1);
		}
	}
	printf("\n");

}

int main() {
	
	// Vector of rows, each row is a string
	char **rows;
	
	char *word;
	int row, col, sizeWord;
	row = col = sizeWord = 0;
	

	// Initialize the Reader variables
	openFile("texto.txt", &rows);
	
	// Initialize the HashTable variables
	HashTable table;
	createHashTable(&table);

	while((word = findNextWord(&row, &col, &sizeWord, &rows)) != NULL) {
		addItem(&table, word, row, col - sizeWord - 2);		
	}

	// printHash(&table);
	searchValue(&table, rows, row);	
	
	
	closeFile(&rows, row);
	freeTable(&table);
	return 0;
}
