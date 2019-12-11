#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "printer.h"

#define YELLOW(string) "\033[33;4m" string "\033[0m"
#define NUMBER_MATCHED_ROW(string) "\x1b[31m" string "\x1b[0m"

void printMatchedLine(int nRow) {
	printf(NUMBER_MATCHED_ROW("%2d  "), nRow);
}

void printLine(char *line, int nRow) {
	printf("%2d  %s", nRow, line);
}

void printSubstring(char *string, int start, int end) {
	printf("%.*s", end - start +1, (string + start)); 
}

void printMany(char c, int count, char start, char end) {
	printf("%c", start);
	for(int i = 0; i < count; i++) {
		printf("%c", c);
	}
	printf("%c", end);
}

void clearScreen() {
	system("@cls||clear");
}

int printMatchedWord(char *word) {
	printf(YELLOW("%s"), word);
	return strlen(word);
}

void printLines(char **lines, int lineCount) {
	printf("\nImprimindo na tela o texto do arquivo, com a contagem de linhas\n\n");
	for(int i = 0; i < lineCount; i++) {
		printf("%2d  %s", i+1,  lines[i]);
	}
	printf("\n");
}

