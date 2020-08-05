RPS: main.o ppt.o
	g++ main.o ppt.o -o RPS

main.o: main.cpp
	g++ -c main.cpp

ppt.o: ppt.cpp
	g++ -c ppt.cpp
clean:
	rm *.o RPS