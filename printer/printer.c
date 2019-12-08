#include <string.h>
#include <stdio.h>

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

void printLine(char *line, int nRow) {
	printf("%2d  %s", nRow, line);
}

void printLineWithMarkedWord(char *line, char *word, int posWord, int nRow) {
	int finalPosWord = posWord + strlen(word);
	// printf("\033[31;1;4mHello\033[0m");
	printf(NUMBER_MATCHED_ROW("%2d  "), nRow);
	fwrite(line, 1, posWord, stdout);
	printf(YELLOW("%s"), word);
	fwrite(line + finalPosWord, 1, strlen(line) - finalPosWord, stdout);
}
