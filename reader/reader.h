// This module is responsible for the reading stuff


// Responsible to openFile and control the pointers, and the data of file
void openFile(char *pathFile, char ***rows);

// Responsible to closeFile and free memory
void closeFile(char ***rows, int lines);

// Responsible to find the next word in file and returns it
char *findNextWord(int *row, int *col, int *sizeWord, char ***rows, int *isNewLine);

// "Create" the lines
// void createLines(char ***rows);

// Add new line
void addNewLine(int *row, int *col, char ***rows, int *isNewLine);
