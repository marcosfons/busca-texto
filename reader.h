// This module is responsible for the reading stuff


// Responsible to openFile and control the pointers, and the data of file
void openFile(char *pathFile);

// Responsible to closeFile and free memory
void closeFile();

// Responsible to find the next word in file and returns it
char *findNextWord(int *row, int *col, int *sizeWord);
