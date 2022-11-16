CC = g++ -std=c++11
CFLAGS = -Wall -Wextra -Wshadow -pedantic -gz
STEP1 = chang755/step1/
SOURCE1 = $(wildcard $(STEP1)*.cpp)
OBJS1 := 
HOBJS1 = $(wildcard $(STEP1)*.h)
STEP2 = chang755/step2/
SOURCE2 = $(wildcard $(STEP2)*.cpp)
OBJS2 = 
HOBJS2 =
TESTS = $(wildcard testcases/*)
TESTS2 = $(wildcard results/*.out)

VALGRIND = valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose

all: clean step1 step2 

.PHONY: test1
test1: clean step1
	mkdir -p results
	@echo "Testing step1"
	@for i in $(TESTS); do \
		echo "Testing $$i"; \
		./step1 $$i; \
		mv testcases/*.out results; \
		mv testcases/*.pout results; \
	done

step1: $(SOURCE1) $(HOBJS1)
	$(CC) $(CFLAGS) $(SOURCE1) -o step1

.PHONY: test2
test2: step2
	mkdir -p step2_results
	@echo "Testing step2"
	@for i in $(TESTS2); do \
		echo "Testing $$i"; \
		./step2 $$i; \
		mv testcases/*.vout step2_results; \
	done

step2: $(OBJS2) $(HOBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o step2

.PHONY: clean
clean: 
	rm -f $(OBJS1) $(OBJS2) step1 step2 
	rm -rf results
