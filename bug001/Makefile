# 工程原样
vpath %.cc ./Function
vpath %.h  ./headers

PLC: main.o PLCManager.o
	g++ main.o PLCManager.o -o PLC -std=c++11 -lpthread

main.o: main.cc Function/PLCManager.cc headers/PLCManager.h
	g++ -c main.cc Function/PLCManager.cc -std=c++11 -lpthread

PLCManager.o: PLCManager.cc headers/PLCManager.h
	g++ -c PLCManager.cc -std=c++11 -lpthread

clean:
	-rm PLC main.o PLCManager.o