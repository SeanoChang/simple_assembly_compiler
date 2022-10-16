CC = g++ -std=c++11
CFLAGS = -Wall -Wextra -Werror -Wshadow -pedantic -gz
STEP1 = chang755/step1/
OBJS1 = $(STEP1)main.o $(STEP1)step1.o
HOBJS1 = $(STEP1)Parser.h
STEP2 = chang755/step2/
OBJS2 = 
HOBJS2 =

all: clean step1 step2 

.PHONY: step1
step1: $(OBJS1) $(HOBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o step1

.PHONY: step2
step2: $(OBJS2) $(HOBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o step2

.PHONY: clean
clean: 
	rm -f $(OBJS1) $(OBJS2) step1 step2