#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "printer.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define BLUE(string) "\x1b[34m" string "\x1b[0m"
#define RED(string) "\x1b[44m" string "\x1b[0m"
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
	// printf("\e[1;1H\e[2J");
}

int printMatchedWord(char *word) {
	printf(YELLOW("%s"), word);
	return strlen(word);
}

void printLineWithMarkedWord(char *line, char *word, int posWord, int nRow) {
	int finalPosWord = posWord + strlen(word);
	// printf("\033[31;1;4mHello\033[0m");
	printf("    %s    ", word);
	printf(NUMBER_MATCHED_ROW("%2d  "), nRow);
	fwrite(line, 1, posWord, stdout);
	printf(YELLOW("%s"), word);
	fwrite(line + finalPosWord, 1, strlen(line) - finalPosWord, stdout);
}

void printLines(char **lines, int lineCount) {
	printf("\nImprimindo na tela o texto do arquivo, com a contagem de linhas\n\n");
	for(int i = 0; i < lineCount; i++) {
		printf("%2d  %s", i+1,  lines[i]);
	}
	printf("\n");
}

