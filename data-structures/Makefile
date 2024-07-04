OBJFILES = notes.o helpers.o

notes: $(OBJFILES)
	gcc -w $(OBJFILES) -o notes

notes.o: notes.c helpers.h
	gcc -w -c notes.c

helpers.o: helpers.c helpers.h
	gcc -w -c helpers.c

.PHONY: clean
clean:
	rm *.o notes