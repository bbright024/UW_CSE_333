# define the commands we will use for compilation and library building
AR = ar
ARFLAGS = rcs
CC = gcc
CXX = g++

# define useful flags to cc/ld/etc.
CFLAGS += -g -pg -Wall -I. -I.. -O0 -fprofile-arcs -ftest-coverage
LDFLAGS += -L. -lhw1 -fprofile-arcs -ftest-coverage -pg
CPPUNITFLAGS = #-L../gtest -lgtest

# define common dependencies
OBJS = LinkedList.o HashTable.o #Assert333.o
HEADERS = LinkedList.h HashTable.h #Assert333.h
#TESTOBJS = test_linkedlist.o test_hashtable.o test_suite.o
#TESTHEADERS = test_linkedlist.h test_hashtable.h

#define coverage output location
GOAL = example

# compile everything; this is the default rule that fires if a user
# just types "make" in the same directory as this Makefile
# removed test_suite from the beginning
all: example_program_ll example_program_ht FORCE
	./example_program_ll
	gprof example_program_ll > $(GOAL).stats
	./example_program_ht
	gcov LinkedList.c
	gcov HashTable.c
	@echo "Look at LinkedList.c.gcov and HashTable.c.gov for coverage data."
	lcov -c -d . -o $(GOAL).info
	genhtml $(GOAL).info -o $(GOAL)/


example_program_ll: example_program_ll.o libhw1.a $(HEADERS) FORCE
	$(CC) $(CFLAGS) -o example_program_ll example_program_ll.o $(LDFLAGS)

example_program_ht: example_program_ht.o libhw1.a $(HEADERS) FORCE
	$(CC) $(CFLAGS) -o example_program_ht example_program_ht.o $(LDFLAGS)

libhw1.a: $(OBJS) $(HEADERS) FORCE
	$(AR) $(ARFLAGS) libhw1.a $(OBJS)

#test_suite: $(TESTOBJS) $(TESTHEADERS) libhw1.a FORCE
#	$(CXX) $(CFLAGS) -o test_suite $(TESTOBJS) \
#	$(CPPUNITFLAGS) $(LDFLAGS) -lpthread $(LDFLAGS) -lgtest

%.o: %.cc $(HEADERS) FORCE
	$(CXX) $(CFLAGS) -c $<

%.o: %.c $(HEADERS) FORCE
	$(CC) $(CFLAGS) -c -std=c99 $<

clean: FORCE
	/bin/rm -f *.o *~ *.gcno *.gcda *.gcov test_suite libhw1.a \
    example_program_ll example_program_ht image_hist 

FORCE:
