#include <stdio.h>
#include <stdlib.h>

#include "reader.h"

// In this way the file pointer is only accessible in the reader Module
// What makes sense, because the main just care about proccess data
static FILE *file = NULL;

// Control the allocation of the line
static int sizeRow = 0;

static int nRow = 0;

void openFile(char *pathFile, char ***rows) {
	if(file == NULL) {
		file = fopen(pathFile, "r");
		
		*rows = (char**) malloc(1 * sizeof(char*));
		
		sizeRow = 500;
		
		(*rows)[0] = (char*) malloc(sizeRow * sizeof(char));

		if(file == NULL) {
			printf("Erro ao tentar abrir o arquivo\n");
		}
	}
}

void closeFile() {
	if(file != NULL) {	
		fclose(file);
		file = NULL;
	}
}

char *findNextWord(int *row, int *col, int *sizeWord, char ***rows, int *colBeforeNewLine) {
	char *word = (char*) malloc(100 * sizeof(char));
	*sizeWord = -1;
	char currChar;

	// This is to maintain the col even after newLine
	// Stores the col number of the word before the newLine
	*colBeforeNewLine = 0;

	while((currChar = fgetc(file)) != EOF) {
		
		(*rows)[*row][*col] = currChar;

		*col += 1;
		// Check if it's still a word
		if((currChar >= 65 && currChar <= 90) || (currChar >= 97 && currChar <= 122)) {
			
			*sizeWord += 1;
			word[*sizeWord] = currChar;
			
		} else {
			// Count new line
			if(currChar == '\n') {
				if(*sizeWord >= 0) {
					addNewLine(row, col, rows, colBeforeNewLine);
				} else {
					addNewLine(row, col, rows, NULL);
				}
			}

			if(*sizeWord > -1) { // End of the word	
				break;
			}
		}
	}

	// Add the end of the word
	word[*sizeWord + 1] = '\0';
	
	// Ensures the function returns NULL if the word is empty
	// Reallocate the word, free a little bit of memory
	word = (char*) realloc(word, (*sizeWord + 1) * sizeof(char));
		
	return word;
}


void addNewLine(int *row, int *col, char ***rows, int *colBeforeNewLine) {
	if(colBeforeNewLine != NULL) {
		*colBeforeNewLine = *col;
	}

	(*rows)[*row][*col] = '\0';
	(*rows)[*row] = (char*) realloc((*rows)[*row], (*col) * sizeof(char));

	*col = 0;
	
	*row += 1;
	*rows = (char**) realloc(*rows, (*row + 1) * sizeof(char*));
	sizeRow = 500;
	
	(*rows)[*row] = (char*) malloc(sizeRow * sizeof(char));
}



