buscatexto:
	gcc main.c hashtable/hashtable.c reader/reader.c printer/printer.c -o main.o

clean:
	rm -f *.o
