dosun : prog1.o lecture_fich.o
	gcc -g -Wall -o dosun prog1.o lecture_fich.o
	
lecture_fich.o : lecture_fich.c lecture_fich.h prog1.h
	gcc -g -Wall -c lecture_fich.c

prog1.o : prog1.h prog1.c lecture_fich.h prog1.c
	gcc -g -Wall -c prog1.c

clean:
	rm -f dosun *.o