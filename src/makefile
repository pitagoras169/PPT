CC=g++
INC_DIR = ../include
DEPS=$(INC_DIR)/ppt.hpp
CFLAGS=-c -I$(INC_DIR)

all: RPS_hVm RPS_batch_mar_vs_sec

RPS_hVm: RPS_human_vs_machine.o ppt.o
	$(CC) RPS_human_vs_machine.o ppt.o -o RPS_hVm

RPS_batch_mar_vs_sec: batch_markov_vs_secondguess.o ppt.o
	$(CC) batch_markov_vs_secondguess.o ppt.o -o RPS_batch_mar_vs_sec

batch_markov_vs_secondguess.o: batch_markov_vs_secondguess.cpp $(DEPS)
	$(CC) $(CFLAGS) batch_markov_vs_secondguess.cpp

RPS_human_vs_machine.o: RPS_human_vs_machine.cpp $(DEPS)
	$(CC) $(CFLAGS) RPS_human_vs_machine.cpp

ppt.o: ppt.cpp $(DEPS)
	$(CC) $(CFLAGS) ppt.cpp

clean:
	rm *.o RPS_hVm RPS_batch_mar_vs_sec