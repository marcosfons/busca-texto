
# Busca Texto

Um programa feito em C, que realiza buscas em textos por meio de tabelas Hash.

## Como utilizar
No diretório existe um arquivo makefile, que já provém os devidos comandos para compilar

Primeiro confira se o arquivo makefile tem permissâo de execução. Caso não tenha execute:
```
chmod +x makefile
```
Gere os executáveis, e execute:

1. **Projeto Principal**
	```
	make
	./main.o
	```

2. Teste do módulo da **Tabela Hash**
	```
	make testhashtable
	tests/testHashTable.o
	```

3. Teste do módulo do **Reader**
	```
	make testreader
	tests/testReader.o
	```

## Limpar os executáveis gerados
	make clean
