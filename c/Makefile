notes_sort: notes.o sorting.o
	gcc notes.o sorting.o -o notes_sort

notes.o: notes.c sorting.h
	gcc -c notes.c

sorting.o: sorting.c sorting.h
	gcc -c sorting.c

clean:
	rm *.o notes_sort