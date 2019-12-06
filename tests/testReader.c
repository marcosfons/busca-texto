#include <stdio.h>

#include "../reader/reader.h"

void main() {
	openFile("texto.txt");	
	
	char *word;
	int sizeWord = 0;
	int row = 0;
	int col = 0;
	
	printf("Printando as palavras do arquivo e as suas posicoes\n");
	while((word = findNextWord(&row, &col, &sizeWord)) != NULL) {
		printf("Linha: %d Coluna: %d Palavra: %s \n", row, col - sizeWord - 2, word);
	}
	closeFile();

	openFile("texto.txt");

	printf("Reconstruindo o texto, apenas com as posições sem os caracteres que não são palavras\n");

	closeFile();

	printf("\n");
}
