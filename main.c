#include <stdio.h>
#include <string.h>

#include "hashtable/hashtable.h"
#include "reader/reader.h"
#include "printer/printer.h"


void printMatchedItem(char *line, HashTable *table, HashItem **item, int start) {
	printSubstring(line, start, (*item)->col - 1);
	int row = (*item)->row;
	// printf("Linha: %d\t\n", row);
	int length = printMatchedWord((*item)->word) + (*item)->col;
	
	(*item) = findValue(table, (*item)->word, (*item));
	
	if ((*item) != NULL) {
		// printf("Linha2: %d\t\n", (*item)->row);
		if((*item)->row == row) {
			//printf("\n\naqui\n\n");
			printMatchedItem(line, table, item, length);
			return;
		}
	}
	printf("%s", line + length);
}


void searchValue(HashTable *table, char **rows, int row) {
	char word[50];
	printf("Procurar: ");
	fgets(word, 50, stdin);
	word[strlen(word) - 1] = '\0';
	printf("\n");

	HashItem *item = NULL;
	item = findValue(table, word, item);
	for(int i = 0; i < row; i++) {
		if(item != NULL) {
			if(item->row == i) {
				printMatchedLine(i + 1);
				printMatchedItem(rows[i], table, &item, 0);
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
	int row, col, sizeWord, colBeforeNewLine;
	row = col = sizeWord = 0;
	

	// Initialize the Reader variables
	openFile("texto.txt", &rows);
	
	// Initialize the HashTable variables
	HashTable table;
	createHashTable(&table);

	while((word = findNextWord(&row, &col, &sizeWord, &rows, &colBeforeNewLine)) != NULL) {
		if(colBeforeNewLine) {
			addItem(&table, word, row - 1, colBeforeNewLine - sizeWord - 2);
		} else {
			addItem(&table, word, row, col - sizeWord - 2);
		}
	}

	//printHash(&table);
	//searchValue(&table, rows, row);	
	searchValue(&table, rows, row);	
	
	closeFile(&rows, row);
	freeTable(&table);
	return 0;
}
