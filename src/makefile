CC=g++
INC_DIR = ../include
DEPS=$(INC_DIR)/ppt.hpp
CFLAGS=-c -I$(INC_DIR)
PROG_PATH = ../bin/
PROGS = RPS_hVm RPS_batch_mar_vs_sec

all: $(PROGS)

RPS_hVm: RPS_human_vs_machine.o ppt.o $(PROGS)
	$(CC) RPS_human_vs_machine.o ppt.o -o RPS_hVm
	mv RPS_hVm $(PROG_PATH)


RPS_batch_mar_vs_sec: batch_markov_vs_secondguess.o ppt.o $(PROGS)
	$(CC) batch_markov_vs_secondguess.o ppt.o -o RPS_batch_mar_vs_sec
	mv RPS_batch_mar_vs_sec $(PROG_PATH)


batch_markov_vs_secondguess.o: batch_markov_vs_secondguess.cpp $(DEPS)
	$(CC) $(CFLAGS) batch_markov_vs_secondguess.cpp

RPS_human_vs_machine.o: RPS_human_vs_machine.cpp $(DEPS)
	$(CC) $(CFLAGS) RPS_human_vs_machine.cpp

ppt.o: ppt.cpp $(DEPS)
	$(CC) $(CFLAGS) ppt.cpp

install: $(PROGS)
	mv $(PROGS) $(PROG_PATH)

clean:
	rm *.o 
	rm $(PROG_PATH)RPS*