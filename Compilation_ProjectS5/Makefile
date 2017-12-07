CC = gcc -Wall

all: clean CPYRR

CPYRR: y.tab.c lex.yy.o table_declarations.o table_lexicographique.o table_regions.o table_types.o declarations.o analyse_semantique.o 
	$(CC) -o bin/cpcmpl y.tab.c lex.yy.o obj/declarations.o obj/table_declarations.o obj/table_lexicographique.o obj/table_regions.o obj/table_types.o obj/analyse_semantique.o -ly -ll

analyse_semantique.o:
	$(CC) -c src/analyse_semantique.c -o obj/analyse_semantique.o
table_types.o:
	$(CC) -c src/table_types.c -o obj/table_types.o
table_regions.o:
	$(CC) -c src/table_regions.c -o obj/table_regions.o
table_declarations.o:
	$(CC) -c src/table_declarations.c -o obj/table_declarations.o
table_lexicographique.o:
	$(CC) -c src/table_lexicographique.c -o obj/table_lexicographique.o
declarations.o:
	$(CC) -c src/declarations.c -o obj/declarations.o
y.tab.c:
	yacc -v -d projet.y
lex.yy.o: lex.yy.c
	$(CC) -c lex.yy.c
lex.yy.c:
	lex projet.l
clean:
	rm -f *.o *~ y.output y.tab.h lex.yy.c y.tab.c obj/*

