notes_sort: notes.o sorting.o
	gcc notes.o sorting.o -o notes_sort

notes.o: notes.c sorting.h
	gcc -c notes.c

sorting.o: sorting.c sorting.h
	gcc -c sorting.c

# the following rule is never called
%.o: %.c sorting.h 
	echo "BARS"

.PHONY: clean
clean:
	rm *.o notes_sort