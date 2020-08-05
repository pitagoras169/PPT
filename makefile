RPS_hVm: RPS_human_vs_machine.o ppt.o
	g++ RPS_human_vs_machine.o ppt.o -o RPS_hVm

RPS_batch_mar_vs_sec: batch_markov_vs_secondguess.o ppt.o
	g++ batch_markov_vs_secondguess.o ppt.o -o RPS_batch_mar_vs_sec

batch_markov_vs_secondguess.o: batch_markov_vs_secondguess.cpp
	g++ -c batch_markov_vs_secondguess.cpp

RPS_human_vs_machine.o: RPS_human_vs_machine.cpp
	g++ -c RPS_human_vs_machine.cpp

ppt.o: ppt.cpp
	g++ -c ppt.cpp
clean:
	rm *.o RPS_hVm RPS_batch_mar_vs_sec