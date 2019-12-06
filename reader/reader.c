#include <stdio.h>
#include <stdlib.h>

#include "reader.h"

// In this way the file pointer is only accessible in the reader Module
// What makes sense, because the main just care about proccess data
static FILE *file = NULL;

void openFile(char *pathFile) {
	if(file == NULL) {
		file = fopen(pathFile, "r");
		
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

char *findNextWord(int *row, int *col, int *sizeWord) {
	char *word = (char*) malloc(100 * sizeof(char));
	*sizeWord = -1;
	char currChar;

	while((currChar = fgetc(file)) != EOF) {
		*col += 1;
		// Check if it's still a word
		if((currChar >= 65 && currChar <= 90) || (currChar >= 97 && currChar <= 122)) {
			
			*sizeWord += 1;
			word[*sizeWord] = currChar;
			
		} else {
			if(*sizeWord > -1) { // End of the word	
				break;
			}
		}

		// Count new line
		if(currChar == '\n') {
			*row += 1;
			*col = 0;
		}
	}

	// Add the end of the word
	word[*sizeWord + 1] = '\0';
	
	// Ensures the function returns NULL if the word is empty
	// Reallocate the word, free a little bit of memory
	word = (char*) realloc(word, (*sizeWord + 1) * sizeof(char));
		
	return word;
}




