/*
// Structure to store the row and the col of the word
typedef struct ItemValue {
	int row;
	int col;
} ItemValue;
*/

// Structure to store the key and the related value
// And store a nextItem, in case of repeated words added
typedef struct HashItem {
	int key;
	int row;
	int col;
	struct HashItem *nextItem;
} HashItem;

// Structure to store the all hashTable
typedef struct HashTable {
	int size;
	HashItem *items;
} HashTable;


// Just create a hashTable
void createHashTable(HashTable *table);

// Create a hashTable with the given text
void createHashTableWithText(HashTable *table, char **text);

// Add a item with the given word
void addItem(HashTable *table, char *word, int row, int col);

// Calculate hashCode with the given word
// Table parameter because the code hash of the given word depends on the table
int hashCode(HashTable *table, char *word);

// Find the next word in the text
// Return NULL if not find
char *findNextWord(char **text, int *currPosition, int *row, int *col);

// Try to find the given word in the table
// Return NULL if not find
void findValue(HashTable *table, char *word, HashItem **item);




















