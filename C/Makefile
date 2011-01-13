PROGRAMS = edyview

CC = gcc
RM = rm -f

DEBUG = -g -Wall
CFLAGS = -O2 $(DEBUG)
LIBS = -lpafe

all: $(PROGRAMS)

edyview: edyview.o
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(PROGRAMS) $(addsuffix .o, $(PROGRAMS))
