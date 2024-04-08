CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
TST= $(wildcard *.cc)

testcase : $(SRC) 
	make -C tests

%.o: %.cc
	$(CC) $(CCFLAGS)  -o $@ -c $<

clean :
	rm -f $(OBJ_TEST) tests/testcase
