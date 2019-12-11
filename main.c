#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hashtable/hashtable.h"
#include "reader/reader.h"
#include "printer/printer.h"


int selectOption() {
	printf("\nSelecionar ([4] - Mostrar o menu): ");
	int op;
	scanf("%d", &op);
	return op;
}

void showMenu() {
	printMany('-', 44, '\n', ' ');
	printf("\nOpções");
	printMany('-', 44, '\n', '\n');
	printf("\t[1] - Procurar palavra\n\t[2] - Imprimir o texto inteiro\n\t[3] - Imprimir a tabela hash\n\t[4] - Limpar tela e mostrar o menu\n\t[0] - Sair");
	printMany('-', 44, '\n', '\n');
}

void printMatchedItem(char *line, HashTable *table, HashItem **item, int start) {
	printSubstring(line, start, (*item)->col - 1);
	int row = (*item)->row;
	int length = printMatchedWord((*item)->word) + (*item)->col;
	
	(*item) = findValue(table, (*item)->word, (*item));
	
	if ((*item) != NULL) {
		if((*item)->row == row) {
			printMatchedItem(line, table, item, length);
			return;
		}
	}
	printf("%s", line + length);
}


void searchValue(HashTable *table, char **rows, int row) {
	char word[50];
	printf("\nProcurar: ");
	while ((getchar()) != '\n'); 
	fgets(word, 50, stdin);
	word[strlen(word) - 1] = '\0';
	
	printf("As palavras sublinhadas em amarelo foram as encontradas\nE o numero em vermelho é o numero da linha\n\n");

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

void readFileAndCreateHashTable(char *nameFile, HashTable *table, char ***rows, int *row) {
	char *word;
	int col, sizeWord, colBeforeNewLine;
	col = sizeWord = 0;
	*row = 0;

	// Initialize the Reader variables
	openFile(nameFile, rows);

	while((word = findNextWord(row, &col, &sizeWord, rows, &colBeforeNewLine)) != NULL) {
		if(colBeforeNewLine) {
			addItem(table, word, *row - 1, colBeforeNewLine - sizeWord - 2);
		} else {
			addItem(table, word, *row, col - sizeWord - 2);
		}
	}

	// Free memory
	closeFile();
}

char *requestNameFile() {
	printMany('-', 57, '\n', '\n');
	printf("Por favor, digite um nome de arquivo válido, com extensão\n\nVocê pode evitar essa tela\nPasse o nome do arquivo por parâmetro\nExemplo: ./main.o texto.txt\n");
	printMany('-', 57, '\n', '\n');
	
	char *nameFile = malloc(50 * sizeof(char));
	printf(">>> ");
	fgets(nameFile, 50, stdin);
	nameFile[strlen(nameFile) - 1] = '\0';
	clearScreen();
	return nameFile;
}

int main(int argc, char *argv[]) {
	if(argv[1] == NULL) {
		argv[1] = requestNameFile();	
	}
	printf("Abrindo arquivo: %s", argv[1]);

	// Vector of rows, each row is a string
	char **rows;
	int countRows = 0;

	// Initialize the HashTable variables
	HashTable table;
	createHashTable(&table);

	readFileAndCreateHashTable(argv[1], &table, &rows, &countRows);
	

	int option = 0;
	showMenu();
	while( (option = selectOption()) != 0 ) {
		if(option == 1) {
			// Procurar palavra
			searchValue(&table, rows, countRows);	
		} else if(option == 2) {
			// Imprimir o texto inteiro
			printLines(rows, countRows);
		} else if(option == 3) {
			// Imprimir a tabela hash
			printHash(&table);	
		} else if(option == 4) {
			// Limpa a tela e mostra denovo o menu
			clearScreen();
			showMenu();
		} else {
			// Opcao invalida
			printf("Você tem que selecionar uma opção válida!\n");
		}
	}
	printf("\nSaindo\n");
	
	
	if(rows != NULL) {
		for(int i = 0; i < countRows; i++) {
			free((rows)[i]);
		}
		free(rows);
	}
	freeTable(&table);
	
	return 0;
}
