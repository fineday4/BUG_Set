# 工程原样
vpath %.cc ./Function
vpath %.h  ./headers

PLC: main.o PLCSieMenS.o PLCMitSubShi.o PLCProtocol.o
	g++ main.o PLCSieMenS.o PLCMitSubShi.o PLCProtocol.o -o PLC -std=c++11 -lpthread -g

main.o: main.cc PLCSieMenS.cc PLCMitSubShi.cc
	g++ -c main.cc Function/PLCSieMenS.cc Function/PLCMitSubShi.cc -std=c++11 -lpthread -g

PLCSieMenS.o: PLCSieMenS.cc PLCSieMenS.h PLCManager.h
	g++ -c Function/PLCSieMenS.cc headers/PLCManager.h -std=c++11 -lpthread -g

PLCMitSubShi.o: PLCMitSubShi.cc PLCMitSubShi.h PLCManager.h
	g++ -c Function/PLCMitSubShi.cc headers/PLCManager.h -std=c++11 -lpthread -g

PLCProtocol.o: PLCProtocol.cc PLCProtocol.h PLCManager.h
	g++ -c Function/PLCProtocol.cc headers/PLCManager.h Function/PLCMitSubShi.cc Function/PLCSieMenS.cc -std=c++11 -lpthread -g

clean:
	-rm PLC main.o PLCSieMenS.o PLCMitSubShi.o PLCProtocol.o