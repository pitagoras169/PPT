RPS_hVm: RPS_human_vs_machine.o ppt.o
	g++ RPS_human_vs_machine.o ppt.o -o RPS_hVm

RPS_human_vs_machine.o: RPS_human_vs_machine.cpp
	g++ -c RPS_human_vs_machine.cpp

ppt.o: ppt.cpp
	g++ -c ppt.cpp
clean:
	rm *.o RPS