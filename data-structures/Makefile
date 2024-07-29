OBJFILES = src/notes.o src/helpers.o

notes: $(OBJFILES)
	gcc -w $(OBJFILES) -o notes

src/notes.o: src/notes.c src/helpers.h
	gcc -w -c src/notes.c -o src/notes.o

src/helpers.o: src/helpers.c src/helpers.h
	gcc -w -c src/helpers.c -o src/helpers.o

.PHONY: clean
clean:
	rm src/*.o notes