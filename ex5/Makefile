
CC = gcc
CFLAGS = -Wall -std=c11

OBJS = ex5.o Vector.o

ex5: $(OBJS)
	$(CC) $(CFLAGS) -o ex5 $(OBJS)

ex5.o: ex5.c Vector.h
Vector.o: Vector.c Vector.h

clean:
	rm -f *~ *.o ex5
