# ------------
# This code is provided solely for the personal and private use of
# students taking the CSC367H5 course at the University of Toronto.
# Copying for purposes other than this use is expressly prohibited.
# All forms of distribution of this code, whether as given or with
# any changes, are expressly prohibited.
#
# Authors: Bogdan Simion, Alexey Khrabrov
#
# All of the files in this directory and all subdirectories are:
# Copyright (c) 2024 Bogdan Simion
# -------------

CC = gcc
CFLAGS += -std=gnu11 -Wall -Werror -g3 -O3 -DNDEBUG
LDFLAGS += -lm

all: lab1 lab1-opt

lab1: lab1.o
	$(CC) $^ -o $@ $(LDFLAGS)

lab1-opt: lab1-opt.o
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o lab1 lab1-opt
