OBJFILES = notes.o sorting.o

notes_sort: $(OBJFILES)
	gcc $(OBJFILES) -o notes_sort

notes.o: notes.c sorting.h
	gcc -c notes.c

sorting.o: sorting.c sorting.h
	gcc -c sorting.c

# the following rule is never called
# even though we will go to the sorting.o and notes.o rules, the following rule is never called because the sorting.o and notes.o rules are more specific
%.o: %.c sorting.h 
	echo "BARS"
	gcc -c $< -o $@ 
# $< is the first prerequisite, $@ is the target

.PHONY: clean
clean:
	rm *.o notes_sort

# some common automatic variables to know about:
# $@ - the target, the name of the file that is being generated
# $< - the first prerequisite, the name of the file that caused the rule to be triggered
# $^ - all the prerequisites, separated by spaces

# some less common automatic variables to know about:
# $? - all the prerequisites that are newer than the target
# $* - the stem of the target, the part of the filename that matched the % in the rule
# $+ - all the prerequisites, separated by spaces, with duplicates included
# $| - all the order-only prerequisites, separated by spaces
