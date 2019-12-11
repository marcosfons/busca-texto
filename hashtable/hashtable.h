
// Structure to store the key and the related value
// And store a nextItem, in case of repeated words added
typedef struct HashItem {
	int key;
	char *word;
	int row;
	int col;
	struct HashItem *nextItem;
} HashItem;

// Structure to store the all hashTable
typedef struct HashTable {
	int size;
	HashItem **items;
} HashTable;


// Just create a hashTable
void createHashTable(HashTable *table);

// Create a single HashItem and return its pointer
HashItem *createHashItem(int key, char *word, int row, int col);

// Add a item with the given word
void addItem(HashTable *table, char *word, int row, int col);

// Calculate hashCode with the given word
// Table parameter because the code hash of the given word depends on the table
int hashCode(HashTable *table, char *word);

// Try to find the given word in the table
// Return NULL if not find
HashItem *findValue(HashTable *table, char *word, HashItem *item);

// Print the hash
void printHash(HashTable *table);

// Print the item and the next ones
void printList(HashItem *item);

// Free memory of the table
void freeTable(HashTable *table);

// Free memory of the item
void freeList(HashItem *item);
