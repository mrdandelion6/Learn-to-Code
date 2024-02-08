OBJFILES = notes.o sorting.o

notes_sort: $(OBJFILES)
	gcc $(OBJFILES) -o notes_sort

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