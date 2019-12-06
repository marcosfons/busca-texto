

buscatexto:
	gcc main.c hashtable/hashtable.c reader/reader.c -o main.o

testreader:
	gcc tests/testReader.c reader/reader.c -o tests/testReader.o

testhashtable:
	gcc tests/testHashTable.c hashtable/hashtable.c -o tests/testHashTable.o

clean:
	rm *.o tests/*.o
